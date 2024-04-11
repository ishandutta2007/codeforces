#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
const ll inv2=(MOD+1)/2;
ll a[MAXN],d,b[MAXN],c[MAXN],ans;
ll f[MAXN],nf[MAXN],inv[MAXN];
int n,r,s;
ll pow_(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1) res=res*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return res;
}
ll C(ll x,ll y)
{
    return f[x]*nf[y]%MOD*nf[x-y]%MOD;
}
ll calc(ll n,ll b,ll sum)
{
    if(sum<0) return 0;
    if(n==0) return (sum==0);
    if(b==0) return 0;
    ll res=0;
    for(int i=0;i<=min(n,sum/b);i++)
    {
        if(i&1) (res-=C(n,i)*C(sum-i*b+n-1,n-1)%MOD)%=MOD;
        else (res+=C(n,i)*C(sum-i*b+n-1,n-1))%=MOD;
    }
    return (res+MOD)%MOD;
}

int main()
{
    inv[1]=1; for(int i=2;i<MAXN;i++) inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
    f[0]=nf[0]=1; for(int i=1;i<MAXN;i++) f[i]=f[i-1]*i%MOD,nf[i]=nf[i-1]*inv[i]%MOD;
    scanf("%d%d%d",&n,&s,&r);
    if(s==0)
    {
        printf("%lld\n",inv[n]);
        return 0;
    }
    for(int i=r;i<=s;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ll ret=calc(n-j,i,s-j*i)*C(n-1,j-1)%MOD;
            (ans+=ret*inv[j])%=MOD;
        }
    }
    ans=ans*pow_(calc(n,s+1,s-r),MOD-2)%MOD;
    printf("%lld\n",ans);
    return 0;
}