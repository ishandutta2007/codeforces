#include<bits/stdc++.h>
#define MAXN 3005
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll k,a,b;
ll p,q;
ll dp[MAXN][MAXN];
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
ll cal(ll n,ll m)
{
    if(dp[n][m]!=-1) return dp[n][m];
    if(n<=m)
    {
        ll d=mod_inverse(q,MOD);
        return dp[n][m]=d*(p+q*m%MOD)%MOD;
    }
    else return dp[n][m]=(p*cal(n,m+1)%MOD+q*(m+cal(n-m,m))%MOD)%MOD;
}
int main()
{
    scanf("%I64d%I64d%I64d",&k,&a,&b);
    p=(a*mod_inverse(a+b,MOD))%MOD;
    q=(b*mod_inverse(a+b,MOD))%MOD;
    for(ll i=0;i<MAXN;i++)
        for(ll j=0;j<MAXN;j++)
            dp[i][j]=-1;
    cal(k,1);
    printf("%I64d\n",dp[k][1]);
    return 0;
}