#include <iostream>
#include <algorithm>
using namespace std; 
long long int C(int n,int m)
{long long int x=1,y=1,z=1,t=1;
for (int i=n; i>=n-9; i--)
if (i>0) x*=i; 
for (int i=n-10; i>=n-19; i--)
if (i>0) y*=i;
for (int i=n-20; i>=n-29; i--)
if (i>0) z*=i;
for (int i=2; i<=m; i++)
if (x%i==0) x/=i; else if (y%i==0) y/=i; else if (z%i==0) z/=i; else t*=i;
for (int i=2; i<=n-m; i++)
if (x%i==0) x/=i; else if (y%i==0) y/=i; else if (z%i==0) z/=i; else t*=i;
return x*y*z/t;
}
int main ()
{long long int n,m,t,an=0,k=1;
cin>>n>>m>>t;
for (int i=4; i<=min(n,t-1); i++)
{if (m>=t-i) an+=C(n,i)*C(m,t-i);}
cout<<an<<endl;
return 0;
}