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
    VV<> a(n, V<>(m)); for (auto&& v : a) for (auto&& e : v) cin >> e;
    V<> dp(1 << n, -1e9);
    dp[0] = 0;
    for (int j = 0; j < m; ++j) {
      auto ndp = dp;
      for (int k = 0; k < n; ++k) {
        for (int S = 0; S < 1 << n; ++S) {
          for (int T = S; ; T = T - 1 & S) {
            int sum = 0;
            for (int i = 0; i < n; ++i) if ((S ^ T) >> i & 1) {
              sum += a[(k + i) % n][j];
            }
            ndp[S] = max(ndp[S], dp[T] + sum);
            if (!T) break;
          }
        }
      }
      swap(dp, ndp);
    }
    cout << dp.back() << '\n';
  }
}