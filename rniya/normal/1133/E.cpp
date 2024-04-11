#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    sort(a.begin(),a.end());
    vector<vector<int>> dp(n+1,vector<int>(k+1,-INF));
    dp[0][0]=0;
    int r=0;
    for (int i=0;i<n;++i){
        while(r<n&&a[r]<=a[i]+5) ++r;
        for (int j=0;j<=k;++j){
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if (j+1<=k) dp[r][j+1]=max(dp[r][j+1],dp[i][j]+r-i);
        }
    }
    int ans=-INF;
    for (int j=0;j<=k;++j) ans=max(ans,dp[n][j]);
    cout << ans << '\n';
}