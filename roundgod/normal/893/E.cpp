#include<bits/stdc++.h>
#define MAXN 1000500
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
ll prime[MAXN];
bool is_prime[MAXN];
ll pow2[MAXN];
ll x,y,q;
ll fact[MAXN],inv[MAXN];
ll pow_mod(ll a,ll i)
{
    if(i==0) return 1;
     ll s=1;
    while(i>0)
     {
         if(i&1) s=(s*a)%MOD;
         a=(a*a)%MOD;
         i>>=1;
     }
     return s;
}
ll mod_comb(ll n,ll k)
{
    return (((fact[n]*inv[n-k])%MOD)*inv[k])%MOD;
}
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(ll j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
int main()
{
    ll num=sieve(MAXN-1);
    scanf("%I64d",&q);
    pow2[0]=1;
    for(ll i=1;i<MAXN;i++)
        pow2[i]=(pow2[i-1]*2)%MOD;
    fact[0]=1;
    for(ll i=1;i<MAXN;i++)
        fact[i]=(i*fact[i-1])%MOD;
    inv[MAXN-1]=pow_mod(fact[MAXN-1],MOD-2);
    for(int i=MAXN-2;i>=0;i--)
        inv[i]=(inv[i+1]*(i+1))%MOD;
    while(q--)
    {
        scanf("%I64d%I64d",&x,&y);
        ll res=1;
        for(ll i=0;i<num;i++)
        {
            ll cnt=0;
            if(x==1) break;
            else if(is_prime[x]==true)
            {
                res=res*y%MOD;
                break;
            }
            while(x%prime[i]==0) {cnt++; x/=prime[i];}
            if(cnt) res=(res*mod_comb(y-1+cnt,cnt))%MOD;
        }
        res=(res*pow2[y-1])%MOD;
        printf("%I64d\n",res);
    }
    return 0;
}