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
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  V<> s(m), f(m), c(m), r(m); for (int i = 0; i < m; ++i) cin >> s[i] >> f[i] >> c[i] >> r[i], --s[i], --f[i];
  auto chk = [&](int j, lint x) -> bool {
    int t = 0;
    lint v = x;
    for (int i = s[j]; i < f[j]; ++i) {
      v -= lint(a[i + 1] - a[i]) * c[j];
      if (v < 0) {
        v = x - lint(a[i + 1] - a[i]) * c[j];
        if (v < 0) return false;
        ++t;
      }
      if (t > r[j]) return false;
    }
    return true;
  };
  lint res = 0;
  V<> js(m);
  iota(begin(js), end(js), 0);
  shuffle(begin(js), end(js), mt19937(chrono::steady_clock::now().time_since_epoch().count()));
  for (int j : js) {
    if (chk(j, res)) continue;
    lint ng = 0, ok = 9e18;
    while (ok - ng > 1) {
      lint mid = ng + ok >> 1;
      (chk(j, mid) ? ok : ng) = mid;
    }
    res = max(res, ok);
  }
  cout << res << '\n';
}