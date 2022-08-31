#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, n;
  cin >> r >> n;
  vector<int> t(n + 1);
  vector<int> x(n + 1);
  vector<int> y(n + 1);
  vector<int> dp(n + 1);
  vector<int> pref(n + 1);
  t[0] = 0;
  x[0] = 1;
  y[0] = 1;
  dp[0] = 0;
  pref[0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i] >> x[i] >> y[i];
    dp[i] = -n;
    for (int j = i - 1; j >= 0; --j) {
      if (t[i] - t[j] >= 2 * (r - 1)) {
        dp[i] = max(dp[i], pref[j] + 1);
        break;
      }
      if (t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j])) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    pref[i] = max(pref[i - 1], dp[i]);
  }
  cout << pref[n] << "\n";
  return 0;
}