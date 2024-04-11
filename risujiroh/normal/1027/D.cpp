#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

struct edge { int to; edge(int to) : to(to) {} };

int scc(const VV<edge>& g, V<>& comp) {
  int n = g.size();
  VV<edge> rg(n); for (int i = 0; i < n; i++) for (auto&& e : g[i]) rg[e.to].push_back(i);
  V<> vs;
  V<bool> vis(n);
  comp.resize(n);

  function<void(int)> dfs = [&](int v) {
    vis[v] = true;
    for (auto&& e : g[v]) if (!vis[e.to]) dfs(e.to);
    vs.push_back(v);
  };

  function<void(int, int)> rdfs = [&](int v, int k) {
    vis[v] = true;
    comp[v] = k;
    for (auto&& e : rg[v]) if (!vis[e.to]) rdfs(e.to, k);
  };

  for (int v = 0; v < n; v++) if (!vis[v]) dfs(v);
  vis.assign(n, false);
  int k = 0;
  reverse(vs.begin(), vs.end());
  for (auto&& v : vs) if (!vis[v]) rdfs(v, k++);
  return k;
}

struct QF {
  V<> par;
  V< set<int> > chi;

  QF(int n) {
    par.resize(n);
    chi.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i;
      chi[i].insert(i);
    }
  }

  bool same(int a, int b) { return par[a] == par[b]; }

  int size(int a) { return chi[par[a]].size(); }

  void unite(int a, int b) {
    if (same(a, b)) return;
    if (size(a) < size(b)) swap(a, b);
    a = par[a], b = par[b];
    for (int i : chi[b]) par[i] = a;
    chi[a].insert(chi[b].begin(), chi[b].end());
    chi[b].clear();
  }
};

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> c(n); for (int i = 0; i < n; i++) cin >> c[i];
  V<> a(n); for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
  VV<edge> g(n);
  for (int i = 0; i < n; i++) g[i].emplace_back(a[i]);
  V<> comp;
  int k = scc(g, comp);
  QF qf(k);
  for (int i = 0; i < n; i++) qf.unite(comp[i], comp[a[i]]);
  V<> p;
  for (int i = 0; i < k; i++) if (qf.chi[i].size()) {
    p.push_back(*(--qf.chi[i].end()));
  }
  VV<> c2c(k);
  for (int i = 0; i < n; i++) c2c[comp[i]].push_back(c[i]);
  for (auto&& v : c2c) sort(v.begin(), v.end());
  int res = 0;
  for (auto&& i : p) res += c2c[i][0];
  cout << res << '\n';
}