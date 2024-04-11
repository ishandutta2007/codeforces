#include <bits/stdc++.h>

using namespace std;
long long dp[1000001][6];
long long a[1000001];
int n;string s;
long long solve(int i,int j)
{
    if (j>=4)return (1LL<<55);
    if (i==n) return 0;
    if (dp[i][j]!=-1)return dp[i][j];
    long long ret=(1LL<<55);
    if (s[i]=='h')
    {
        if (j==0)
            dp[i][j]=min(solve(i+1,j+1),solve(i+1,j)+a[i]);
        else
            dp[i][j]=solve(i+1,j);
    }
    else if (s[i]=='a')
    {
        if (j==1)
            dp[i][j]=min(solve(i+1,j+1),solve(i+1,j)+a[i]);
        else
            dp[i][j]=solve(i+1,j);
    }
    else if (s[i]=='r')
    {
        if (j==2)
            dp[i][j]=min(solve(i+1,j+1),solve(i+1,j)+a[i]);
        else
            dp[i][j]=solve(i+1,j);
    }
    else if (s[i]=='d')
    {
        if (j==3)
            dp[i][j]=min(solve(i+1,j+1),solve(i+1,j)+a[i]);
        else
            dp[i][j]=solve(i+1,j);
    }
    else dp[i][j]=solve(i+1,j);
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>s;
    for (int i=0;i<n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0)<<endl;
}