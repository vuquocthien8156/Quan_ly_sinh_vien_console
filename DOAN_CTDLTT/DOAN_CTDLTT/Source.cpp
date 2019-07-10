#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//Khai bao ham
struct NTN
{
	short ngay , thang; 
	int nam;
};

struct DTK
{
	int MSHV;
	short MaKH;
	float DiemTK;
	NTN NgaydkKH;
};

struct HV
{
	int MSHV;
	char Hoten[50];
	NTN NTNS;
	char GT[5];
	char mail[30];
	int SDT;
	char LV_Truong[50];
	short sobuoinghi;
	DTK Dahoc;
	DTK Danghoc;
};
 
struct KhHoc
{
	short MaKH;
	char TenKH[30];
	int Sobuoihoc;
	NTN NgayKG;
	char TenGV[40];
	char Tomtat[100];
};

struct Node
{
	HV info;
	Node *next;
};

struct list
{
	Node* head;
	Node* tail;
};

void menu();

void Printlist(list l); //case 1
void xuatHV(HV x);

void Hienthitheotieuchi(list l); //case 2
void Tieuchinam(list l);
void Tieuchinu(list l);
void tieuchitruong(list l);

Node *getnode(HV x); //case 3
void insertTail (list &l , HV x);
int HamkiemtraMSHV(list l , int x);
void Nhapdulieu(HV &x, list &l ,list &k, list &h);
void NhapKHDH(list &l , list &k , HV &x);
void NhapKHDgH(list &l , list &h , HV &x);

void suathongtinhocvien(list &l); // Case 4
void suasdt(list &l);
void suaLVTruong(list &l);
void suanamsinh(list &l);
void suaMail(list &l);
void suaGT(list &l);
void suaHoTen(list &l);

void DeleteHead(list &l); //Case5
void DeleteHead(list &l);
void DeleteP(list &l, Node *p);
void DeleteSV(list &l);

void TimkiemtheoMSHV(list l); // case 6
void SVthamgiaKH(list k); //Case 7
void XemKQHT(list l , list k ,list h); //case 8
void diemdanh(list l); //case 9
void HVbiThoiHoc(list l); //case 10
void DemHVtruong(list l); //case 11

void tinhtuoiLN(list l, list k); //case 12
void tinhtuoiNN(list l, list k);

void HTtheoMSSV(list l); //case 13

void NhapMaKHXuatHV(list l,list k, list h); //case 14
void NhapKHXuatThuKhoa(list l, list k, list h); //case 15
void ThongKeXepLoaiHV(list l,list k, list h); //case 16

//Ham chinh
void main()
{

	HV x;
	x.sobuoinghi = 0;
	list l; l.head=l.tail=NULL;
	list h; h.head=h.tail=NULL;
	list k; k.head=k.tail=NULL;
	
	int ichon;
	do
	{
		menu();
		cout <<"Nhap chuc nhang ban muon (1 -> 17): "; cin >> ichon;
		system("CLS");
		switch(ichon)
		{
			case 1:
				{	
					Printlist(l);
				} break;

			case 2:
				{
					Hienthitheotieuchi(l);
				}break;

			case 3:
				{
					cout <<"Nhap thong tin cua hoc vien. \n";
					Nhapdulieu( x, l, k, h);
					system("cls");
				}break;

			case 4:
				{
					suathongtinhocvien(l);
					system("cls");
				}break;

			case 5:
				{	
					DeleteSV(l);
				}break;

			case 6:
				{
					TimkiemtheoMSHV(l);
				}break;

			case 7:
				{
					SVthamgiaKH(k);
				}break;

			case 8:
				{	
					XemKQHT(l , k , h);
				}break;

			case 9:
				{	
					diemdanh(l);
				}break;
			case 10:
				{
					HVbiThoiHoc(l);
				}break;
			case 11:
				{	
					DemHVtruong(l);
				}break;
			case 12:
				{
					tinhtuoiLN(l,k);
					tinhtuoiNN(l,k);
				}break;
			case 13:
				{
					 HTtheoMSSV(k);
				}break;
			case 14:
				{
					NhapMaKHXuatHV (l , k ,h);
				}break;
			case 15:
				{
					NhapKHXuatThuKhoa(l , k , h);
				}break;
			case 16:
				{
					ThongKeXepLoaiHV(l , k , h);
				}break;
			case 17: break;
				
		default : cout << "Khong co chuc nang ban chon.\n";
		}

	}while(ichon != 17);
	system("pause");
}

