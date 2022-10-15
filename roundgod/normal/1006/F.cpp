/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-16 22:37:50
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 25
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,k,a[MAXN][MAXN];
unordered_map<ll,ll> dp[MAXN][MAXN];
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
            scanf("%lld",&a[i][j]);
    if(n==1&&m==1)
    {
        if(a[1][1]==k) puts("1");
        else puts("0");
        return 0;
    }
    ll lim=(n+m+2)/2;
    dp[1][0][0]=1;
    for(ll i=1;i<=min(n,lim);i++)
    {
        for(ll j=1;i+j<=lim;j++)
        {
            for(auto it=dp[i-1][j].begin();it!=dp[i-1][j].end();it++)
                dp[i][j][(it->F)^a[i][j]]+=it->S;
            for(auto it=dp[i][j-1].begin();it!=dp[i][j-1].end();it++)
               dp[i][j][(it->F)^a[i][j]]+=it->S;
        }
    }
    dp[n][m+1][0]=1;
    ll ans=0;
    for(ll i=n;i>=1;i--)
    {
        for(ll j=m;i+j>lim;j--)
        {
            for(auto it=dp[i+1][j].begin();it!=dp[i+1][j].end();it++)
                dp[i][j][(it->F)^a[i][j]]+=it->S;
            for(auto it=dp[i][j+1].begin();it!=dp[i][j+1].end();it++)
                dp[i][j][(it->F)^a[i][j]]+=it->S;
            if(i+j==lim+1)
            {
                for(auto it=dp[i][j].begin();it!=dp[i][j].end();it++)
                {
                    //printf("%lld %lld %lld\n",i,it->F,it->S);
                    ans+=1LL*(it->S)*dp[i-1][j][it->F^k];
                    ans+=1LL*(it->S)*dp[i][j-1][it->F^k];
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}