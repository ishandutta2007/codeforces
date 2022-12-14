#include<bits/stdc++.h>
using namespace std;
int vis[1000000];
int viss[1000000];
vector<int> adj[1000000];
int best[1000000][2];
int k;
int dp[1000000][2];
bool evil[1000000];
int len=0;
void dfs(int v)
{
    vis[v]=1;
    if (evil[v])
        dp[v][0]=dp[v][1]=0;
    else
        dp[v][0]=dp[v][1]=-100000000;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u])continue;
        dfs(u);
        if (dp[u][0]+1>dp[v][0])
        {
            best[v][1]=best[v][0];
            dp[v][1]=dp[v][0];
            dp[v][0]=dp[u][0]+1;
            best[v][0]=u;
        }
        else if (dp[u][0]+1>dp[v][1])
        {
            best[v][1]=u;
            dp[v][1]=dp[u][0]+1;
        }
    }
    len=max(len,dp[v][0]+dp[v][1]);
}
int mx=0;
int ans=0;
void dfss(int v,int rocket_transition)
{
    if (max(dp[v][0],rocket_transition)<=k)
        ans++;
    viss[v]=1;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (viss[u])continue;
        if (best[v][0]==u)
            dfss(u,max(rocket_transition+1,dp[v][1]+1));
        else
            dfss(u,max(rocket_transition+1,dp[v][0]+1));
    }
}
int main()
{
        int n,m;
        scanf("%d%d%d",&n,&m,&k);
        for (int i=0;i<m;i++)
        {
            int x;
            cin>>x;
            evil[x]=1;
        }
        memset(dp,0,sizeof(dp));
        memset(best,-1,sizeof(best));
        for (int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        len=0;
        dfs(1);
        dfss(1,-100000000);
        cout<<ans<<endl;
}