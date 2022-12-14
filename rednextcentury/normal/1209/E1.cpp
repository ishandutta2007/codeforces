#include<bits/stdc++.h>
using namespace std;
int dp[101][(1<<4)];
int vis[101][(1<<4)];
int T;
int n,m;
int best[101][(1<<4)];
int cur[101][(1<<4)][4];
int DP(int i,int mask)
{
    if (i==m)return 0;
    if (vis[i][mask]==T)return dp[i][mask];
    vis[i][mask]=T;
    dp[i][mask]=0;
    for (int j=0;j<(1<<n);j++)
    {
        if (j&mask)continue;
        dp[i][mask]=max(dp[i][mask],DP(i+1,mask|j)+best[i][j]);
    }
    return dp[i][mask];
}
int a[4][1000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        T++;
        cin>>n>>m;
        int tot=(1<<n);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        for (int j=0;j<m;j++)
        {
            for (int mask=0;mask<tot;mask++)
            {
                best[j][mask]=0;
                for (int x=0;x<n;x++)
                {
                    cur[j][mask][x]=0;
                    for (int l=0;l<n;l++)
                    {
                        if ((1<<l)&mask)
                            cur[j][mask][x]+=(a[(l+x)%n][j]);
                    }
                    best[j][mask]=max(best[j][mask],cur[j][mask][x]);
                }
            }
        }
        cout<<DP(0,0)<<endl;
    }
}