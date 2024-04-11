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
  VV<> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  V<> c(n, -1);
  auto dfs = [&](const auto& dfs, int v, int t) -> void {
    c[v] = t;
    for (int w : g[v]) if (c[w] == -1) {
      dfs(dfs, w, t);
    }
  };
  int t = 0;
  for (int v = 0; v < n; ++v) if (c[v] == -1) {
    dfs(dfs, v, t);
    ++t;
  }
  VV<> vs(t);
  for (int v = 0; v < n; ++v) {
    vs[c[v]].push_back(v);
  }
  V<> diam(t);
  VV<> es; assign(es, n, n, 0);
  for (int v = 0; v < n; ++v) for (int w : g[v]) {
    es[v][w] = 1;
  }
  V<> cent(t, -1);
  for (int ic = 0; ic < t; ++ic) {
    int nc = vs[ic].size();
    VV<> dist; assign(dist, nc, nc, 1e9);
    for (int i = 0; i < nc; ++i) dist[i][i] = 0;
    for (int i = 0; i < nc; ++i) for (int j = 0; j < nc; ++j) if (es[vs[ic][i]][vs[ic][j]]) dist[i][j] = 1;
    for (int k = 0; k < nc; ++k) for (int i = 0; i < nc; ++i) for (int j = 0; j < nc; ++j) {
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    for (int i = 0; i < nc; ++i) for (int j = 0; j < nc; ++j) {
      diam[ic] = max(diam[ic], dist[i][j]);
    }
    int mn = 1e9;
    for (int i = 0; i < nc; ++i) {
      int mx = 0;
      for (int j = 0; j < nc; ++j) mx = max(mx, dist[i][j]);
      if (mx < mn) {
        mn = mx;
        cent[ic] = vs[ic][i];
      }
    }
  }
  if (t == 1) return cout << diam[0] << '\n', 0;
  V<> ics(t);
  iota(begin(ics), end(ics), 0);
  sort(begin(ics), end(ics), [&](int icl, int icr) { return diam[icl] > diam[icr]; });
  int res = (diam[ics[0]] + 1) / 2 + (diam[ics[1]] + 1) / 2 + 1;
  res = max(res, diam[ics[0]]);
  if (t >= 3) {
    res = max(res, (diam[ics[1]] + 1) / 2 + (diam[ics[2]] + 1) / 2 + 2);
  }
  cout << res << '\n';
  for (int i = 1; i < t; ++i) {
    cout << cent[ics[0]] + 1 << ' ' << cent[ics[i]] + 1 << '\n';
  }
}