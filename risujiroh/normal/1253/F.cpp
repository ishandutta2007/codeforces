#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

constexpr lint inf = 1e18;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m, k, q; cin >> n >> m >> k >> q;
  struct Edge { int to, w; };
  VV<Edge> g(n);
  V<> us(m), vs(m), ws(m);
  for (int i = 0; i < m; ++i) {
    int u, v, w; cin >> u >> v >> w, --u, --v;
    g[u].emplace_back(Edge{v, w});
    g[v].emplace_back(Edge{u, w});
    us[i] = u, vs[i] = v, ws[i] = w;
  }
  V<lint> dist(n, inf);
  using P = pair<lint, int>;
  priority_queue< P, V<P>, greater<P> > pq;
  for (int v = 0; v < k; ++v) {
    pq.emplace(dist[v] = 0, v);
  }
  while (not pq.empty()) {
    lint d; int v;
    tie(d, v) = pq.top(); pq.pop();
    if (d > dist[v]) continue;
    for (const auto& e : g[v]) if (dist[v] + e.w < dist[e.to]) {
      pq.emplace(dist[e.to] = dist[v] + e.w, e.to);
    }
  }
  struct NEdge {
    int u, v;
    lint w;
    bool operator<(const NEdge& r) const { return w < r.w; }
  };
  V<NEdge> es(m);
  for (int i = 0; i < m; ++i) {
    es[i] = {us[i], vs[i], dist[us[i]] + ws[i] + dist[vs[i]]};
  }
  sort(begin(es), end(es));
  V<lint> res(q, -1);
  V<> par(n);
  iota(begin(par), end(par), 0);
  VV<> ch(n);
  for (int v = 0; v < n; ++v) ch[v] = {v};
  V< set<int> > se(n);
  for (int i = 0; i < q; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    se[u].insert(i);
    se[v].insert(i);
  }
  for (const auto& e : es) {
    int pu = par[e.u], pv = par[e.v];
    if (pu == pv) continue;
    if (ch[pu].size() < ch[pv].size()) swap(pu, pv);
    for (int v : ch[pv]) par[v] = pu;
    ch[pu].insert(end(ch[pu]), begin(ch[pv]), end(ch[pv]));
    V<>().swap(ch[pv]);
    // if (se[pu].size() < se[pv].size()) swap(pu, pv);
    for (int i : se[pv]) {
      if (se[pu].count(i)) {
        res[i] = e.w;
        se[pu].erase(i);
      } else {
        se[pu].insert(i);
      }
    }
    set<int>().swap(se[pv]);
  }
  for (lint e : res) cout << e << '\n';
}