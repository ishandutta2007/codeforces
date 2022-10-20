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
  V<lint> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  V<lint> c(n); for (int i = 0; i < n; ++i) cin >> c[i];
  V<lint> t(m), d(m); for (int i = 0; i < m; ++i) cin >> t[i] >> d[i], --t[i];
  V<> id(n);
  iota(begin(id), end(id), 0);
  sort(begin(id), end(id), [&](int i, int j) { return c[i] != c[j] ? c[i] < c[j] : i < j; });
  int x = 0;
  for (int j = 0; j < m; ++j) {
    lint res = 0;
    if (a[t[j]] >= d[j]) {
      res += c[t[j]] * d[j];
      a[t[j]] -= d[j];
      d[j] = 0;
    } else {
      res += a[t[j]] * c[t[j]];
      d[j] -= a[t[j]];
      a[t[j]] = 0;
      while (x < n and d[j] > 0) {
        if (a[id[x]] >= d[j]) {
          res += c[id[x]] * d[j];
          a[id[x]] -= d[j];
          d[j] = 0;
        } else {
          res += a[id[x]] * c[id[x]];
          d[j] -= a[id[x]];
          a[id[x]] = 0;
          ++x;
        }
      }
    }
    if (d[j] > 0) {
      res = 0;
    }
    cout << res << '\n';
  }
}