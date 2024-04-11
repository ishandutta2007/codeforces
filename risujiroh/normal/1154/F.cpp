#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  V<> a(n); for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  a.resize(k);
  V<> b(k + 1);
  while (m--) {
    int x, y; cin >> x >> y;
    if (x > k) continue;
    b[x] = max(b[x], y);
  }
  V<lint> dp(k + 1, 1e18);
  dp[k] = 0;
  V<lint> c(k + 1);
  for (int i = 0; i < k; ++i) c[i + 1] = c[i] + a[i];
  for (int i = k - 1; i >= 0; --i) {
    // dp[i] = a[i] + dp[i + 1];
    for (int j = 1; i + j <= k; ++j) {
      dp[i] = min(dp[i], c[i + j] - c[i + b[j]] + dp[i + j]);
    }
  }
  cout << dp[0] << '\n';
}