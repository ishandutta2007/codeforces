#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long c[500009];
int p;
main()
{long long n,k,s=0,t=0;
cin>>n>>k;
for (long long i=0; i<n; i++)
{scanf("%d",&p);
c[i]=p;
t=max(t,c[i]);
s+=c[i];
}long long s2=0;
for (long long j=0; j<n; j++)
s2+=abs(c[j]-s/n);
if (s2/2<=k && s%n==0) {cout<<0<<endl; return 0;}
else if(s2/2<=k && s%n!=0) {cout<<1<<endl;  return 0;}
sort(c,c+n);
//system("pause");
long long d=k,x;
for (long long i=0; i<n; i++)
{if ((c[i+1]-c[i])*(i+1)<=d) d-=(c[i+1]-c[i])*(i+1); else
{x=c[i]+d/(i+1); break;}
//system("pause");
}
//system("pause");
d=k; long long m;
for (long long i=n-1; i>=0; i--)
if ((c[i]-c[i-1])*(n-i)<=d) d-=(c[i]-c[i-1])*(n-i); else
{m=c[i]-d/(n-i); break;}
//system("pause");
cout<<m-x<<endl;
//system("pause");
return 0;
}