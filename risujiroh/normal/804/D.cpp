#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << '\t' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
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
  cout << fixed << setprecision(20);
  int n, m, q;
  cin >> n >> m >> q;
  dsu d(n);
  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    d.unite(u, v);
  }
  vector<vector<int>> vs(n);
  for (int v = 0; v < n; ++v) {
    vs[d.root(v)].push_back(v);
  }
  vector<int> dist(n);
  auto dfs = [&](auto&& self, int v, int p) -> void {
    for (int u : g[v]) {
      if (u != p) {
        dist[u] = dist[v] + 1;
        self(self, u, v);
      }
    }
  };
  vector<int> diam(n, -1), mx(n, -1);
  vector<vector<int>> c(n);
  vector<vector<long long>> cum(n), cumi(n);
  for (int v = 0; v < n; ++v) {
    int p = d.root(v);
    if (diam[p] != -1) {
      continue;
    }
    dist[v] = 0;
    dfs(dfs, v, -1);
    int x = -1;
    for (int u : vs[p]) {
      if (x == -1 or dist[u] > dist[x]) {
        x = u;
      }
    }
    dist[x] = 0;
    dfs(dfs, x, -1);
    int y = -1;
    for (int u : vs[p]) {
      mx[u] = max(mx[u], dist[u]);
      if (y == -1 or dist[u] > dist[y]) {
        y = u;
      }
    }
    diam[p] = dist[y];
    dist[y] = 0;
    dfs(dfs, y, -1);
    int sz = d.size(v);
    c[p].resize(sz);
    for (int u : vs[p]) {
      mx[u] = max(mx[u], dist[u]);
      ++c[p][mx[u]];
    }
    cum[p].resize(sz + 1), cumi[p].resize(sz + 1);
    for (int i = sz; i--; ) {
      cum[p][i] = c[p][i] + cum[p][i + 1];
      cumi[p][i] = (long long)c[p][i] * i + cumi[p][i + 1];
    }
  }
  DEBUG(diam);
  DEBUG(mx);
  DEBUG(vs);
  DEBUG(c);
  map<pair<int, int>, double> mp;
  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    u = d.root(u), v = d.root(v);
    if (u == v) {
      cout << "-1\n";
      continue;
    }
    if (mp.count({u, v})) {
      cout << mp[{u, v}] << '\n';
      continue;
    }
    if (d.size(u) < d.size(v)) {
      swap(u, v);
    }
    int nu = d.size(u), nv = d.size(v), md = max(diam[u], diam[v]);
    DEBUG(nu, nv, md);
    DEBUG(c[u]);
    DEBUG(cum[u]);
    DEBUG(cumi[u]);
    double res = 0;
    for (int j = 0; j < nv; ++j) {
      double cur = 0;
      if (md - j > 0) {
        cur += (double)md * (cum[u][0] - cum[u][md - j]);
      }
      cur += cumi[u][max(md - j, 0)] + (double)(j + 1) * cum[u][max(md - j, 0)];
      cur *= c[d.root(v)][j];
      cur /= nu;
      cur /= nv;
      res += cur;
    }
    mp[{u, v}] = mp[{v, u}] = res;
    cout << res << '\n';
  }
}