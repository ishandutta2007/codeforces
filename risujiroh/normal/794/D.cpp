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
  vector<vector<int>> g(n);
  vector<pair<int, int>> es(m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    es[i] = minmax({u, v});
  }
  sort(begin(es), end(es));
  auto [a, b] = [&] {
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < y; ++x) {
        if (binary_search(begin(es), end(es), make_pair(x, y))) continue;
        vector<int> d(n, -1), prv(n, -1);
        queue<int> que;
        d[x] = 0;
        que.push(x);
        while (not empty(que)) {
          int v = que.front();
          que.pop();
          for (int to : g[v]) {
            if (d[to] != -1) continue;
            d[to] = d[v] + 1;
            prv[to] = v;
            que.push(to);
          }
        }
        assert(d[y] >= 2);
        while (d[y] > 2) {
          y = prv[y];
        }
        return minmax({x, y});
      }
    }
    return make_pair(-1, -1);
  }();
  if (a == -1) {
    cout << "YES\n";
    for (int v = 0; v < n; ++v) {
      cout << 1 << " \n"[v == n - 1];
    }
    exit(0);
  }
  DEBUG(a, b);
  vector<int> d(n, -1);
  queue<int> que;
  for (int v = 0; v < n; ++v) {
    if (v == a or v == b) continue;
    if (not binary_search(begin(es), end(es), minmax({v, a}))) continue;
    if (not binary_search(begin(es), end(es), minmax({v, b}))) continue;
    d[v] = 0;
    que.push(v);
  }
  while (not empty(que)) {
    int v = que.front();
    que.pop();
    for (int to : g[v]) {
      if (d[to] != -1) continue;
      d[to] = d[v] + 1;
      que.push(to);
    }
  }
  dsu dsu(n);
  for (auto [u, v] : es) {
    if (d[u] == 0 or d[v] == 0) continue;
    dsu.unite(u, v);
  }
  if (dsu.same(a, b)) {
    cout << "NO\n";
    exit(0);
  }
  vector<int> x(n, n), cnt(2 * n);
  for (int v = 0; v < n; ++v) {
    if (dsu.same(v, a)) {
      x[v] += d[v];
    }
    if (dsu.same(v, b)) {
      x[v] -= d[v];
    }
    ++cnt[x[v]];
  }
  DEBUG(x);
  long long sum = 0;
  for (int i = 1; i < 2 * n; ++i) {
    sum += (long long)cnt[i] * (cnt[i] - 1) / 2;
    sum += (long long)cnt[i - 1] * cnt[i];
  }
  if (sum != m) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";
  for (int v = 0; v < n; ++v) {
    cout << x[v] << " \n"[v == n - 1];
  }
}