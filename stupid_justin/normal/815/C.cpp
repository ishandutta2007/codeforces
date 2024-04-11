#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,fa;
int c[N],d[N];
int dp[N][N][2];
int sz[N];
vector<int> T[N];
void dfs(int u)
{
    sz[u]=1;
    dp[u][0][0]=0;dp[u][1][0]=c[u];
    dp[u][1][1]=c[u]-d[u];
    for (int i=0;i<T[u].size();i++)
    {
        int v=T[u][i];
        dfs(v);
        for (int j=sz[u];j>=0;j--)
            for (int k=0;k<=sz[v];k++)
            {
                dp[u][j+k][0]=min(dp[u][j+k][0],dp[u][j][0]+dp[v][k][0]);
                dp[u][j+k][1]=min(dp[u][j+k][1],dp[u][j][1]+min(dp[v][k][0],dp[v][k][1]));
            }
        sz[u]+=sz[v];
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>c[i]>>d[i];
        if (i>1)
        {
            cin>>fa;
            T[fa].push_back(i);
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dfs(1);
    for (int i=n;i>=0;i--)
        if (dp[1][i][0]<=m || dp[1][i][1]<=m)
        {
            cout<<i<<endl;
            return 0;
        }
}