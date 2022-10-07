#include<bits/stdc++.h>
using namespace std;
long long m,n,q;
long long X;
long long f(long long a)
{long long b=X-2,c=X,k,ans=1;
while(b>0)
{long long p=1,k=a;
while(p*2<=b){p*=2;
k=k*k%c; }
ans=ans*k%c;
b-=p;}
return ans;
}
long long a[1005009],A;
long long p[1000509];
main()
{cin>>n>>m>>A>>q;
p[0]=1;
for (long long i=1; ; i++)
   {p[i]=p[i-1]*A%q;
    if(p[i]==1) {X=i;break;}}

a[0]=1;long long x=m,t=1;
for (long long i=1; i<=n-1; i++)
{
    a[i]=(a[i-1]*x*f(i))%X;
    x--;
}
long long s=0;
for (long long i=0; i<=n-1; i++)
{
    s+=a[i];
    a[i]=s;
}
for (long long i=n-1; i>=0; i--)
    cout<<p[a[i]%X]<<" ";
}