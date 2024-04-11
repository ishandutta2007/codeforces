#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long int ll;

ll gcd(ll x,ll y)
{
    if (x%y==0) return y; else return gcd(y,x%y);
}

ll min(ll x,ll y)
{
    if (x<y) return x; else return y;
}

ll t,a,b,c,d,e,tmp,ans,t2;

int main()
{
    scanf("%I64d%I64d%I64d",&t,&a,&b);
    c=gcd(a,b);
    t2=t;
    tmp=a/c;
    d=t/tmp/b;
    t-=d*tmp*b;
    a=min(a,b);
    ans=a*d+min(t+1,a)-1;
    a=gcd(ans,t2);
    ans/=a;t2/=a;
    printf("%I64d/%I64d\n",ans,t2);
    return 0;
}