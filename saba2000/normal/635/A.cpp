#include<iostream>
using namespace std;
int x[20][20],r,c,n,k;
main()
{cin>>r>>c>>n>>k;
for (int i=0; i<n; i++)
{int a,b;
cin>>a>>b;
x[a][b]=1;
}int ans=0,s;
for (int i=1; i<=r; i++)
for (int j=1; j<=c; j++)
for (int p=i; p<=r; p++)
for (int q=j; q<=c; q++)
{s=0;
for (int l=i; l<=p; l++)
for (int k=j; k<=q; k++)
s+=x[l][k];

if (s>=k) ans++;}


cout<<ans<<endl;
}