#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int scc(const VV<>& g, V<>& comp) {
  int n = g.size();
  VV<> rg(n);
  for (int v = 0; v < n; v++) for (int w : g[v]) {
    rg[w].push_back(v);
  }
  V<> vs;
  V<bool> vis(n);
  comp.resize(n);
  auto dfs = [&](const auto& dfs, int v) -> void {
    vis[v] = true;
    for (int w : g[v]) if (!vis[w]) {
      dfs(dfs, w);
    }
    vs.push_back(v);
  };
  auto rdfs = [&](const auto& rdfs, int v, int k) -> void {
    vis[v] = true;
    comp[v] = k;
    for (int w : rg[v]) if (!vis[w]) {
      rdfs(rdfs, w, k);
    }
  };
  for (int v = 0; v < n; v++) if (!vis[v]) {
    dfs(dfs, v);
  }
  vis.assign(n, false);
  int k = 0;
  reverse(begin(vs), end(vs));
  for (int v : vs) if (!vis[v]) {
    rdfs(rdfs, v, k++);
  }
  return k;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<> g(n);
  struct Edge { int u, v; };
  V<Edge> es(m);
  for (int j = 0; j < m; ++j) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    es[j] = {u, v};
  }
  V<> comp;
  int c = scc(g, comp);
  if (c == n) {
    cout << 1 << '\n';
    for (int j = 0; j < m; ++j) {
      cout << 1 << " \n"[j == m - 1];
    }
  } else {
    cout << 2 << '\n';
    for (int j = 0; j < m; ++j) {
      cout << 1 + (es[j].u < es[j].v) << " \n"[j == m - 1];
    }
  }
}