//Dinh nghia ham
void menu()
{
	cout<<"\t\t\tCHUONG TRINH QUAN LY HOC VIEN\n";
	cout<<"!-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-!\n";
	cout<<"1. Danh sach hoc vien.\n";
	cout<<"2. Hien thi danh sach hoc vien theo tieu chi.\n";
	cout<<"3. Them mot hoc vien moi(MSHV khong duoc trung voi hoc vien co trong DS.\n";
	cout<<"4. Chinh sua thong tin cua hoc vien.\n";
	cout<<"5. Xoa bo hoc vien.\n";
	cout<<"6. Tim kiem hoc vien theo MSHV.\n";
	cout<<"7. Nhap MSHV , cho biet hoc vien tham gia nhung khoa hoc nao.\n";
	cout<<"8. Xem ket qua hoc tap cua mot hoc vien.\n";
	cout<<"9. Dien danh.\n";
	cout<<"10. Cho biet hoc vien nao bi thoi hoc. \n";
	cout<<"11. Nhap vao truong , cho biet co bao nhiu HV hoc truong do.\n";
	cout<<"12. Cho biet hoc vien nao nho va lon tuoi nhat.\n";
	cout<<"13. Sap xep DS theo tieu chi.\n";
	cout<<"14. Nhap vao ma khoa hoc , in ra DSHV cua khoa hoc.\n";
	cout<<"15. Cho biet thu khoa cua mot khoa hoc.\n";
	cout<<"16. Nhap ma KH , thong ke xep loai.\n";
	cout<<"17. ";
	cout<<"18. ";
	cout<<"19. ";
	cout<<"17. Thoat truong trinh.\n";
	cout<<"!-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-!\n";
}

Node *getnode(HV x)
{
	Node *q = new Node;
	if(q == NULL)
		cout << "Khong du bo nho";
	else
	{
		q -> info = x;
		q -> next = NULL;
	}
	return q;
}

void insertTail (list &l , HV x)
{
	Node*T = getnode(x);
	if(l.head == NULL)
		l.head = l.tail = T;
	else
	{
		l.tail -> next = T;
		l.tail = T;
	}
}
void xuatHV(HV x)
{	
	cout << setw(5)<< x.MSHV; 
	cout << setw(15) <<x.Hoten; 
	cout << setw(5) <<x.NTNS.ngay <<"/"<< x.NTNS.thang <<"/"<< x.NTNS.nam; 
	cout << setw(8) << x.GT ; 
	cout << setw(20) << x.mail ; 
	cout << setw(15) <<x.SDT ; 
	cout << setw(20) << x.LV_Truong << endl ;
}

void Printlist(list l)
{
	cout<< setw(5) <<"MSHV"; 
	cout << setw(15)<<"Hoten"; 
	cout << setw(12)<<"NTNS" ; 
	cout << setw(8)<<"GT";	
	cout << setw(20)<<"mail" ; 
	cout << setw(15)<<"SDT"; 
	cout << setw(20) <<"NLV/Truong" << endl;	
		for(Node* q = l.head; q != NULL ; q = q-> next)
		{
			xuatHV(q -> info);
			for(int i= 1 ; i <= 80 ; i++ )
				cout << char(196) ;
			cout << endl;
		}
}

int HamkiemtraMSHV(list l , int x)
{
	Node* p = l.head;
	while(p != NULL)
	{
		if( x == p->info.MSHV){
			cout<<"Hoc vien nay da co trong DS xin nhap lai: \n";
			return 0;}
		p = p->next;
	}
	return 1;
}

