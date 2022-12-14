#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long dp[5001][5002];
int main()
{
    int m,a,b,n;
    cin>>m>>a>>b>>n;
    dp[0][a]=1;
    for (int i=0;i<n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            int dis=abs(j-b);
            if (i!=0)
            {
                dp[i][j]+=dp[i][j-1];
                dp[i][j]%=MOD;
            }
            if (j==b)continue;
            dp[i+1][min(m+1,j+dis)]-=dp[i][j];
            dp[i+1][min(m+1,j+dis)]=(dp[i+1][min(m+1,j+dis)]+MOD)%MOD;
            dp[i+1][min(m+1,j+1)]+=dp[i][j];
            dp[i+1][min(m+1,j+1)]%=MOD;
            dp[i+1][max(1,j-dis+1)]+=dp[i][j];
            dp[i+1][max(1,j-dis+1)]%=MOD;
            dp[i+1][j]-=dp[i][j];
            dp[i+1][j]=(dp[i+1][j]+MOD)%MOD;
        }
    }
    long long ans=0;
    for (int i=1;i<=m;i++)
        dp[n][i]+=dp[n][i-1],dp[n][i]%=MOD,ans=(ans+dp[n][i])%MOD;
    cout<<ans<<endl;
}