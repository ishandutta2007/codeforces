#include <bits/stdc++.h>
using namespace std;
const int INF=1e9,MAX=1e5+10,MAX_KN=5010;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,K; cin >> n >> K;
    vector<int> c(K*n),f(n),h(K);
    for (int i=0;i<K*n;++i) cin >> c[i];
    for (int i=0;i<n;++i) cin >> f[i];
    for (int i=0;i<K;++i) cin >> h[i];
    vector<int> cnt(MAX,0);
    for (int i=0;i<K*n;++i) ++cnt[c[i]];
    sort(f.begin(),f.end());
    vector<vector<int>> dp(n+1,vector<int>(MAX_KN,-INF));
    dp[0][0]=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<MAX_KN;++j){
            int nxt=(!i||f[i-1]!=f[i]?0:j);
            for (int k=0;k<=K&&nxt+k<=cnt[f[i]];++k){
                dp[i+1][nxt+k]=max(dp[i+1][nxt+k],dp[i][j]+(!k?0:h[k-1]));
            }
        }
    }
    int ans=0;
    for (int j=0;j<MAX_KN;++j) ans=max(ans,dp[n][j]);
    cout << ans << '\n';
}