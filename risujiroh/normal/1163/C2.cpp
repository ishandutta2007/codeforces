#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  auto fn = [](int x0, int y0, int x1, int y1) -> tuple<int, int, int> {
    int a = y1 - y0, b = x0 - x1, c = x0 * y1 - y0 * x1;
    int d = __gcd(__gcd(a, b), c);
    a /= d, b /= d, c /= d;
    if (a < 0) a = -a, b = -b, c = -c;
    return {a, b, c};
  };
  int n; cin >> n;
  V<> x(n), y(n); for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  map< pair<int, int>, int> mp;
  set< tuple<int, int, int> > se;
  lint res = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) {
    int a, b, c;
    tie(a, b, c) = fn(x[i], y[i], x[j], y[j]);
    if (se.count({a, b, c})) continue;
    res += se.size() - mp[{a, b}]++;
    se.emplace(a, b, c);
  }
  cout << res << '\n';
}