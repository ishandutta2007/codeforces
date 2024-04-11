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
  V<> c(m);
  for (int i = 0; i < n; ++i) {
    int a; cin >> a, --a;
    ++c[a];
  }
  VV<> dp0; assign(dp0, 3, 3, -1e9);
  dp0[0][0] = 0;
  for (int i = 0; i < m; ++i) {
    VV<> dp1; assign(dp1, 3, 3, -1e9);
    for (int j = 0; j < 3; ++j) for (int k = 0; k < 3; ++k) {
      for (int x = 0; x < 3; ++x) {
        if (c[i] - x - j - k >= 0) {
          dp1[j][k] = max(dp1[j][k], dp0[x][j] + x + (c[i] - x - j - k) / 3);
        }
      }
    }
    swap(dp0, dp1);
  }
  cout << dp0[0][0] << '\n';
}