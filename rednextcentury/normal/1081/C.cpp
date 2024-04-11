#include <bits/stdc++.h>
using namespace std;
long long dp[2007][2007];
int n,m,k;
long long mod = 998244353;
long long sol(int i,int j)
{
    if (j>k)return 0;
    if (i==n)return j==k;
    if (dp[i][j]!=-1)return dp[i][j];
    dp[i][j]=(sol(i+1,j)+sol(i+1,j+1)*(m-1))%mod;
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));
    cout<<(m*sol(1,0))%mod<<endl;
}