#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
bool vis[100001][21];
long long dp[100001][21][2];
int a[100001][21];
long long ret[21];
void dfs(int v,int x)
{
    vis[v][x]=1;
    long long tot[2]={0,0};
    dp[v][x][0]=dp[v][x][1]=0;
    dp[v][x][a[v][x]]=1;
    if (a[v][x])ret[x]++;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u][x])
            continue;
        dfs(u,x);
        if (a[v][x])
            ret[x]+=(tot[0]+1)*dp[u][x][0]+tot[1]*dp[u][x][1];
        else
            ret[x]+=tot[1]*dp[u][x][0]+(tot[0]+1)*dp[u][x][1];
        tot[0]+=dp[u][x][0];
        tot[1]+=dp[u][x][1];

    }
    if (a[v][x])
        dp[v][x][0]+=tot[1],dp[v][x][1]+=tot[0];
    else
        dp[v][x][0]+=tot[0],dp[v][x][1]+=tot[1];
}
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for (int j=0;j<20;j++)
        {
            a[i][j]=x%2;
            x/=2;
        }
    }
    for (int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=0;i<20;i++)
        dfs(1,i);
    long long ans=0;
    long long p=1;
    for (int i=0;i<20;i++)
    {
        ans+=p*ret[i];
        p=p*2;
    }
    cout<<ans<<endl;
}