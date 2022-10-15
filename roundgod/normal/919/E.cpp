#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
typedef long long ll;
ll a,b,p,x;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll extgcd(ll a,ll b,ll &x,ll &y)
{
    ll d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
ll mod_inverse(ll a,ll m)
{
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
ll num[MAXN];
int main()
{
    scanf("%I64d%I64d%I64d%I64d",&a,&b,&p,&x);
    ll s=1,ans=0;
    memset(num,0,sizeof(num));
    for(ll i=0;i<=p-2;i++)
    {
        num[i]=b*mod_inverse(s,p)%p;
        //printf("%I64d ",num[i]);
        s=s*a%p;
    }
    //printf("\n");
    for(ll i=0;i<=p-2;i++)
    {
        ans+=x/(p*(p-1));
        ll minmod=(p*p-num[i]*p-p+num[i]+p*i)%(p*(p-1));
        //printf("%I64d ",minmod);
        if(x%(p*(p-1))>=minmod) ans++;
    }
    //printf("\n");
    printf("%I64d\n",ans);
    return 0;
}