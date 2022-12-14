#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int dp[5001][5001];
int ba[5001][5001];
vector<int> adj[1000000];
vector<int> len[1000000];
int main()
{
    int n,m,T;
    cin>>n>>m>>T;
    for (int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[b].push_back(a);
        len[b].push_back(c);
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            dp[i][j]=T+1;
    dp[1][1]=0;
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            for (int x=0;x<adj[j].size();x++)
            {
                int u=adj[j][x];
                if (dp[i-1][u]+len[j][x]<dp[i][j])
                {
                    dp[i][j]=min(dp[i][j],dp[i-1][u]+len[j][x]);
                    ba[i][j]=u;
                }
            }
        }
    }
    for (int i=n;i>=1;i--)
    {
        if (dp[i][n]<=T)
        {
            int ans=i;
            cout<<ans<<endl;
            int v=n;
            vector<int> ret;
            while(ans>=1)
            {
                ret.push_back(v);
                v=ba[ans][v];
                ans--;
            }
            for (int i=ret.size()-1;i>=0;i--)
                cout<<ret[i]<<' ';
            cout<<endl;
            return 0;
        }
    }
}