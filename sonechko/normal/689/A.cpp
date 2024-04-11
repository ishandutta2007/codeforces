#include<bits/stdc++.h>
using namespace std;
int a[20],n,x[20],y[20],xx[20],yy[20];
int main()
{
    cin>>n;
    string s;
    cin>>s;
    xx[1]=xx[2]=xx[3]=1;
    xx[4]=xx[5]=xx[6]=2;
    xx[7]=xx[8]=xx[9]=3;
          xx[0]=4;
    yy[1]=yy[4]=yy[7]=1;
    yy[2]=yy[5]=yy[8]=yy[0]=2;
    yy[3]=yy[6]=yy[9]=3;
    for (int i=1; i<=n; i++)
    {
        int k=(s[i-1]-'0');
        a[i]=k;
    }
    for (int i=1; i<n; i++)
    {
        x[i]=xx[a[i+1]]-xx[a[i]];
        y[i]=yy[a[i+1]]-yy[a[i]];
    }
    int kol=0;
    for (int ii=0; ii<=9; ii++)
    {
        int l=xx[ii],r=yy[ii];
        for (int i=1; i<n; i++)
        {
            l+=x[i];
            r+=y[i];
            if (l<1||l>4||r<1||r>3) break;
            if (l==4&&(r==1||r==3)) break;
            if (i==n-1) kol++;
        }
    }
    if (kol<2&&n!=1) cout<<"YES"<<endl; else cout<<"NO"<<endl;
}