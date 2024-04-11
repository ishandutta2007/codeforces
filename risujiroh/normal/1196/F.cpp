#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  V<> x(m), y(m), w(m); for (int i = 0; i < m; ++i) cin >> x[i] >> y[i] >> w[i], --x[i], --y[i];
  V<> idx(m);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) { return w[i] < w[j]; });

  struct Edge { int to, w; };
  VV<Edge> g(n);
  for (int i = 0; i < min(m, k); ++i) {
    g[x[idx[i]]].emplace_back(Edge{y[idx[i]], w[idx[i]]});
    g[y[idx[i]]].emplace_back(Edge{x[idx[i]], w[idx[i]]});
  }

  struct Path {
    int from, to;
    lint w;
    bool operator<(const Path& r) const { return w > r.w; }
  };
  priority_queue<Path> pq;
  for (int v = 0; v < n; ++v) for (auto e : g[v]) if (v < e.to) {
    pq.emplace(Path{v, e.to, e.w});
  }
  set< pair<int, int> > se;
  while (true) {
    auto p = pq.top(); pq.pop();
    if (se.count({p.from, p.to})) continue;
    se.emplace(p.from, p.to);
    se.emplace(p.to, p.from);
    if (!--k) {
      cout << p.w << '\n';
      break;
    }
    for (auto e : g[p.from]) if (e.to != p.to) {
      if (se.count({e.to, p.to})) continue;
      pq.emplace(Path{e.to, p.to, e.w + p.w});
    }
    for (auto e : g[p.to]) if (e.to != p.from) {
      if (se.count({p.from, e.to})) continue;
      pq.emplace(Path{p.from, e.to, p.w + e.w});
    }
  }
}