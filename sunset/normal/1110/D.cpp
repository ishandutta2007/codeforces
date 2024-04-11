#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++a[x - 1];
  }
  vector<vector<int>> dp(3, vector<int>(3, -1));
  vector<vector<int>> new_dp(3, vector<int>(3, -1));
  dp[0][0] = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        new_dp[j][k] = -1;
      }
    }
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (dp[j][k] != -1 && a[i] >= j + k) {
          int remain = a[i] - j - k;
          for (int l = 0; l < 3 && l <= remain; ++l) {
            new_dp[k][l] = max(new_dp[k][l], dp[j][k] + (remain - l) / 3 + l);
          }
        }
      }
    }
    swap(dp, new_dp);
  }
  cout << dp[0][0] << "\n";
  return 0;
}