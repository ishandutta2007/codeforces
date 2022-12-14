# include <iostream>
# include <stdio.h>
# include <map>
# include <algorithm>
# include <vector>
#define eps 1e-9
using namespace std;
int a[1000000];
vector<int> adj[1000000];
bool vis[1000000];
int dp[1000000];
int ans=0;
int m;
int pa[1000000];
void dfs(int v,int cur)
{
    vis[v]=1;
    if (a[v])
        dp[v]=max(dp[pa[v]],++cur);
    else
        dp[v]=dp[pa[v]],cur=0;
    int n=adj[v].size();
    bool p=0;
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (vis[u])
            continue;
        pa[u]=v;
        p=1;
        dfs(u,cur);
    }
    if (!p && dp[v]<=m)
        ans++;
}
int main()
{
    int n;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<n-1;i++)
    {
        int s,e;
        cin>>s>>e;
        adj[e].push_back(s);
        adj[s].push_back(e);
    }
    dfs(1,0);
    cout<<ans<<endl;
}