void NhapKHDH(list &l , list &k , HV &x)
{	bool c ;
	do
	{	x.Dahoc.MSHV = x.MSHV;
		do{cout <<"Khoa da hoc: "; cin >> x.Dahoc.MaKH;}while(x.Dahoc.MaKH < 10 || x.Dahoc.MaKH > 99);

	do{cout <<"Diem Tk: "; cin >> x.Dahoc.DiemTK;}while(x.Dahoc.DiemTK < 0 || x.Dahoc.DiemTK > 10);
				
	cout <<"Ngay dang ki KH: "<<endl; 
	cout <<"+ Nhap ngay: ";
	do{cin >> x.Dahoc.NgaydkKH.ngay;} while(x.Dahoc.NgaydkKH.ngay < 1 || x.Dahoc.NgaydkKH.ngay >31);
	cout <<"+ Nhap thang: "; 
	do{cin >> x.Dahoc.NgaydkKH.thang;} while(x.Dahoc.NgaydkKH.thang < 1 || x.Dahoc.NgaydkKH.thang >12);
	cout <<"+ Nhap nam: " ; 
	do{cin>> x.Dahoc.NgaydkKH.nam;}while(x.Dahoc.NgaydkKH.nam < 1900);
	insertTail(k , x);	
	cout << "\nTiep 1 , dung 0: "; cin >> c; }while(c !=0 );

}

void NhapKHDgH(list &l , list &h , HV &x)
{
	bool d;
	do
	{	x.Dahoc.MSHV = x.MSHV;
		do{cout <<"Khoa dag hoc: "; cin >> x.Danghoc.MaKH;}while((x.Danghoc.MaKH < 10 || x.Danghoc.MaKH > 99));

		cout <<"Ngay dang ki KH: "<<endl;
		cout <<"+ Nhap ngay: ";
		do{cin >> x.Danghoc.NgaydkKH.ngay;} while(x.Danghoc.NgaydkKH.ngay < 1 || x.Danghoc.NgaydkKH.ngay >31);
		cout <<"+ Nhap thang: ";
		do{cin >> x.Danghoc.NgaydkKH.thang;}while(x.Danghoc.NgaydkKH.thang < 1 || x.Danghoc.NgaydkKH.thang >12);
		cout <<"+ Nhap nam: " ;
		do{cin>> x.Danghoc.NgaydkKH.nam;}while(x.Danghoc.NgaydkKH.nam < 1900);
				
		insertTail(h , x);
		cout << "\nTiep 1 , dung 0: "; cin >> d; }while(d != 0);
}

void Nhapdulieu(HV &x, list &l , list &k,  list &h)
{
	bool a, b;
	do
	{
		do{
			cout <<"MSHV: "; cin >> x.MSHV;
		}while((x.MSHV <= 99 || x.MSHV > 999) || HamkiemtraMSHV(l , x.MSHV) == 0);

		cout <<"Hoten: "; cin >> x.Hoten;
		cout <<"NTNS: "<<endl;
		cout <<"+ Nhap ngay: ";
		do{cin >> x.NTNS.ngay;} while(x.NTNS.ngay < 1 || x.NTNS.ngay >31);  cout <<"+ Nhap thang: ";   
		do{cin >> x.NTNS.thang;} while(x.NTNS.thang < 1 || x.NTNS.thang >12);  cout <<"+ Nhap nam: ";  
		do{cin>> x.NTNS.nam;}while(x.NTNS.nam < 1900);

		cout <<"GT: "; cin >> x.GT;
		cout <<"mail: "; cin >> x.mail;
		cout <<"SDT: "; cin >> x.SDT;
		cout <<"Noi lam viec or truong: "; cin >> x.LV_Truong;
		
		insertTail(l , x);
		NhapKHDH(l , k , x);
		NhapKHDgH(l , k , x);
		cout << "Tiep tuc nhap HV nhap 1 , dung nhap 0: "; cin >> b; 
	} while(b != 0);
}
//Phan cua Lam Thanh
void DeleteHead(list &l)
{
	Node *p;
	if (l.head != NULL)  //kiem tra dau co khac rong khong
	{
		p = l.head;
		l.head = l.head->next; // gan dau cho phan tu ke tiep
		delete p;		// xoa p
		if (l.head == NULL)	
			l.tail = NULL;
	}
}

