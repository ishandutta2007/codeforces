#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> x(n), y(n); for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  V<> id(4);
  id[0] = distance(begin(x), max_element(begin(x), end(x)));
  id[1] = distance(begin(y), min_element(begin(y), end(y)));
  id[2] = distance(begin(x), min_element(begin(x), end(x)));
  id[3] = distance(begin(y), max_element(begin(y), end(y)));
  int f4 = 0;
  auto dist = [&](int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
  };
  for (int i = 0; i < 4; ++i) f4 += dist(id[i], id[(i + 1) % 4]);
  int f3 = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < n; ++j) if (j != id[i] and j != id[(i + 1) % 4]) {
      f3 = max(f3, dist(id[i], id[(i + 1) % 4]) + dist(id[i], j) + dist(id[(i + 1) % 4], j));
    }
  }
  if (n == 3) return cout << f3 << '\n', 0;
  cout << f3 << ' ';
  for (int i = 0; i < n - 3; ++i) cout << f4 << (i != n - 4 ? ' ' : '\n');
}