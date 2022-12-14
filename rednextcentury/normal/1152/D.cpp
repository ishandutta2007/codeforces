#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
long long dp[2001][2001];
long long solve(int i,int sum)
{
    if (i==0)
        return 0;
    if (dp[i][sum]!=-1)
        return dp[i][sum];
    if (sum>0)
        dp[i][sum]=(solve(i-1,sum+1)+solve(i-1,sum-1))%1000000007;
    else
        dp[i][sum]=solve(i-1,sum+1);
    if (i%2 && i>=sum)
        dp[i][sum]=(1+dp[i][sum])%1000000007;
    return dp[i][sum];
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    n = n*2;
    memset(dp,-1,sizeof(dp));
    long long ret=0;
    cout<<solve(n,0)<<endl;
}