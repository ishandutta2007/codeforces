#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, r; cin >> n >> r;
  V<> a(n), b(n); for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  V<> idx(n);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) {
    if (b[i] >= 0 and b[j] < 0) return true;
    if (b[i] < 0 and b[j] >= 0) return false;
    if (b[i] >= 0 and b[j] >= 0) return a[i] < a[j];
    return max(a[i], a[j] - b[i]) < max(a[j], a[i] - b[j]);
  });
  {
    auto na = a, nb = b;
    for (int p = 0; p < n; ++p) {
      a[p] = na[idx[p]];
      b[p] = nb[idx[p]];
    }
  }
  V<> dp(n + 1, -1e9);
  dp[0] = r;
  for (int i = 0; i < n; ++i) {
    V<> ndp(n + 1, -1e9);
    for (int x = 0; x <= n; ++x) if (dp[x] >= 0) {
      ndp[x] = max(ndp[x], dp[x]);
      if (dp[x] >= a[i]) {
        ndp[x + 1] = max(ndp[x + 1], dp[x] + b[i]);
      }
    }
    swap(dp, ndp);
  }
  for (int x = n; x >= 0; --x) if (dp[x] >= 0) {
    return cout << x << '\n', 0;
  }
}