#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint n, m, k; cin >> n >> m >> k;
  V<lint> a(n); for (auto&& e : a) cin >> e;
  lint res = -9e18;
  for (int r = 0; r < m; ++r) {
    auto b = a;
    for (int i = r; i < n; i += m) b[i] -= k;
    V<lint> c(n + 1);
    for (int i = 0; i < n; ++i) c[i + 1] = c[i] + b[i];
    lint mn = 9e18;
    for (int i = 0; i <= n; ++i) {
      if (i % m == r) mn = min(mn, c[i]);
      res = max(res, c[i] - mn);
    }
  }
  cout << res << '\n';
}