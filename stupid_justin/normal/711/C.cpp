#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=205;
int num[N];
int color[N][N];
int dp[N][N][N];//ijk
signed main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>num[i];
    int c;int l;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>color[i][j];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int v=0;v<=k;v++)
                dp[i][j][v]=inf;
    if(num[1])
        dp[1][num[1]][1]=0;
    else 
        for(int i=1;i<=m;i++)
            dp[1][i][1]=color[1][i];
        
    for(int i=2;i<=n;i++)
        if(num[i]!=0)
            for(int j=1;j<=m;j++)
                for(int v=1;v<=k&&v<=i;v++)
                    if(j==num[i])
                        dp[i][num[i]][v]=min(dp[i-1][num[i]][v],dp[i][num[i]][v]);
                    else 
                        dp[i][num[i]][v]=min(dp[i][num[i]][v],dp[i-1][j][v-1]);
        else 
            for(int j=1;j<=m;j++)
                for(int v=1;v<=m;v++)
                    for(int z=1;z<=k&&z<=i;z++)
                        if(j==v)
                            dp[i][j][z]=min(dp[i-1][j][z]+color[i][j],dp[i][j][z]);
                        
                        else 
                            dp[i][j][z]=min(dp[i-1][v][z-1]+color[i][j],dp[i][j][z]);
    int ans=inf;
    for(int i=1;i<=m;i++) ans=min(ans,dp[n][i][k]);
    if(ans>=inf) cout<<-1<<endl;
    else cout<<ans<<endl;
}