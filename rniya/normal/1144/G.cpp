#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    vector<vector<int>> dp(n,vector<int>(2)),pre(n,vector<int>(2));
    for (int i=0;i<n;++i) dp[i][0]=-INF,dp[i][1]=INF;
    dp[0][0]=INF,dp[0][1]=-INF;
    for (int i=1;i<n;++i){
        if (a[i]>a[i-1]) if (chmax(dp[i][0],dp[i-1][0])) pre[i][0]=0;
        if (a[i]>dp[i-1][1]) if (chmax(dp[i][0],a[i-1])) pre[i][0]=1;
        if (a[i]<a[i-1]) if (chmin(dp[i][1],dp[i-1][1])) pre[i][1]=1;
        if (a[i]<dp[i-1][0]) if (chmin(dp[i][1],a[i-1])) pre[i][1]=0;
    }
    for (int j=0;j<2;++j) if (dp[n-1][j]!=(j?INF:-INF)){
        cout << "YES" << '\n';
        vector<int> ans(n);
        ans[n-1]=j;
        for (int i=n-2;i>=0;--i) ans[i]=pre[i+1][ans[i+1]];
        for (int i=0;i<n;++i) cout << ans[i] << (i+1==n?'\n':' ');
        return 0;
    }
    cout << "NO" << '\n';
}