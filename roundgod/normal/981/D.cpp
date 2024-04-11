/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-28 18:00:51
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 55
#define MAXK 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k;
ll a[MAXN],sum[MAXN];
bool dp[MAXK][MAXN];
bool check(ll x)
{
    memset(dp,false,sizeof(dp));
    //printf("%lld\n",x);
    dp[0][0]=true;
    for(ll i=1;i<=k;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            for(ll l=0;l<j;l++)
            {
                if(!dp[i-1][l]) continue;
                if(((sum[j]-sum[l])&x)==x)
                {
                    dp[i][j]=true;
                    break;
                }
            }
            //printf("%d ",dp[i][j]?1:0);
        }
        //puts("");
    }
    return dp[k][n];
}
int main()
{
    scanf("%I64d%I64d",&n,&k);
    for(ll i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(ll i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    ll ans=0;
    for(ll i=59;i>=0;i--)
        if(check(ans+(1LL<<i))) ans+=(1LL<<i);
    printf("%I64d\n",ans);
    return 0;
}