void DeleteTail(list &l)
{
	Node *p = l.head;	// gan p = dau
	while (p->next != l.tail)
		p = p->next;
	Node *k = l.tail;	// gan k = duoi
	l.tail = p;
	l.tail->next = NULL;
	delete k;
}

void DeleteP(list &l, Node *p) // ham xoa phan tu sau p
{
	Node *k = l.head;
	while (k->next != p)
		k = k->next;
	k->next = p->next;
	delete p;
}
void DeleteSV(list &l)
{
	int x;
	Node *p;
	cout << "Nhap vao MSHV muon xoa : "; 
	cin >> x;		//nguoi dung nhap vao MSHV muon xoa
	for (p = l.head; p != NULL; p = p->next)
	{
		if (p->info.MSHV == x) 
		{
			if (p == l.head) //neu mshv = dau thi xoa dau
				DeleteHead(l);
			else
				if (p == l.tail)
					DeleteTail(l);	//neu mshv = duoi thi xoa cuoi
				else
					DeleteP(l, p);	//xoa phan tu sau p
			break;
		}
	}
	if (p == NULL)
		cout << " Khong co hoc vien nay " << endl;
	else
		cout << "Da xoa hoc vien thanh cong" << endl;
}

void suathongtinhocvien(list &l)
{
	int c;
	cout << "1.Sua ho ten "<<endl;
	cout << "2.Sua nam sinh "<<endl;
	cout << "3.Sua gioi tinh "<<endl;
	cout << "4.Sua Email "<<endl;
	cout << "5.Sua SDT "<<endl;
	cout << "6.Sua noi lam viec,truong "<<endl;
	cout <<	"7. Thoat. \n";
	do
	{
	cout << "Nhap vao chuc nang muon su dung : ";
	cin >> c;
		system("cls");
		switch(c)
		{
		case 1:
			{
				suaHoTen(l);
				break;
			}
		case 2:
			{
				suanamsinh(l);
				break;
			}
		case 3:
			{
				suaGT(l);
				break;
			}
		case 4:
			{
				suaMail(l);
				break;
			}
		case 5:
			{
				suasdt(l);
				break;
			}
		case 6:
			{
				cout << "Sua noi lam viec or Truong" <<endl;
				suaLVTruong(l);
				break;
			}
		case 7: break;
		default :
			cout << "Khong co thong tin nay"<<endl;
		}
	}while(c != 7);
}

