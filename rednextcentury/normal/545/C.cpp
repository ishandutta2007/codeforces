#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[1000000][2];
pair<int,int> a[1000005];
int n;
int DP(int i,int j,int last)
{
    if (i==n)return 1;
    if (dp[i][j]!=-1)return dp[i][j];
    dp[i][j]=DP(i+1,0,a[i].first);
    if (a[i].first-a[i].second>last)
        dp[i][j]=max(dp[i][j],1+DP(i+1,0,a[i].first));
    if (a[i].first+a[i].second<a[i+1].first)
        dp[i][j]=max(dp[i][j],1+DP(i+1,1,a[i].first+a[i].second));
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    cout<<DP(1,0,-1e9)<<endl;
}