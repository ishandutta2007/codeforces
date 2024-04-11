#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

struct dsu {
  int cc;
  vector<int> p, sz;
  dsu(int n = 0) : cc(n), p(n, -1), sz(n, 1) {}
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
  int n, m;
  cin >> n >> m;
  vector<long long> c(n);
  for (auto&& e : c) {
    cin >> e;
  }
  vector<pair<int, int>> edges(m);
  for (auto&& [u, v] : edges) {
    cin >> u >> v;
    --u, --v;
  }
  dsu d(n);
  vector<set<int>> g(n);
  for (int i = 0; i < m; ++i) {
    auto [u, v] = edges[i];
    if (not d.same(u, v)){
      d.unite(u, v);
      g[u].insert(i);
      g[v].insert(i);
    }
  }
  dsu b(2 * n + 1);
  int x = -1, y = -1, z = -1;
  for (int i = 0; i < m; ++i) {
    auto [u, v] = edges[i];
    if (b.same(u, v)) {
      x = u, y = v, z = i;
    } else {
      b.unite(u, n + v);
      b.unite(v, n + u);
    }
  }
  vector<long long> w(m);
  auto fn = [&] {
    queue<int> que;
    for (int v = 0; v < n; ++v) {
      if (size(g[v]) == 1) {
        que.push(v);
      }
    }
    while (not empty(que)) {
      int v = que.front();
      que.pop();
      assert(size(g[v]) <= 1);
      if (empty(g[v])) {
        continue;
      }
      int id = *begin(g[v]);
      w[id] = c[v];
      int to = v ^ edges[id].first ^ edges[id].second;
      c[to] -= w[id];
      g[v].erase(id);
      g[to].erase(id);
      if (size(g[to]) == 1) {
        que.push(to);
      }
    }
    for (auto e : w) {
      cout << e << '\n';
    }
  };
  for (int v = 0; v < n; ++v) {
    if (not b.same(v, 2 * n) and not b.same(n + v, 2 * n)){
      b.unite(v, 2 * n);
    }
  }
  vector<long long> s(2);
  for (int v = 0; v < n; ++v) {
    s[b.same(v, 2 * n)] += c[v];
  }
  if (x == -1) {
    if (s[0] != s[1]) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      fn();
    }
    exit(0);
  }
  cout << "YES\n";
  if (b.same(x, 2 * n)) {
    w[z] = (s[1] - s[0]) / 2;
  } else {
    w[z] = (s[0] - s[1]) / 2;
  }
  c[x] -= w[z];
  c[y] -= w[z];
  fn();
}