void suasdt(list &l)
{
		int a, c;
		Node* f = l.head;
		cout <<"Nhap ma so hoc vien muon thay doi : ";  
		cin >> a;
		for(f = l.head ; f != NULL ; f = f->next)
		{
			if((f-> info.MSHV) == a) 
			{
				cout <<"Nhap SDT muon cap nhap: "; 
				cin >> c;		//cap nhat thong tin moi 
				(f->info.SDT = c);	// gan gia tri moi nhap vao 
				break;
			}
		}
}
void suanamsinh(list &l)
{
	int a,b,c,d;
		Node* t = l.head;
		cout <<"Nhap ma so hoc vien muon thay doi : ";  
		cin >> a;
		
		for(t = l.head ; t != NULL ; t = t->next)
		{
			if((t-> info.MSHV) == a)
			{
				cout <<"Nhap ngay thang nam sinh muon cap nhap"<<endl;
				cout << "Nhap Nam  : ";
				cin >> b;		//cap nhat thong tin moi 
				(t->info.NTNS.nam = b);	// gan gia tri moi nhap vao 
				cout << "Nhap thang : ";
				cin >> c;		//cap nhat thong tin moi 
				(t->info.NTNS.thang = c);	// gan gia tri moi nhap vao 
				cout << "Nhap ngay : ";
				cin >> d;		//cap nhat thong tin moi 
				(t->info.NTNS.ngay = d);	// gan gia tri moi nhap vao 
				break;
			}
		}
}
void suaGT(list &l)
{
	int a;
	char b[5];
		Node* t = l.head;
		cout <<"Nhap ma so hoc vien muon thay doi : ";  	
		cin >> a;
		for(t = l.head ; t != NULL ; t = t->next)
		{
			if((t-> info.MSHV) == a)	// kiem tra dieu kien mshv co = mshv nguoi dung nhap vao hay khong
			{
				cout <<"Nhap gioi tinh muon cap nhap: ";
				fflush(stdin);
				gets_s(b);	//cap nhat thong tin moi 
				strcpy(t->info.GT , b);		// gan gia tri moi nhap vao 
				break;	
			}
		}
}

void suaHoTen(list &l)
{
	int a;
	char b[50];
		Node* t = l.head;
		cout <<"Nhap ma so hoc vien muon thay doi : ";  
		cin >> a;
		for(t = l.head ; t != NULL ; t = t->next)
		{
			if((t-> info.MSHV) == a)
			{
				cout <<"Nhap ho ten muon cap nhap: ";
				fflush(stdin);
				gets_s(b);	//cap nhat thong tin moi 
				strcpy(t->info.Hoten , b);	// gan gia tri moi nhap vao 
				break;
			}
		}
}

void suaMail(list &l)
{
	int a;
	char b[50];
		Node* t = l.head;
		cout <<"Nhap ma so hoc vien muon thay doi : ";  
		cin >> a;
		
		for(t = l.head ; t != NULL ; t = t->next)
		{
			if((t-> info.MSHV) == a)	 // kiem tra dieu kien mshv co = mshv nguoi dung nhap vao hay khong
			{
				cout <<"Nhap Email muon cap nhap: ";
				fflush(stdin);
				gets_s(b);	//cap nhat thong tin moi do nguoi dung nhap vao
				strcpy(t->info.mail , b);		// gan gia tri moi nhap vao 
				break;
			}
		}
}
void suaLVTruong(list &l)
{
	int a;
	char b[50];
		Node* t;
		cout <<"Nhap ma so hoc vien muon thay doi : ";  
		cin >> a;
		
		for(t = l.head ; t != NULL ; t = t->next)
		{
			if((t-> info.MSHV) == a)
			{
				cout <<"Nhap noi lam viec hoac truong muon cap nhap: ";
				fflush(stdin);
				gets_s(b);	//cap nhat thong tin moi do nguoi dung nhap vao
				strcpy(t->info.LV_Truong , b);			// gan gia tri moi nhap vao 
				break;
			}
		}
}

void SVthamgiaKH(list k) //Mot hoc vien da tham gia nhung khoa hoc nao
{
	int x;
	cout<<"Nhap MSHV can tim: "; cin >> x; 
	Node *q = k.head;
	cout <<"Nhung khoa hoc HV da tham gia: ";
	while(q != NULL)
	{
		if(q->info.Dahoc.MSHV == x)
		{
			cout<< q->info.Dahoc.MaKH << " , ";
		}
		q = q-> next;
	}
}

// end Lam thanh

//begin Nguyen Thanh
void Hienthitheotieuchi(list l)
{
	cout <<"1. Gioi tinh.\n";
	cout <<"2. Truong hoac hoi lam viec.\n";
	cout <<"3. Thoat.\n";
	int ichon;
	do
	{
	cout <<"Chon tieu chi: "; cin >> ichon;
	switch(ichon)
	{
	case 1:
		{
			int i; 
			cout<<"\t1. Nam , 2. Nu : "; cin >> i;
			switch(i)
			{
			case 1: { Tieuchinam(l); }break;
			case 2: { Tieuchinu(l); }break;
			}

		}break;
	case 2:
		{
			tieuchitruong(l);
		}break;
	case 3: break;
		system("cls");
	default : cout <<"Khong co chuc nang nay.\n";
	}
	}while(ichon != 3);
}

