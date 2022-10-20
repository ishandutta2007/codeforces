#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    VV<> a(m, V<>(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      cin >> a[j][i];
    }
    sort(rbegin(a), rend(a), [](const auto& l, const auto& r) {
      return *max_element(begin(l), end(l)) < *max_element(begin(r), end(r));
    });
    V<> dp(1 << n, -1e9);
    dp[0] = 0;
    for (int j = 0; j < min(n, m); ++j) {
      auto ndp = dp;
      for (int S = 0; S < 1 << n; ++S) {
        for (int i = 0; i < n; ++i) if (~S >> i & 1) {
          ndp[S | 1 << i] = max(ndp[S | 1 << i], ndp[S] + a[j][i]);
        }
      }
      swap(dp, ndp);
      for (int S = 0; S < 1 << n; ++S) {
        for (int k = 0; k < n; ++k) {
          int T = S >> k | (S & ~(~0U << k)) << n - k;
          dp[T] = max(dp[T], dp[S]);
        }
      }
    }
    cout << dp.back() << '\n';
  }
}