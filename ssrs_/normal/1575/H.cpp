#include <bits/stdc++.h>
using namespace std;
const int INF = 1000;
int main(){
  int n, m;
  cin >> n >> m;
  string a;
  cin >> a;
  string b;
  cin >> b;
  vector<vector<int>> nxt(m + 1, vector<int>(2));
  for (int i = 0; i <= m; i++){
    string p = b.substr(0, i);
    for (int j = 0; j < 2; j++){
      string p2 = p + (char) ('0' + j);
      int cnt = p2.size();
      for (int k = m; k >= 0; k--){
        if (k <= cnt){
          if (p2.substr(cnt - k) == b.substr(0, k)){
            nxt[i][j] = k;
            break;
          }
        }
      }
    }
  }
  vector<vector<int>> dp(m + 1, vector<int>(n - m + 2, INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++){
    vector<vector<int>> dp2(m + 1, vector<int>(n - m + 2, INF));
    for (int j = 0; j <= m; j++){
      for (int k = 0; k <= n - m; k++){
        if (dp[j][k] != INF){
          if (a[i] == '0'){
            if (nxt[j][0] == m){
              dp2[nxt[j][0]][k + 1] = min(dp2[nxt[j][0]][k + 1], dp[j][k]);
            } else {
              dp2[nxt[j][0]][k] = min(dp2[nxt[j][0]][k], dp[j][k]);
            }
            if (nxt[j][1] == m){
              dp2[nxt[j][1]][k + 1] = min(dp2[nxt[j][1]][k + 1], dp[j][k] + 1);
            } else {
              dp2[nxt[j][1]][k] = min(dp2[nxt[j][1]][k], dp[j][k] + 1);
            }
          }
          if (a[i] == '1'){
            if (nxt[j][0] == m){
              dp2[nxt[j][0]][k + 1] = min(dp2[nxt[j][0]][k + 1], dp[j][k] + 1);
            } else {
              dp2[nxt[j][0]][k] = min(dp2[nxt[j][0]][k], dp[j][k] + 1);
            }
            if (nxt[j][1] == m){
              dp2[nxt[j][1]][k + 1] = min(dp2[nxt[j][1]][k + 1], dp[j][k]);
            } else {
              dp2[nxt[j][1]][k] = min(dp2[nxt[j][1]][k], dp[j][k]);
            }
          }
        }
      }
    }
    swap(dp, dp2);
  }
  for (int i = 0; i < n - m + 2; i++){
    int ans = INF;
    for (int j = 0; j <= m; j++){
      ans = min(ans, dp[j][i]);
    }
    if (ans == INF){
      cout << -1;
    } else {
      cout << ans;
    }
    if (i < n - m + 1){
      cout << ' ';
    }
  }
  cout << endl;
}