void Tieuchinam(list l)
{
	cout<<"+ Danh sach HV Nam:"<<endl;
	Node *q = l.head;
	cout<< setw(5) <<"MSHV";
	cout << setw(15)<<"Hoten";
	cout << setw(12)<<"NTNS" ;
	cout << setw(8)<<"GT";
	cout << setw(20)<<"mail" ;
	cout << setw(15)<<"SDT";
	cout << setw(20) <<"NLV/Truong" << endl;
	while(q!=NULL)
	{
		strlwr(q ->info.GT);
		if (strcmp((q->info.GT),"nam") == 0) { xuatHV(q -> info);}
		q = q->next;
	}
}
void Tieuchinu(list l)
{
	cout<<"+ Danh sach HV Nu: "<<endl;
	Node *u = l.head;
	cout<< setw(5) <<"MSHV";
	cout << setw(15)<<"Hoten";
	cout << setw(12)<<"NTNS" ;
	cout << setw(8)<<"GT";
	cout << setw(20)<<"mail" ;
	cout << setw(15)<<"SDT";
	cout << setw(20) <<"NLV/Truong" << endl;
	while(u!=NULL)
	{
		strlwr(u ->info.GT);
		if (strcmp((u->info.GT),"nu") == 0)  
			xuatHV(u->info);  
		u=u->next;
	}
}

void tieuchitruong(list l)
{
	char c[5];
	cout <<"Nhap truong hay noi lam viec: "; gets(c);
	Node* p =l.head;
	while(p != NULL)
	{
		strlwr(p ->info.LV_Truong);
		strlwr(c);
		if(strcmp((p->info.LV_Truong), c) == 0) { xuatHV(p->info); }
	}

}
void HTtheoMSSV(list l)
{
	cout<<"Hien thi theo tieu chi tang dan cua MSHV: "<<endl;
	Node *i, *j;
	for (i = l.head; i != l.tail; i = i->next)
		for (j = i->next; j != NULL; j = j->next)
			if (i->info.MSHV > j->info.MSHV)
				swap(i->info, j->info);
}

void diemdanh(list l)
{
	Node * p = l.head;
	int i;
	do {cout <<"Nhap MSHV : "; cin >> i;}while(i <= 99 || i > 999);
	while(p != NULL)
	{
		if(p->info.MSHV == i)
		{
			cout <<"Cap nhap so ngay nghi: ";
			cin >>p->info.sobuoinghi;
		}
		p=p->next;
	}
}

void HVbiThoiHoc(list l)
{   bool x=0;
	cout<<" Danh sach cac hoc vien bi thoi hoc : "<<endl;
	Node *q;
	cout<< setw(5) <<"MSHV";
	cout << setw(15)<<"Hoten";
	cout << setw(12)<<"NTNS" ;
	cout << setw(8)<<"GT";
	cout << setw(20)<<"mail" ;
	cout << setw(15)<<"SDT";
	cout << setw(20) <<"NLV/Truong" <<endl;
	q=l.head;
	while(q!=NULL)
	{
		if(q->info.sobuoinghi > 3)
		{xuatHV(q->info);
		   x = 1; }
	q=q->next;}
	if(x == 1) return;
	else cout <<"Khong co HV nao bi thoi hoc.\n";
}


//End Nguyen Thanh

