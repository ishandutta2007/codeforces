#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,s[MAXN],t[MAXN],d[MAXN],w[MAXN];
P choice[MAXN];
vector<P> st[MAXN],ed[MAXN];
multiset<P> ms;
ll dp[MAXN][MAXM];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d%d",&s[i],&t[i],&d[i],&w[i]);
        st[s[i]].push_back(P(w[i],d[i]));
        ed[t[i]+1].push_back(P(w[i],d[i]));
    }
    for(int i=1;i<=n;i++)
    {
        for(auto v:st[i]) ms.insert(v);
        for(auto v:ed[i]) ms.erase(ms.find(v));
        if(!ms.size()) choice[i]=P(0,0);
        else
        {
            auto it=ms.end();it--;
            choice[i]=*it;
        }
    }
    memset(dp,0,sizeof(dp));
    dp[n+1][0]=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=m;j++)
        {
            if(!choice[i].F) dp[i][j]=dp[i+1][j];
            else dp[i][j]=choice[i].F+dp[choice[i].S+1][j];
            if(j) dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
        }
    }
    printf("%lld\n",dp[1][m]);
    return 0;
}