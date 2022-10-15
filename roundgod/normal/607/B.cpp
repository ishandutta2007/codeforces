#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
using namespace std;
int n,c[MAXN],dp[MAXN][MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) dp[i][i]=1;
    for(int len=2;len<=n;len++)
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(c[i]==c[j]) dp[i][j]=max(1,dp[i+1][j-1]); else dp[i][j]=INF;
            for(int k=i;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    printf("%d\n",dp[1][n]);
    return 0;
}