#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct UnionFind {
  const int n;
  V<> t; // root ? -sz : par
  V< set<int> > se;
  UnionFind(int n) : n(n), t(n, -1), se(n) {}
  int find(int v) { return t[v] < 0 ? v : t[v] = find(t[v]); }
  void unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (-t[u] < -t[v]) swap(u, v);
    t[u] += t[v];
    t[v] = u;
    se[u].insert(begin(se[v]), end(se[v]));
    set<int>().swap(se[v]);
  }
  bool same(int u, int v) { return find(u) == find(v); }
  int size(int v) { return -t[find(v)]; }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m, k, q; cin >> n >> m >> k >> q;
  UnionFind uf(n + 2 * (m + q));
  int p = n;
  map< pair<int, int>, int> mp;
  auto add_edge = [&](int u, int v, int c) -> void {
    uf.se[uf.find(u)].insert(v);
    uf.se[uf.find(v)].insert(u);
    if (!mp.count({u, c})) mp[{u, c}] = p++;
    uf.unite(mp[{u, c}], v);
    if (!mp.count({v, c})) mp[{v, c}] = p++;
    uf.unite(mp[{v, c}], u);
  };
  while (m--) {
    int u, v, c; cin >> u >> v >> c, --u, --v, --c;
    add_edge(u, v, c);
  }
  while (q--) {
    char c; cin >> c;
    if (c == '+') {
      int u, v, c; cin >> u >> v >> c, --u, --v, --c;
      add_edge(u, v, c);
    } else {
      int u, v; cin >> u >> v, --u, --v;
      [&] {
        if (uf.same(u, v)) {
          cout << "Yes" << '\n';
          return;
        }
        if (uf.se[uf.find(u)].count(v)) {
          cout << "Yes" << '\n';
          return;
        }
        cout << "No" << '\n';
      }();
    }
  }
}