#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int scc(const VV<>& g, V<>& comp) {
  int n = g.size();
  VV<> rg(n);
  for (int v = 0; v < n; v++) {
    for (int w : g[v]) {
      rg[w].push_back(v);
    }
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
    for (int w: rg[v]) if (!vis[w]) {
      rdfs(rdfs, w, k);
    }
  };

  for (int v = 0; v < n; v++) if (!vis[v]) {
    dfs(dfs, v);
  }
  vis.assign(n, false);
  int k = 0;
  reverse(vs.begin(), vs.end());
  for (int v : vs) if (!vis[v]) {
    rdfs(rdfs, v, k++);
  }
  return k;
}

struct Edge {
  int id, from, to, c;
  bool operator<(const Edge& rhs) {
    return c < rhs.c;
  }
};

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<Edge> es(m);
  for (int i = 0; i < m; ++i) {
    int u, v, c; cin >> u >> v >> c, --u, --v;
    es[i] = {i, u, v, c};
  }
  sort(rbegin(es), rend(es));
  auto chk = [&](int x) -> bool {
    VV<> g(n);
    for (const auto& e : es) {
      if (e.c <= x) break;
      g[e.from].push_back(e.to);
    }
    V<> comp;
    scc(g, comp);
    return *max_element(begin(comp), end(comp)) == n - 1;
  };
  int ng = -1, ok = 1e9;
  while (ok - ng > 1) {
    int mid = ng + ok >> 1;
    (chk(mid) ? ok : ng) = mid;
  }
  VV<> g(n);
  for (const auto& e : es) {
    if (e.c <= ok) break;
    g[e.from].push_back(e.to);
  }
  V<> comp;
  scc(g, comp);
  V<> res;
  for (const auto& e : es) if (comp[e.from] > comp[e.to]) {
    res.push_back(e.id);
  }
  int k = res.size();
  cout << ok << ' ' << k << '\n';
  for (int i = 0; i < k; ++i) {
    cout << res[i] + 1 << (i != k - 1 ? ' ' : '\n');
  }
}