/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-12 12:25:34
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll pow_mod(ll a,ll i)
{
    ll s=1;
    while(i)
    {
        if(i&1) s=s*a%MOD;
        a=a*a%MOD;
        i>>=1;
    }
    return s;
}
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
namespace polysum
{
    const ll D=100005;
    ll a[D],f[D],g[D],p[D],p1[D],p2[D],b[D],h[D][2],C[D];
    ll calcn(ll d,ll *a,ll n)
    {
        if(n<=d) return a[n];
        p1[0]=p2[0]=1;
        for(ll i=0;i<=d;i++)
        {
            ll t=(n-i+MOD)%MOD;
            p1[i+1]=p1[i]*t%MOD;
        }
        for(ll i=0;i<=d;i++)
        {
            ll t=(n-d+i+MOD)%MOD;
            p2[i+1]=p2[i]*t%MOD;
        }
        ll ans=0;
        for(ll i=0;i<=d;i++)
        {
            ll t=g[i]*g[d-i]%MOD*p1[i]%MOD*p2[d-i]%MOD*a[i]%MOD;
            if((d-i)&1) ans=(ans-t+MOD)%MOD;
            else ans=(ans+t)%MOD;
        }
        return ans;
    }
    void init(ll M)
    {
        f[0]=f[1]=g[0]=g[1]=1;
        for(ll i=2;i<=M+4;i++) f[i]=f[i-1]*i%MOD;
        g[M+4]=pow_mod(f[M+4],MOD-2);
        for(ll i=M+3;i>=1;i--) g[i]=g[i+1]*(i+1)%MOD;
    }
    ll polysum(ll n,ll *a,ll m) //a[0]..a[m] \sum_{i=0}^{n-1} a[i]
    {
        a[m+1]=calcn(m,a,m+1);
        for(ll i=1;i<=m+1;i++) a[i]=(a[i-1]+a[i])%MOD;
        return calcn(m+1,a,n-1);
    }
    ll qpolysum(ll R,ll n,ll *a,ll m)
    {
        if(R==1) return polysum(n,a,m);
        a[m+1]=calcn(m,a,m+1);
        ll r=pow_mod(R,MOD-2),p3=0,p4=0,c,ans;
        h[0][0]=0;h[0][1]=1;
        for(ll i=1;i<=m+1;i++)
        {
            h[i][0]=(h[i-1][0]+a[i-1])*r%MOD;
            h[i][1]=h[i-1][1]*r%MOD;
        }
        for(ll i=0;i<=m+1;i++)
        {
            ll t=g[i]*g[m+1-i]%MOD;
            if(i&1) p3=((p3-h[i][0]*t)%MOD+MOD)%MOD,p4=((p4-h[i][1]*t)%MOD+MOD)%MOD;
            else p3=(p3+h[i][0]*t)%MOD,p4=(p4+h[i][1]*t)%MOD;
        }
        c=pow_mod(p4,MOD-2)*(MOD-p3)%MOD;
        for(ll i=0;i<=m+1;i++) h[i][0]=(h[i][0]+h[i][1]*c)%MOD;
        for(ll i=0;i<=m+1;i++) C[i]=h[i][0];
        ans=(calcn(m,C,n)*pow_mod(R,n)-c)%MOD;
        if(ans<0) ans+=MOD;
        return ans;
    }
}
ll n,D,dp[MAXN][MAXN],a[MAXN];
vector<ll> G[MAXN];
void dfs(ll v,ll p,ll d)
{
    for(ll i=0;i<=d;i++) dp[v][i]=1;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        dfs(to,v,d);
        for(ll j=0;j<=d;j++) a[j]=dp[to][j];
        for(ll j=1;j<=d;j++) a[j]=(a[j]+a[j-1])%MOD;
        for(ll j=0;j<=d;j++) dp[v][j]=1LL*dp[v][j]*a[j]%MOD;
    }
}
int main()
{
    scanf("%lld%lld",&n,&D);
    for(ll i=2;i<=n;i++)
    {
        ll x;
        scanf("%lld",&x);
        G[i].push_back(x);G[x].push_back(i);
    }
    dfs(1,0,n);
    for(ll i=0;i<=n;i++) a[i]=dp[1][i];
    for(ll i=1;i<=n;i++) a[i]=(a[i]+a[i-1])%MOD;
    //for(ll i=0;i<=n;i++) printf("%lld\n",a[i]);
    polysum::init(4000);
    printf("%lld\n",polysum::calcn(n,a,D-1));
    return 0;
}