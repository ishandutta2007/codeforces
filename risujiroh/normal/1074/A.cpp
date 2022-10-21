#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> x(n); for (int i = 0; i < n; ++i) cin >> x[i];
  sort(begin(x), end(x));
  V<> z;
  for (int i = 0; i < m; ++i) {
    int x1, x2, y; cin >> x1 >> x2 >> y;
    if (x1 == 1) z.push_back(x2);
  }
  sort(begin(z), end(z));
  constexpr int inf = 1e9;
  if (!n) return cout << count(begin(z), end(z), inf) << '\n', 0;
  int res = distance(lower_bound(begin(z), end(z), x[0]), end(z));
  for (int i = 1; i < n; ++i) {
    res = min(res, i + distance(lower_bound(begin(z), end(z), x[i]), end(z)));
  }
  res = min(res, n + count(begin(z), end(z), inf));
  cout << res << '\n';
}