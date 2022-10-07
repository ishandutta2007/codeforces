#include <iostream>
using namespace std;
int main ()
{int a[100009]={0},b[100009]={0},p[100009],s=0,d=0;
int n;
cin>>n;
for (int i=0; i<n; i++)
{cin>>p[i]; a[p[i]]++; b[p[i]]++; if (p[i]>n) s=1;}
for (int i=1; i<=n; i++)
if (a[i]<a[i+1])  d=1;
if (d+s>0) {cout<<-1<<endl; return 0;}
cout<<a[1]<<endl;
for (int i=0; i<n; i++)
{cout<<b[p[i]]-a[p[i]]+1<<" "; a[p[i]]--;}
return 0;
}