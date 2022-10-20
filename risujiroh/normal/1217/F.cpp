#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct UnionFind {
  const int n;
  V<> t; // root ? -sz : par
  UnionFind(int n) : n(n), t(n, -1) {}
  int find(int v) { return t[v] < 0 ? v : t[v] = find(t[v]); }
  void unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (-t[u] < -t[v]) swap(u, v);
    t[u] += t[v];
    t[v] = u;
  }
  bool same(int u, int v) { return find(u) == find(v); }
  int size(int v) { return -t[find(v)]; }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> t(m), x(m), y(m); 
  for (int i = 0; i < m; ++i) cin >> t[i] >> x[i] >> y[i], --x[i], --y[i];
  V< set<int> > g(n);
  int last = 0;
  for (int s = 0; s < m; s += 2048) {
    set< pair<int, int> > se;
    for (int i = s; i < min(s + 2048, m); ++i) if (t[i] == 1) {
      se.emplace(x[i], y[i]);
      se.emplace(y[i], x[i]);
      se.emplace((x[i] + 1) % n, (y[i] + 1) % n);
      se.emplace((y[i] + 1) % n, (x[i] + 1) % n);
    }
    V< set<int> > h(n);
    UnionFind uf(n);
    for (int v = 0; v < n; ++v) for (int w : g[v]) {
      if (se.count({v, w})) continue;
      uf.unite(v, w);
    }
    for (int v = 0; v < n; ++v) for (int w : g[v]) {
      if (se.count({v, w})) {
        int p = uf.find(v), q = uf.find(w);
        h[p].insert(q);
        h[q].insert(p);
      }
    }
    
    for (int i = s; i < min(s + 2048, m); ++i) {
      x[i] = (x[i] + last) % n;
      y[i] = (y[i] + last) % n;
      if (t[i] == 1) {
        int p = uf.find(x[i]), q = uf.find(y[i]);
        if (g[x[i]].count(y[i])) {
          g[x[i]].erase(y[i]);
          g[y[i]].erase(x[i]);
          h[p].erase(q);
          h[q].erase(p);
        } else {
          g[x[i]].insert(y[i]);
          g[y[i]].insert(x[i]);
          h[p].insert(q);
          h[q].insert(p);
        }
      } else {
        bool res = false;
        if (uf.same(x[i], y[i])) {
          res = true;
        } else {
          set<int> vis;
          auto dfs = [&](const auto& dfs, int v) -> bool {
            if (v == uf.find(y[i])) return true;
            vis.insert(v);
            for (int w : h[v]) if (!vis.count(w)) {
              if (dfs(dfs, w)) return true;
            }
            return false;
          };
          res = dfs(dfs, uf.find(x[i]));
        }
        cout << res;
        last = res;
      }
    }
  }
  cout << '\n';
}