# include <bits/stdc++.h>
using namespace std;
int dp[100][2];
bool vis[100][2];
int a[100];
int n;
int DP(int i,int v)
{
    if (vis[i][v]==1)
        return dp[i][v];
    if (i==n+1)
        return 0;
    vis[i][v]=1;
    dp[i][v]=0;
    if (v==0)
    {
        return dp[i][v]=max(DP(i+1,!v)+a[i],DP(i+1,v));
    }
    else
    {
        return dp[i][v]=min(DP(i+1,!v),DP(i+1,v)+a[i]);
    }
}
int main()
{
    cin>>n;
    int sum=0;
    for (int i=1;i<=n;i++)
        cin>>a[i],sum+=a[i];
    int x=DP(0,0);
    cout<<sum-x<<' '<<x<<endl;
}