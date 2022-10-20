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
  int n, k; cin >> n >> k;
  V<> p(n); for (auto&& e : p) cin >> e, --e;
  V<> q(n); for (auto&& e : q) cin >> e, --e;
  VV<> g(n);
  for (int i = 0; i < n - 1; ++i) {
    g[p[i]].push_back(p[i + 1]);
    g[q[i]].push_back(q[i + 1]);
  }
  V<> comp;
  int c = scc(g, comp);
  if (c < k) return cout << "NO" << '\n', 0;
  cout << "YES" << '\n';
  for (int i = 0; i < n; ++i) {
    cout << (char)('a' + min(comp[i], 25));
  }
  cout << '\n';
}