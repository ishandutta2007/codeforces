#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long dp[100002][4][4];
bool v[100002][4][4];
long long val[100002][4][4];
int n;
long long DP(int i,int s,int e)
{
    if (i==n+1)
    {
        if (e==2)
            return 0;
        else
            return -(1LL<<55);
    }
    if (v[i][s][e])
        return dp[i][s][e];
    v[i][s][e]=1;
    dp[i][s][e]=-(1LL<<55);
    // 1 step
    for (int r=0;r<3;r++)
        dp[i][s][e]=max(dp[i][s][e],DP(i+1,e,r)+val[i][e][r]);
    // 2 step
    if (i+1<=n)
    {
        if (e==0)
            dp[i][s][e]=max(dp[i][s][e],DP(i+2,0,2)+val[i][0][2]+val[i+1][0][2]);
        if (e==2)
            dp[i][s][e]=max(dp[i][s][e],DP(i+2,2,0)+val[i][0][2]+val[i+1][0][2]);
    }
    return dp[i][s][e];
}
long long a[100002][4];
int main()
{
    fast
    cin>>n;
    for (int j=0;j<3;j++)
        for (int i=1;i<=n;i++)
            cin>>a[i][j];
    for (int i=1;i<=n;i++)
        for (int l=0;l<3;l++)
            for (int r=0;r<3;r++)
                for (int x=min(l,r);x<=max(l,r);x++)
                    val[i][l][r]+=a[i][x];
    cout<<DP(1,0,0)<<endl;
}