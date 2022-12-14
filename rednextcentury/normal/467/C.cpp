#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int n,m,k;
long long a[1000000];
long long dp[5001][5001];
long long DP(int i,int j)
{
    if (j>k)return -1e16;
    if (i>n+1)return -1e16;
    if (i==n+1)
    {
        if (j==k)return 0;
        return -1e16;
    }
    if (dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=max(DP(i+1,j),DP(i+m,j+1)+a[i+m-1]-a[i-1]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=a[i-1]+a[i];
    }
    cout<<DP(0,0)<<endl;
}