#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11;

int a[N];
int dp[N][4];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k1,k2,k3;
    cin>>k1>>k2>>k3;
    int n=k1+k2+k3;
    for (int i=1; i<=k1; i++)
    {
        int l;
        cin>>l;
        a[l]=1;
    }
    for (int i=1; i<=k2; i++)
    {
        int l;
        cin>>l;
        a[l]=2;
    }
    for (int i=1; i<=k3; i++)
    {
        int l;
        cin>>l;
        a[l]=3;
    }
    for (int i=1; i<=n; i++)
    {
        dp[i][1]=dp[i-1][1]+(a[i]==1);
        dp[i][2]=dp[i-1][2]+(a[i]==2);
        dp[i][3]=dp[i-1][3]+(a[i]==3);
    }
    int c=dp[0][2]-dp[0][1];
    int ans=2e9;
    for (int r=0; r<=n; r++)
    {
        c=min(c,dp[r][2]-dp[r][1]);
        ans=min(ans,c+dp[r][3]-dp[r][2]+dp[n][1]+dp[n][2]);
    }
    cout<<ans<<"\n";
}
/**
1 2 2 3 2 1 3 2 2
.....|....|......
    l    r

dp[l][2]+dp[l][3]
+dp[r][1]+dp[r][3]-dp[l][1]-dp[l][3]
+dp[n][1]+dp[n][2]-dp[r][1]-dp[r][2]
=dp[l][2]+dp[r][3]-dp[l][1]-dp[r][2]   + dp[n][1]+dp[n][2]

**/