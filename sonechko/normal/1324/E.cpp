#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2000 + 11;

int dp[N][N],a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=0; i<=n; i++)
    for (int j=0; j<=h; j++)
        dp[i][j]=-2e9;
    dp[0][0]=0;
    for (int i=1; i<=n; i++)
    for (int last=0; last<h; last++)
    {
        int x=(last+a[i])%h;
        int y=(last+a[i]-1)%h;
        if (l<=x&&x<=r) dp[i][x]=max(dp[i][x],dp[i-1][last]+1);
        else dp[i][x]=max(dp[i][x],dp[i-1][last]);
        if (l<=y&&y<=r) dp[i][y]=max(dp[i][y],dp[i-1][last]+1);
        else dp[i][y]=max(dp[i][y],dp[i-1][last]);
    }
    int ans=0;
    for (int last=0; last<h; last++)
        ans=max(ans,dp[n][last]);
    cout<<ans;
}