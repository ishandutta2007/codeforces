#include "bits/stdc++.h"

#define int int64_t

using namespace std;


int32_t main() {
    int n, m;
  cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<vector<int>>> dp(n + 2, vector<vector<int>> (m + 2, vector<int> (4, 0) ) );

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + a[i - 1][j - 1];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      dp[i][j][1] = max(dp[i + 1][j][1], dp[i][j + 1][1]) + a[i - 1][j - 1];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      dp[i][j][2] = max(dp[i + 1][j][2], dp[i][j - 1][2]) + a[i - 1][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      dp[i][j][3] = max(dp[i - 1][j][3], dp[i][j + 1][3]) + a[i - 1][j - 1];
    }
  }
  int ans = 0;
  for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
            int k =max(dp[i - 1][j][0] + dp[i + 1][j][1] + dp[i][j - 1][2] + dp[i][j + 1][3], dp[i][j - 1][0] + dp[i][j + 1][1] + dp[i + 1][j][2] + dp[i - 1][j][3]);
            ans = max(ans, k);
            //cout << ans<< " ";
        }
  }
  cout << ans;
    //
}