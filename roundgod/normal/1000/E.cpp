/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-28 00:01:55
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,tot,ans;
int low[MAXN],dp[MAXN],dfn[MAXN];
vector<int> G[MAXN];
void dfs(int v,int p)
{
    dfn[v]=low[v]=++tot;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(!dfn[to])
        {
            dfs(to,v);
            ans=max(ans,dp[v]+dp[to]+(low[to]>dfn[v]));
            dp[v]=max(dp[v],dp[to]+(low[to]>dfn[v]));
            low[v]=min(low[v],low[to]);
        }
        else if(to!=p) low[v]=min(low[v],dfn[to]);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}