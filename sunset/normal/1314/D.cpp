#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
    }
  }
  int ans = 0x3f3f3f3f;
  while ((double) clock() / CLOCKS_PER_SEC < 2.9) {
    vector<int> black;
    vector<int> white;
    black.push_back(0);
    for (int i = 1; i < n; ++i) {
      if (mrand() % 2 == 1) {
        black.push_back(i);
      } else {
        white.push_back(i);
      }
    }
    vector<int> dp(black.size(), INF);
    dp[0] = 0;
    for (int t = 0; t < k; ++t) {
      vector<int> new_dp(white.size(), INF);
      for (int i = 0; i < (int) black.size(); ++i) {
        for (int j = 0; j < (int) white.size(); ++j) {
          new_dp[j] = min(new_dp[j], dp[i] + g[black[i]][white[j]]);
        }
      }
      swap(dp, new_dp);
      swap(black, white);
    }
    ans = min(ans, dp[0]);
  }
  cout << ans << "\n";
  return 0;
}