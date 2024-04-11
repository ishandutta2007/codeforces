#include <bits/stdc++.h>
using namespace std;

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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    dsu d(n);
    for (int i = 0; i < n; ++i) {
      d.unite(i, n - i - 1);
      if (i + k < n) {
        d.unite(i, i + k);
      }
    }
    vector<string> t(n);
    for (int i = 0; i < n; ++i) {
      t[d.root(i)] += s[i];
    }
    int res = n;
    for (auto&& e : t) {
      vector<int> cnt(26);
      for (char c : e) {
        ++cnt[c - 'a'];
      }
      res -= *max_element(begin(cnt), end(cnt));
    }
    cout << res << '\n';
  }
}