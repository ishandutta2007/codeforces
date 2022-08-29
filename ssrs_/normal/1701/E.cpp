#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string t;
    cin >> t;
    vector<vector<int>> dp(3, vector<int>(m + 1, INF));
    dp[0][0] = 1;
    dp[1][0] = 0;
    for (int j = 0; j < n; j++){
      vector<vector<int>> dp2(3, vector<int>(m + 1, INF));
      for (int k = 0; k <= m; k++){
        for (int l = 0; l < 2; l++){
          dp[l + 1][k] = min(dp[l + 1][k], dp[l][k]);
        }
        if (j < n){
          dp2[0][k] = min(dp2[0][k], dp[0][k] + 2);
          dp2[2][k] = min(dp2[2][k], dp[2][k] + 1);
          if (k < m){
            if (s[j] == t[k]){
              dp2[0][k + 1] = min(dp2[0][k + 1], dp[0][k] + 1);
              dp2[1][k + 1] = min(dp2[1][k + 1], dp[1][k]);
              dp2[2][k + 1] = min(dp2[2][k + 1], dp[2][k] + 1);
            }
          }
        }
      }
      swap(dp, dp2);
    }
    int ans = min({dp[0][m], dp[1][m], dp[2][m]});
    if (ans == INF){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}