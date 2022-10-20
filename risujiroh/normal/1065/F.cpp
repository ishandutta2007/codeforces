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

int rec(int v, const VV<>& tree, const V<>& res) {
  if (!tree[v].size()) return res[v];
  int mx = 0;
  for (int w : tree[v]) mx = max(mx, rec(w, tree, res));
  return mx + res[v]; 
}

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<> p(n, -1);
  for (int i = 1; i < n; i++) cin >> p[i], p[i]--;
  VV<> par; assign(par, __lg(n) + 2, n, -1);
  for (int i = 0; i < n; i++) par[0][i] = p[i];
  for (int k = 0; k < __lg(n) + 1; k++) for (int i = 0; i < n; i++) if (par[k][i] != -1) par[k + 1][i] = par[k][par[k][i]];
  auto get_par = [&](int v, int m) {
    int k = 0;
    while (m) {
      if (m & 1) v = par[k][v];
      if (v == -1) break;
      m >>= 1;
      k++;
    }
    return v;
  };
  VV<> ch(n);
  for (int i = 1; i < n; i++) ch[p[i]].push_back(i);
  VV<edge> g(n);
  for (int i = 1; i < n; i++) g[p[i]].emplace_back(i);
  for (int i = 0; i < n; i++) if (!ch[i].size()) {
    if (get_par(i, k) != -1) g[i].emplace_back(get_par(i, k));
    else g[i].emplace_back(0);
  }
  V<> comp;
  int c = scc(g, comp);
  V<> res(c);
  for (int i = 0; i < n; i++) if (!ch[i].size()) res[comp[i]]++;
  VV<> tree(c);
  for (int v = 0; v < n; v++) {
    for (auto&& e : g[v]) if (comp[v] != comp[e.to]) tree[comp[v]].push_back(comp[e.to]);
  }
  for (int v = 0; v < c; v++) {
    sort(tree[v].begin(), tree[v].end());
    tree[v].erase(unique(tree[v].begin(), tree[v].end()), tree[v].end());
  }
  cout << rec(comp[0], tree, res) << '\n';
}