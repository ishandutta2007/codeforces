#include <bits/stdc++.h>
using namespace std;

struct dsu {
  int cc;
  vector<int> p, sz;
  dsu(int n) : cc(n), p(n, -1), sz(n, 1) {}
  int root(int v) const {
    while (p[v] != -1) v = p[v];
    return v;
  }
  bool unite(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return false;
    --cc;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    return true;
  }
  bool same(int u, int v) const { return root(u) == root(v); }
  int size(int v) const { return sz[root(v)]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int m, n;
  cin >> m >> n;
  vector<int> r(m);
  for (auto&& e : r) {
    cin >> e;
  }
  vector<vector<int>> es(m);
  for (int v = 0; v < n; ++v) {
    int d;
    cin >> d;
    while (d--) {
      int id;
      cin >> id;
      --id;
      es[id].push_back(v);
    }
  }
  dsu d(2 * n);
  for (int id = 0; id < m; ++id) {
    assert(es[id].size() == 2);
    if (r[id] == 0) {
      d.unite(es[id][0], n + es[id][1]);
      d.unite(n + es[id][0], es[id][1]);
    } else {
      d.unite(es[id][0], es[id][1]);
      d.unite(n + es[id][0], n + es[id][1]);
    }
  }
  for (int v = 0; v < n; ++v) {
    if (d.same(v, n + v)) {
      cout << "NO\n";
      exit(0);
    }
  }
  cout << "YES\n";
}