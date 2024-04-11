#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000000];
vector<int> a[1000000];
bool vis[1000000];
int cur;
int dp[2000][2000];
void dfs(int v)
{
    vis[v]=1;
    a[cur].push_back(v);
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u])continue;
        dfs(u);
    }
}
int w[1000000];
int b[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,W;
    cin>>n>>m>>W;

    for (int i=1;i<=n;i++)
        cin>>w[i];
    for (int i=1;i<=n;i++)
        cin>>b[i];
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cur=1;
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            dfs(i);
            cur++;
        }
    }
    dp[1][0]=0;
    for (int i=1;i<cur;i++)
    {
        for (int j=0;j<=W;j++)
        {
            dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
            int Wc=0,B=0;
            for (int x=0;x<a[i].size();x++)
            {
                if (w[a[i][x]]+j<=W)
                    dp[i+1][w[a[i][x]]+j]=max(dp[i][j]+b[a[i][x]],dp[i+1][w[a[i][x]]+j]);
                Wc+=w[a[i][x]];
                B+=b[a[i][x]];
            }
            if (Wc+j<=W)
                dp[i+1][Wc+j]=max(dp[i+1][Wc+j],dp[i][j]+B);
        }
    }
    int ans=0;
    for (int i=1;i<=W;i++)
        ans=max(ans,dp[cur][i]);
    cout<<ans<<endl;
}