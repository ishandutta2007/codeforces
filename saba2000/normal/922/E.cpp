#include<bits/stdc++.h>
using namespace std;
long long dp[1009][10009];
long long c[1009],m[1009];
main()
{
    long long n,W,B,X;
    cin >> n >> W >> B >> X;
    for (long long i = 1; i <=n; i++)
        cin >> c[i];
    for (long long j = 1; j <=n; j++)
    {
        cin >> m[j];
    }
    dp[1][0]=W;
    for (long long i = 1; i <= 10000; i++)
        dp[1][i]=-1;
    for (long long i = 2; i <= n+1; i++)
    {
        for (long long j = 0; j <=10000; j++)
        {
            dp[i][j]=-1;
            for (long long k = 0; k <= min(j,c[i-1]); k++)
            {
                if(dp[i-1][j-k]>=m[i-1]*(k) ) {dp[i][j]=max(dp[i][j],min(W+B*j,dp[i-1][j-k]-m[i-1]*(k)+X)); }
            }
        }
    }
    for (int i =10000; i>=0; i--)
        if(dp[n+1][i]!=-1) {cout<<i<<endl; break;}


}