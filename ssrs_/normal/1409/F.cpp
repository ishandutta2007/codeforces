#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  int N, K;
  cin >> N >> K;
  string s;
  cin >> s;
  string t;
  cin >> t;
  if (t[0] == t[1]){
    int cnt = 0;
    for (int i = 0; i < N; i++){
      if (s[i] == t[0]){
        cnt++;
      }
    }
    cnt = min(cnt + K, N);
    cout << cnt * (cnt - 1) / 2 << endl;
  } else {
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(K + 1, vector<int>(N + 1, -INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++){
      for (int j = 0; j <= K; j++){
        for (int k = 0; k < N; k++){
          if (s[i] == t[0]){
            dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k]);
            if (j < K){
              dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + k);
            }
          } else if (s[i] == t[1]){
            if (j < K){
              dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
            }
            dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + k);
          } else {
            dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
            if (j < K){
              dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
              dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + k);
            }
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i <= K; i++){
      for (int j = 0; j <= N; j++){
        ans = max(ans, dp[N][i][j]);
      }
    }
    cout << ans << endl;
  }
}