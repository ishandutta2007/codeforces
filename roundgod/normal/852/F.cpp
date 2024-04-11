#include<bits/stdc++.h>
#define MAXN 1000500
using namespace std;
typedef long long ll;
ll n,m,a,q;
ll num[MAXN],ans[MAXN],fact[MAXN];
ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
void extgcd(ll a,ll b,ll &x,ll &y)
{
    if(b!=0)
    {
        extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
}
ll mod_inverse(ll a,ll m)
{
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
ll mod_fact(ll n,ll p,ll &e)
{
    e=0;
    if(n==0) return 1;
    ll res=mod_fact(n/p,p,e);
    e+=n/p;
    if(n/p%2!=0) return res*(p-fact[n%p])%p;
    return res*fact[n%p]%p;
}
ll mod_comb(ll n,ll k,ll p)
{
    if(n<0||k<0||n<k) return 0;
    ll e1,e2,e3;
    ll a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);
    if(e1>e2+e3) return 0;
    return a1*mod_inverse(a2*a3%p,p)%p;
}
ll phi(long long n)
{
    long long rea=n;
    for(int i=2; i*i<=n; i++)
        if(n%i==0)
        {
            rea=rea-rea/i;
            do
                n/=i;
            while(n%i==0);
        }
    if(n>1)rea=rea-rea/n;
    return rea;
}
ll exp_mod(ll a,ll b,ll c)
{
    a%=c;
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%c;
        b>>=1,a=a*a%c;
    }
    return ans;
}
int main()
{
    scanf("%I64d %I64d %I64d %I64d",&n,&m,&a,&q);
    ll p=phi(q),l=(ll)sqrt(p*1.0),pr=1e9;
    for(ll i=1; i<=l; i++)
        if(p%i==0)
        {
            if(exp_mod(a,i,q)==1) pr=min(pr,i);
            if(exp_mod(a,p/i,q)==1)pr=min(pr,p/i);
        }
    memset(fact,0,sizeof(fact));
    fact[0]=1;
    for(int i=1;i<pr;i++)
        fact[i]=(fact[i-1]*i)%pr;
    for(int i=0;i<=m;i++)
        num[i]=mod_comb(m,i,pr);
    for(int i=1;i<=m;i++)
        num[i]=(num[i]+num[i-1])%pr;
    for(int i=0;i<=m;i++)
       ans[i]=exp_mod(a,num[i],q);
    for(int i=m+1;i<n;i++)
        ans[i]=ans[i-1];
    for(int i=n-1;i>=0;i--)
        printf("%I64d ",ans[i]);
    return 0;
}