#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
long long b[1000000];
int T;
long long dp[500000][4];
int vis[500000][4];
int n;
long long DP(int i,int j)
{
    if (i==n+1)return 0;
    if (vis[i][j]==T)return dp[i][j];
    vis[i][j]=T;
    int last = a[i-1]+j;
    dp[i][j]=1e18;
    for (int x=0;x<=3;x++)
    {
        if (a[i]+x == last)continue;
        dp[i][j]=min(dp[i][j],DP(i+1,x)+b[i]*x);
    }
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        T++;
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i]>>b[i];
        cout<<DP(1,0)<<"\n";
    }
}