#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
const ll N = 5000 + 11;
ll dp[N][N],a[N],b[N];
int  main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k;
    cin>>n>>k>>m;
    for (ll i=1; i<=n; i++)
        {
            cin>>a[i];
            b[i]=b[i-1]+a[i];
        }
    ll ans=0;
    for (int i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
    {
        dp[i][j]=dp[i-1][j];
        if (i>=k) dp[i][j]=max(dp[i][j],dp[i-k][j-1]+b[i]-b[i-k]);
        ans=max(ans,dp[i][j]);
    }
    cout<<ans<<endl;
}