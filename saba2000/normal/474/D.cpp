#include<iostream>
#include<cmath>
using namespace std;
int t,k,a[1000000],b[1000000];
const int p=1000000007;
main()
{cin>>t>>k;
a[0]=1;
for (int i=1; i<=100000; i++)
{a[i]=a[i-1]%p;
if (i-k>=0) a[i]+=a[i-k]%p;
a[i]%=p;}
for (int i=1; i<=100000; i++)
b[i]=(b[i-1]%p+a[i]%p)%p;
for (int i=0; i<t; i++)
{int x,y;
cin>>x>>y;
cout<<((b[y]-b[x-1]+p)%p+p)%p<<endl;
}
}