#include <bits/stdc++.h>
using namespace std;

auto chmin = [](auto&& l, auto r) { return r < l ? l = r, 1 : 0; };

constexpr int inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> nxt(n + 1, vector<int>(26, n));
    for (int i = n; i--; ) {
      nxt[i] = nxt[i + 1];
      nxt[i][s[i] - 'a'] = i;
    }
    [&] {
      for (int k = 0; k <= m; ++k) {
        string t0 = t.substr(0, k), t1 = t.substr(k);
        vector<vector<int>> dp(k + 1, vector<int>(m - k + 1, inf));
        for (int i = 0; i <= k; ++i) {
          for (int j = 0; j <= m - k; ++j) {
            if (i == 0 and j == 0) {
              dp[i][j] = 0;
            }
            if (i and dp[i - 1][j] < n) {
              chmin(dp[i][j], nxt[dp[i - 1][j]][t0[i - 1] - 'a'] + 1);
            }
            if (j and dp[i][j - 1] < n) {
              chmin(dp[i][j], nxt[dp[i][j - 1]][t1[j - 1] - 'a'] + 1);
            }
          }
        }
        if (dp[k][m - k] <= n) {
          cout << "YES\n";
          return;
        }
      }
      cout << "NO\n";
    }();
  }
}