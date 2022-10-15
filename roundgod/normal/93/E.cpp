#include<bits/stdc++.h>
#define MAXN 105
#define MAGIC 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
ll n;
int k;
ll a[MAXN];
ll dp[MAXN][MAGIC];
ll solve(int now,ll mult)
{
    if(now==k+1) return mult;
    if(mult==0) return 0;
    if(mult<MAGIC&&dp[now][mult]!=-1) return dp[now][mult];
    ll res=0;
    res=solve(now+1,mult)-solve(now+1,mult/a[now]);
    if(mult<MAGIC) dp[now][mult]=res;
    return res;
}
int main()
{
    scanf("%lld%d",&n,&k);
    for(int i=1;i<=k;i++) scanf("%lld",&a[i]);
    sort(a+1,a+k+1,greater<ll>());
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",solve(1,n));
    return 0;
}