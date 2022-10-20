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
  int t; cin >> t;
  for (int it = 0; it < t; ++it) {
    int n, x, y, d; cin >> n >> x >> y >> d, --x, --y;
    int res = 2e9;
    if (abs(y - x) % d == 0) res = min(res, abs(y - x) / d);
    if (y % d == 0) {
      res = min(res, (x + d - 1) / d + y / d);
    }
    if ((n - 1 - y) % d == 0) {
      res = min(res, (n - 1 - x + d - 1) / d + (n - 1 - y) / d);
    }
    if (res == 2e9) res = -1;
    cout << res << '\n';
  }
}