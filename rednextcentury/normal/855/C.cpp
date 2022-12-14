#include<bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long dp[100005][11][3];
bool vis[1000000];
vector<int> adj[1000000];
int n,m,k,x;
void dfs(int v)
{
    vis[v]=1;
    long long cur[11][3]={0};
    dp[v][0][0]=k-1;
    if (x)
        dp[v][1][1]=1;
    dp[v][0][2]=m-k;
    bool leaf=1;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u])continue;
        dfs(u);
        leaf=0;
        for (int j=0;j<=x;j++)
        {
            for (int p=0;p<=x-j;p++)
            {
                cur[j+p][0]+=((dp[v][j][0])*((dp[u][p][0]+dp[u][p][1]+dp[u][p][2])%mod));
                cur[j+p][0]%=mod;

                cur[j+p][1]+=((dp[v][j][1])*(dp[u][p][0]))%mod;
                cur[j+p][1]%=mod;

                cur[j+p][2]+=((dp[v][j][2])*(dp[u][p][0]+dp[u][p][2])%mod)%mod;
                cur[j+p][2]%=mod;
            }
        }
        for (int j=0;j<=x;j++)
            for (int p=0;p<3;p++)
                dp[v][j][p]=cur[j][p],cur[j][p]=0;
    }
    if (leaf)
    {
        if (x)dp[v][1][1]=1;
        dp[v][0][0]=(k-1);
        dp[v][0][2]=(m-k);
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin>>k>>x;
    dfs(1);
    long long ret=0;
    for (int i=0;i<=10;i++)
    {
        for (int j=0;j<3;j++)
            ret=(ret+dp[1][i][j])%mod;
    }    cout<<ret<<endl;
}