#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<vector<int>> dp(n + 1, vector<int>(2001, INF));
    dp[0][0] = 0;
    for (int j = 0; j < n; j++){
      for (int k = 0; k <= 2000; k++){
        if (dp[j][k] != INF){
          if (k + a[j] <= 2000){
            dp[j + 1][k + a[j]] = min(dp[j + 1][k + a[j]], max(dp[j][k], k + a[j]));
          }
          if (k - a[j] >= 0){
            dp[j + 1][k - a[j]] = min(dp[j + 1][k - a[j]], dp[j][k]);
          } else {
            dp[j + 1][0] = min(dp[j + 1][0], dp[j][k] + a[j] - k);
          }
        }
      }
    }
    int ans = INF;
    for (int j = 0; j <= 2000; j++){
      ans = min(ans, dp[n][j]);
    }
    cout << ans << endl;
  }
}