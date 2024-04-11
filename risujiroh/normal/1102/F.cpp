#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<> a; assign(a, n, m, 0);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    cin >> a[i][j];
  }
  if (n == 1) {
    int res = 1e9;
    for (int j = 0; j < m - 1; ++j) {
      res = min(res, abs(a[0][j] - a[0][j + 1]));
    }
    cout << res << '\n';
    return 0;
  }
  VV<> mn; assign(mn, n, n, 1e9);
  for (int i0 = 0; i0 < n; ++i0) for (int i1 = i0 + 1; i1 < n; ++i1) {
    int curr = 1e9;
    for (int j = 0; j < m; ++j) {
      curr = min(curr, abs(a[i0][j] - a[i1][j]));
    }
    mn[i0][i1] = mn[i1][i0] = curr;
  }
  VV<> mn1; assign(mn1, n, n, 1e9);
  for (int i0 = 0; i0 < n; ++i0) for (int i1 = 0; i1 < n; ++i1) if (i0 != i1) {
    int curr = 1e9;
    for (int j = 0; j < m - 1; ++j) {
      curr = min(curr, abs(a[i1][j] - a[i0][j + 1]));
    }
    mn1[i0][i1] = curr;
  }
  V< VV<> > dp; assign(dp, n, 1 << n, n, 0);
  for (int i = 0; i < n; ++i) {
    dp[i][1 << i][i] = 1e9;
  }
  for (int i = 0; i < n; ++i) {
    for (int bit = 0; bit < 1 << n; ++bit) {
      for (int j = 0; j < n; ++j) if (!(bit & 1 << j)) {
        for (int l = 0; l < n; ++l) if (bit & 1 << l) {
          dp[i][bit | 1 << j][j] = max(dp[i][bit | 1 << j][j], min(dp[i][bit][l], mn[l][j]));
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (i != j) {
    res = max(res, min(dp[i].back()[j], mn1[i][j]));
  }
  cout << res << '\n';
}