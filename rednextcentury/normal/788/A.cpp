#include <bits/stdc++.h>
using namespace std;
long long dp[1000000][2];
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    dp[0][0]=0;
    dp[0][1]=-100000000;
    long long ans=-(1LL<<55);
    for (int i=1;i<=n-1;i++)
    {
        dp[i][0]=max(0LL,dp[i-1][1]-abs(a[i]-a[i+1]));
        dp[i][1]=max(0LL,dp[i-1][0]+abs(a[i]-a[i+1]));
        ans=max(ans,max(dp[i][0],dp[i][1]));
    }
    cout<<ans<<endl;
}