//Begin Trung
void NhapMaKHXuatHV(list l,list k, list h)
{
	int a;
	
	cout<<"Moi nhap ma khoa hoc: ";
	cin>>a;
	cout<< setw(5) <<"MSHV"; 
	cout << setw(15)<<"Hoten"; 
	cout << setw(12)<<"NTNS" ; 
	cout << setw(8)<<"GT";	
	cout << setw(20)<<"mail" ; 
	cout << setw(15)<<"SDT"; 
	cout << setw(20) <<"NLV/Truong" <<endl;
		for(Node *q = k.head; q!=NULL; q=q->next)//Duyet danh sach da hoc
			{if(q->info.Dahoc.MaKH == a)
				xuatHV(q->info);
			}
		for(Node *j = h.head; j!=NULL; j=j->next)//Duyet danh sach dang hoc
				{if(j->info.Danghoc.MaKH == a)
				xuatHV(j->info);}


}



void NhapKHXuatThuKhoa(list l, list k, list h)
{
	int a;
	cout<<"Moi nhap ma khoa hoc: ";
	cin>>a;
	cout<< setw(5) <<"MSHV"; 
	cout << setw(15)<<"Hoten"; 
	cout << setw(12)<<"NTNS" ; 
	cout << setw(8)<<"GT";	
	cout << setw(20)<<"mail" ; 
	cout << setw(15)<<"SDT"; 
	cout << setw(20) <<"NLV/Truong"<<endl ;
	HV hv;

	int max = 0; //Khoi tao 1 bien max
	for(Node *p=k.head;p!=NULL;p=p->next)//Duyet danh sach da hoc
	{ 
		if(p->info.Dahoc.MaKH == a )
		{
			if(p->info.Dahoc.DiemTK > max ){
				max = p->info.Dahoc.DiemTK;//Gan gia tri lon nhat
				hv = p->info;
			}
			
		}  
	}
 
	for(Node *p=h.head;p!=NULL;p=p->next)//Duyet danh sach dang hoc
	{ 
		if(p->info.Danghoc.MaKH == a )
		{
			if(p->info.Danghoc.DiemTK > max ){
				max = p->info.Danghoc.DiemTK;//Gan gia tri lon nhat
				hv = p->info;
			}
			
		}  
	}
	xuatHV(hv); //In hoc vien thoa dieu kien

}

void ThongKeXepLoaiHV(list l,list k, list h)
{
	int a;
	int XS=0,Gioi=0,Kha=0,TB=0,KCCC=0,XS1=0,Gioi1=0,Kha1=0,TB1=0,KCCC1=0;//Khoi tao cac bien dem
	
	cout<<"Moi nhap ma khoa hoc: ";
	cin>>a;
		for(Node *q = k.head; q!=NULL; q=q->next)//Duyet danh sach da hoc
			if(q->info.Dahoc.MaKH == a)
			{
				if(q->info.Dahoc.DiemTK >= 9 && q->info.Dahoc.DiemTK <=10)
					XS++;
				if(q->info.Dahoc.DiemTK >= 8 && q->info.Dahoc.DiemTK < 9)
					Gioi++;
				if(q->info.Dahoc.DiemTK >= 7 && q->info.Dahoc.DiemTK <8)
					Kha++;
				if(q->info.Dahoc.DiemTK >= 5.0 && q->info.Dahoc.DiemTK < 7)
					TB++;
				if(q->info.Dahoc.DiemTK < 5 )
					KCCC++;
			}
		for(Node *j = h.head; j!=NULL; j=j->next)//Duyet danh sach dang hoc
			if(j->info.Danghoc.MaKH == a)
			{
				if(j->info.Danghoc.DiemTK >= 9 && j->info.Danghoc.DiemTK <= 10)
					XS1++;
				if(j->info.Danghoc.DiemTK >= 8 && j->info.Danghoc.DiemTK < 9)
					Gioi1++;
				if(j->info.Danghoc.DiemTK >= 7 && j->info.Danghoc.DiemTK <8)
					Kha1++;
				if(j->info.Danghoc.DiemTK >= 5 && j->info.Danghoc.DiemTK < 7)
					TB1++;
				if(j->info.Danghoc.DiemTK < 5 )
					KCCC1++;
			}
			//Thong ke xep loai 
				cout<<"So HV xuat sac la: "<<XS+XS1<<endl;
				cout<<"So HV gioi la: "<<Gioi+Gioi1<<endl;
				cout<<"So HV kha la: "<<Kha+Kha1<<endl;
				cout<<"So HV trung binh la: "<<TB+TB1<<endl;
				cout<<"So HV khong duoc cap chung chi la: "<<KCCC+KCCC1<<endl;


}

