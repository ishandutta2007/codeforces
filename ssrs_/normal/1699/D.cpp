#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<vector<bool>> ok(n + 1, vector<bool>(n + 1, false));
    for (int j = 0; j <= n; j++){
      vector<int> cnt(n, 0);
      int mx = 0;
      ok[j][j] = true;
      for (int k = j; k < n; k++){
        cnt[a[k]]++;
        mx = max(mx, cnt[a[k]]);
        if ((k - j) % 2 == 1){
          if (mx <= (k - j + 1) / 2){
            ok[j][k + 1] = true;
          }
        }
      }
    }
    vector<vector<int>> P(n);
    for (int j = 0; j < n; j++){
      P[j].push_back(-1);
    }
    for (int j = 0; j < n; j++){
      P[a[j]].push_back(j);
    }
    for (int j = 0; j < n; j++){
      P[j].push_back(n);
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      int cnt = P[j].size();
      vector<int> dp(cnt, -INF);
      dp[0] = 0;
      for (int k = 0; k < cnt; k++){
        for (int l = k + 1; l < cnt; l++){
          if (ok[P[j][k] + 1][P[j][l]]){
            dp[l] = max(dp[l], dp[k] + 1);
          }
        }
      }
      ans = max(ans, dp[cnt - 1] - 1);
    }
    cout << ans << endl;
  }
}