#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
vector<int> adj[1000000];
long long a[1000000];
long long dp[1000000];
long long mx=-1e18;
long long num=0;
void dfs(int v=1,int pa=-1)
{
    dp[v]=a[v];
    for (auto u:adj[v])
    {
        if (u==pa)continue;
        dfs(u,v);
        if (dp[u]>0)dp[v]+=dp[u];
    }
    if (dp[v]>mx)mx=dp[v];
}
void dfs2(int v=1,int pa=-1)
{
    dp[v]=a[v];
    for (auto u:adj[v])
    {
        if (u==pa)continue;
        dfs2(u,v);
        if (dp[u]>0)dp[v]+=dp[u];
    }
    if (dp[v]==mx)num++,dp[v]=0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    dfs2();
    cout<<mx*num<<' '<<num<<endl;
}