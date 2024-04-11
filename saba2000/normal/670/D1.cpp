#include<iostream>
using namespace std;
main()
{long long n,k,a[100000],b[100000];
cin>>n>>k;
for (int i=0; i<n; i++)
cin>>a[i];
for (int i=0; i<n; i++)
cin>>b[i];
long long x,y,z;
x=0; y=1000000009;
while (x<y)
{z=(x+y+1)/2;
long long p=k;
for (int i=0; i<n; i++)
{p-=max((long long)0,a[i]*z-b[i]);
}
if (p<0) y=z-1; else x=z;
}
cout<<x<<endl;
}