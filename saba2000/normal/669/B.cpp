#include<iostream>
using namespace std;
int n;
char c[100009];
int a[100009],f[100009];
main()
{
cin>>n;
for (int i=0; i<n; i++)
cin>>c[i];
for (int i=0; i<n; i++)
cin>>a[i];
int u=0;

f[0]=1;
while (u>=0 && u<n)
{
if (c[u]=='>') u+=a[u]; else u-=a[u];
if (u<0 || u>=n) break;
if (f[u]==1) {cout<<"INFINITE"<<endl; return 0;}
f[u]=1;
	
}
cout<<"FINITE"<<endl;
}