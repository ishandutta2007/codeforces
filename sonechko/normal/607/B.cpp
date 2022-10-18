#include<bits/stdc++.h>
using namespace std;

const int N = 500 + 11;

int dp[N][N],a[N];

int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        for (int j=1; j<=n; j++)
            dp[i][j]=n+5;
        dp[i][i]=1;
        dp[i][i-1]=1;
    }
    for (int len=2; len<=n; len++)
    for (int i=1; i<=n-len+1; i++)
    {
        int l=i;
        int r=i+len-1;
        dp[l][r]=dp[l+1][r]+1;
        for (int t=l+1; t<=r; t++)
            if (a[l]==a[t]) dp[l][r]=min(dp[l][r],dp[l+1][t-1]+dp[t+1][r]);
        if (a[l]==a[r]) dp[l][r]=min(dp[l][r],dp[l+1][r-1]);
        ///cout<<l<<".."<<r<<" - "<<dp[l][r]<<endl;
    }
    cout<<dp[1][n]<<endl;
}