#include<bits/stdc++.h>
using namespace std;
long long dp[5005][5005][2];
long long tmp[5005][2];
int sub[5005];
int c[5005];
int d[5005];
vector<int> adj[5005];
void dfs(int v)
{
    sub[v]=1;
    dp[v][0][0]=0;
    dp[v][1][0]=c[v];
    dp[v][1][1]=c[v]-d[v];
    for (auto u:adj[v])
    {
        dfs(u);
        for (int i=0;i<=sub[v]+sub[u];i++)tmp[i][0]=tmp[i][1]=1e15;
        for (int i=0;i<=sub[v];i++){
            for (int j=0;j<=sub[u];j++){
                tmp[i+j][0]=min(tmp[i+j][0],dp[v][i][0]+dp[u][j][0]);
                if (i>=1)
                    tmp[i+j][1]=min(tmp[i+j][1],dp[v][i][1]+min(dp[u][j][1],dp[u][j][0]));
            }
        }
        for (int i=0;i<=sub[v]+sub[u];i++)dp[v][i][0]=min(dp[v][i][0],tmp[i][0]),
                                          dp[v][i][1]=min(dp[v][i][1],tmp[i][1]);
        sub[v]+=sub[u];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,b;
    cin>>n>>b;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=n;j++)
            dp[i][j][0]=dp[i][j][1]=1e15;
    for (int i=1;i<=n;i++)
    {
        cin>>c[i]>>d[i];
        if (i>=2){
            int p;
            cin>>p;
            adj[p].push_back(i);
        }
    }
    dfs(1);
    int ret=0;
    for (int i=1;i<=n;i++)
        if (min(dp[1][i][0],dp[1][i][1])<=b)ret=i;
    cout<<ret<<endl;
}