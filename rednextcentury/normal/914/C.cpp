#include <bits/stdc++.h>
using namespace std;
long long dp[1001][1001][2];
bool vis[1001][1001][2];
int n;
string s;
int k;
long long mod = 1000000007;
int ret[1005];
long long DP(int i,int sum, bool is)
{
    if (i==n)
        return (ret[sum]==(k-1));
    if (vis[i][sum][is])
        return dp[i][sum][is];
    dp[i][sum][is]=0;
    if (is==0)
    {
        dp[i][sum][is]+=DP(i+1,sum,0);
        dp[i][sum][is]+=DP(i+1,sum+1,0);
        dp[i][sum][is]%=mod;
    }
    else
    {
        if (s[i]=='0')
            dp[i][sum][is] = DP(i+1,sum,1);
        else
        {
            dp[i][sum][is] = DP(i+1,sum,0) + DP(i+1,sum+1,1);
            dp[i][sum][is]%=mod;
        }
    }
    vis[i][sum][is]=1;
    return dp[i][sum][is];

}
int main()
{
    cin>>s>>k;
    n=s.size();
    ret[1]=0;
    for (int i=2;i<=1000;i++)
        ret[i]=ret[__builtin_popcount(i)]+1;
    long long ret = DP(0,0,1);
    if (k==0)
        ret = 1;
    else if (k==1)
        ret = n-1;
    cout<<ret<<endl;
}