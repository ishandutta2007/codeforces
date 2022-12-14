#include <bits/stdc++.h>
using namespace std;
long long num[10];
long long dp[1000000][4];
int n;
long long mod=1e9+7;
long long DP(int i,int j)
{
    if (i==n)return j==0;
    if (dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j]=((num[0]*DP(i+1,j))%mod + (num[1]*DP(i+1,(j+1)%3))%mod + (num[2]*DP(i+1,(j+2)%3))%mod)%mod;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int l,r;
    cin>>n>>l>>r;
    while(l<=r && (r-l+1)%3!=0)
    {
        num[l%3]++;
        l++;
    }
    num[0]+=(r-l+1)/3;
    num[1]+=(r-l+1)/3;
    num[2]+=(r-l+1)/3;
    memset(dp,-1,sizeof(dp));
    cout<<DP(0,0)<<endl;
}