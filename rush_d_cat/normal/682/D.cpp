#include<iostream>
using namespace std;
int dp[12][1002][1002][2];
int main()
{
    int m,n,k;
    char a[1002],b[1002];
    cin>>m>>n>>k>>a+1>>b+1;
    for(int cnt=1;cnt<=k;cnt++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i]==b[j]) dp[cnt][i][j][0]=max(dp[cnt][i-1][j-1][0]+1,dp[cnt-1][i-1][j-1][1]+1);
                dp[cnt][i][j][1]=max(dp[cnt][i][j][0],max(dp[cnt][i][j-1][1],dp[cnt][i-1][j][1]));
            }
        }
    }
    cout<<dp[k][m][n][1];
    return 0;
}