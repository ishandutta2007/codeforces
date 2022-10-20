#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> x(n), y(n); for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  V<> a(n);
  iota(begin(a), end(a), 0);
  sort(begin(a), end(a), [&](int i, int j) { return x[i] - y[i] < x[j] - y[j]; });
  V<> ia(n);
  for (int i = 0; i < n; ++i) ia[a[i]] = i;
  V<lint> l(n), r(n);
  VV<> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    if (ia[u] > ia[v]) swap(u, v);
    ++r[ia[u]], ++l[ia[v]];
    g[u].push_back(v);
    g[v].push_back(u);
  }
  V<lint> res(n);
  V<lint> cx(n + 1), cy(n + 1);
  for (int i = 0; i < n; ++i) {
    cx[i + 1] = cx[i] + x[a[i]];
    cy[i + 1] = cy[i] + y[a[i]];
  }
  for (int i = 0; i < n; ++i) {
    res[i] = y[i] * (ia[i] - l[ia[i]]) + x[i] * (n - 1 - ia[i] - r[ia[i]]);
    res[i] += cx[ia[i]] + cy[n] - cy[ia[i] + 1];
    for (int j : g[i]) res[i] -= (ia[j] < ia[i] ? x[j] : y[j]);
  }
  for (int i = 0; i < n; ++i) cout << res[i] << (i != n - 1 ? ' ' : '\n');
}