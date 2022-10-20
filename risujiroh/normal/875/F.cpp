#include <bits/stdc++.h>
using namespace std;

struct dsu {
  int cc;
  vector<int> p, sz, num;
  dsu(int n = 0) : cc(n), p(n, -1), sz(n, 1), num(n) {}
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
    num[u] += num[v];
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
  vector<int> a(m), b(m), w(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i] >> w[i];
    --a[i], --b[i];
  }
  vector<int> ord(m);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int i, int j) {
    return w[i] > w[j];
  });
  dsu d(n);
  int res = 0;
  for (int i : ord) {
    if (d.same(a[i], b[i])) {
      if (d.num[d.root(a[i])] < d.size(a[i])) {
        ++d.num[d.root(a[i])];
        res += w[i];
      }
    } else {
      if (d.num[d.root(a[i])] + d.num[d.root(b[i])] < d.size(a[i]) + d.size(b[i])) {
        d.unite(a[i], b[i]);
        ++d.num[d.root(a[i])];
        res += w[i];
      }
    }
  }
  cout << res << '\n';
}