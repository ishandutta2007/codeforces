#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,h,l,r; cin >> n >> h >> l >> r;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    vector<vector<int>> dp(n+1,vector<int>(h,-1));
    dp[0][0]=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<h;++j){
            if (dp[i][j]==-1) continue;
            int nj=(j+a[i]-1)%h;
            chmax(dp[i+1][nj],dp[i][j]+(l<=nj&&nj<=r?1:0));
            (nj+=1)%=h;
            chmax(dp[i+1][nj],dp[i][j]+(l<=nj&&nj<=r?1:0));
        }
    }
    int ans=0;
    for (int j=0;j<h;++j) chmax(ans,dp[n][j]);
    cout << ans << '\n';
}