#include<iostream>
using namespace std;
long long n,k,a[123456],b[123456],g;
main()
{
cin>>n>>k;
for (int i=0; i<n; i++)
{cin>>a[i];
g=max(g,a[i]);
}
for (int i=0; i<n; i++)
cin>>b[i];
long long x,y,z;
x=0; y=4000000009/g;
while (x<y)
{z=(x+y+1)/2;
long long p=k;

for (int i=0; i<n; i++)
{
p-=max((long long)0,a[i]*z-b[i]);
}
if (p<0) y=z-1; else x=z;
}
cout<<x<<endl;
}