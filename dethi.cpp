#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

struct doanhnghiep
{
    char madn[15];
    char giamdoc[30];
    float vondieule;
    int sonhanvien;
};

void nhapDN(doanhnghiep &dn)
{
    cout << "nhap ma doanh nghiep: " << endl;
    fflush(stdin);
    gets(dn.madn);
    cout << "nhap giam doc: " << endl;
    fflush(stdin);
    gets(dn.giamdoc);
    cout << "nhap von dieu le: " << endl;
    cin >> dn.vondieule;
    cout << "nhap so nhan vien: " << endl;
    cin >> dn.sonhanvien;
}

void xuatDN(doanhnghiep dn)
{
    cout << "\nMa doanh nghiep: " << dn.madn << endl;
    cout << "Giam doc: " << dn.giamdoc << endl;
    cout << "Von: " << dn.vondieule << endl;
    cout << "So nhan vien: " << dn.sonhanvien << endl;
}

void nhapDS(doanhnghiep ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        nhapDN(ds[i]);
    }
}

void sapxep(doanhnghiep ds[], int n)
{
    doanhnghiep tg;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[i].vondieule > ds[j].vondieule)
            {
                tg = ds[i];
                ds[i] = ds[j];
                ds[j] = tg;
            }
        }
    }
}

void indn(doanhnghiep dn)
{
    cout << "Madn: " << dn.madn << endl;
    cout << "So nv: " << dn.sonhanvien << endl;
}

void indsdn(doanhnghiep ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (ds[i].sonhanvien > 300 && ds[i].madn[0] == 'D' && ds[i].madn[1] == 'N')
        {
            indn(ds[i]);
        }
    }
}
void xuatDS(doanhnghiep ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        xuatDN(ds[i]);
    }
}

int kiemtradaucach(char madn[])
{
    for (int i = 0; i < strlen(madn); i++)
    {
        if (madn[i]==' ')
        {
            return 1;
        }     
    } 
    return 0; 
}

void checkhl(doanhnghiep ds[],int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds[i].vondieule<10 || kiemtradaucach(ds[i].madn) == 1 )
    {
        dem++;
    }
    }

    cout<<"So doanh nghiep khong hop le la: "<<dem<<endl;
    
    
}

int main()
{
    doanhnghiep dsDN[100];
    int n;
    cout << "Nhap so doanh nghiep: " << endl;
    cin >> n;
    nhapDS(dsDN, n);
    cout << "\n\nDanh sach chuan la: " << endl;
    sapxep(dsDN, n);
    xuatDS(dsDN, n);
    cout << "Danh sach nv > 300: " << endl;
    indsdn(dsDN, n);
    checkhl(dsDN,n);
   
}
