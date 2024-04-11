#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[j][i];
      }
    }
    for (int i = 0; i < m; ++i) {
      rotate(a[i].begin(), max_element(a[i].begin(), a[i].end()), a[i].end());
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    m = min(m, n);
    vector<vector<int>> w(m, vector<int>(1 << n));
    for (int i = 0; i < m; ++i) {
      for (int s = 0; s < 1 << n; ++s) {
        for (int j = 0; j < n; ++j) {
          int sum = 0;
          for (int k = 0; k < n; ++k) {
            if (s >> ((j + k) % n) & 1) {
              sum += a[i][k];
            }
          }
          w[i][s] = max(w[i][s], sum);
        }
      }
    }
    vector<int> dp(1 << n);
    for (int i = 0; i < m; ++i) {
      vector<int> new_dp(1 << n);
      for (int s = 0; s < 1 << n; ++s) {
        int u = ((1 << n) - 1) ^ s;
        for (int t = u; ; t = (t - 1) & u) {
          new_dp[s | t] = max(new_dp[s | t], dp[s] + w[i][t]);
          if (!t) {
            break;
          }
        }
      }
      swap(dp, new_dp);
    }
    cout << dp.back() << "\n";
  }
  return 0;
}