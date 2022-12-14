#include<bits/stdc++.h>
using namespace std;
long long dp[1111][1111];
long long mod = 1000000007;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=1000;i++)dp[1][i]=1;
    for (int i=1;i<=k;i++)
    {
        long long cur=0;
        long long cur2=0;
        for (int j=0;j<=1000;j++)
        {
            cur+=dp[i][j];
            cur%=mod;
            cur2+=cur;
            cur2%=mod;
            dp[i+1][j+2-(i==0)]+=cur2;
            dp[i+1][j+2-(i==0)]%=mod;
        }
    }
    cout<<(dp[k+1][n]*dp[k+1][m])%mod<<endl;
}