// End Trung

void DemHVtruong(list l)
{
	Node * p = l.head;
	char a[50]; int idem=0;
	cout <<"Nhap ten truong: "; cin >> a;
	while(p != NULL)
	{
		strlwr(a);
		strlwr(p->info.LV_Truong);
		if(strcmp(p->info.LV_Truong , a)== 0) idem ++;
			p = p ->next;
	}
	cout <<"So hoc vien cua truong la : " << idem;
}

void XemKQHT(list l , list k ,list h)
{
	Node * p = k.head , *q = l.head;
	int x ; bool i =0 ;
	cout <<"Nhap ma hoc vien: "; cin >> x;
		while(q != NULL)
		{
			if(q->info.MSHV == x);
			{ cout << q->info.Hoten << endl; i = 1; }
			q=q ->next;
		}
	if(i == 1)
	{
		while(p != NULL)
		{
			if(p->info.Dahoc.MSHV == x)
			{ cout <<"Khoa hoc : "<< p->info.Dahoc.MaKH <<endl; cout << " Diem TK : " << p->info.Dahoc.DiemTK<<endl;}
				 p = p->next;
		}
   }
	else cout <<"Khong co ma hoc vien nay.\n";

}

void TimkiemtheoMSHV(list l)
{
	bool a=0; int i;
	cout <<"Nhap MSHV muon tim: "; cin >> i;
	Node *p = l.head;
	cout<< setw(5) <<"MSHV"; 
	cout << setw(15)<<"Hoten"; 
	cout << setw(12)<<"NTNS" ; 
	cout << setw(8)<<"GT";	
	cout << setw(20)<<"mail" ; 
	cout << setw(15)<<"SDT"; 
	cout << setw(20) <<"NLV/Truong" << endl;	
	while(p != NULL)
	{
		if(p->info.MSHV == i)
		{
			xuatHV(p->info); a=1;
		}
		p = p->next;
	}
	if(a == 1)
		return;
	else cout <<"\nKhong tim thay hoc vien.";
}


void tinhtuoiLN(list l , list k)
{
	Node* MAX = l.head;
	cout <<"Hoc vien có tuoi lon nhat: ";
	cout<< setw(5) <<"MSHV"; 
	cout << setw(15)<<"Hoten"; 
	cout << setw(12)<<"NTNS" ; 
	cout << setw(8)<<"GT";	
	cout << setw(20)<<"mail" ; 
	cout << setw(15)<<"SDT"; 
	cout << setw(20) <<"NLV/Truong" <<endl;
		for(Node* q = MAX->next ; q != NULL ; q = q ->next)
			if(MAX->info.NTNS.nam < q->info.NTNS.nam)
				MAX = q;
		xuatHV(MAX ->info);
		cout <<endl;
}
void tinhtuoiNN(list l , list k)
{
	Node* Min = l.head;
	cout <<"Hoc vien co tuoi be nhat: \n";
	cout<< setw(5) <<"MSHV"; 
	cout << setw(15)<<"Hoten"; 
	cout << setw(12)<<"NTNS" ; 
	cout << setw(8)<<"GT";	
	cout << setw(20)<<"mail" ; 
	cout << setw(15)<<"SDT"; 
	cout << setw(20) <<"NLV/Truong" <<endl;
		for(Node* q = Min->next ; q != NULL ; q = q ->next)
			if(Min->info.NTNS.nam > q->info.NTNS.nam)
				Min = q;
		xuatHV(Min ->info);
}