#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> b(n); for (auto&& e : b) cin >> e;
  V<> g(m); for (auto&& e : g) cin >> e;
  sort(begin(b), end(b));
  sort(begin(g), end(g));
  if (b.back() > g[0]) return cout << -1 << '\n', 0;
  lint res = accumulate(begin(g), end(g), 0LL);
  res += accumulate(begin(b), end(b) - 1, 0LL) * m;
  if (b.back() < g[0]) {
    res += b.back() - b[n - 2];
  }
  cout << res << '\n';
}