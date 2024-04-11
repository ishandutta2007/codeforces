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
  V< bitset<40> > g(n);
  for (int _ = 0; _ < m; ++_) {
    int u, v; cin >> u >> v, --u, --v;
    g[u][v] = g[v][u] = 1;
  }
  lint res = 1LL << n;
  { // 0, 2
    lint c = 0;
    if (n <= 20) {
      for (int S = 0; S < 1 << n; ++S) {
        bool ok = true;
        for (int u = 0; u < n; ++u) if (S >> u & 1) for (int v = 0; v < n; ++v) if (S >> v & 1) {
          if (g[u][v]) ok = false;
        }
        c += ok;
      }
    } else {
      int n0 = n / 2, n1 = n - n0;
      V<> dp(1 << n1);
      for (int S = 0; S < 1 << n1; ++S) {
        bool ok = true;
        for (int u = 0; u < n1; ++u) for (int v = 0; v < n1; ++v) if (S >> u & 1 and S >> v & 1) {
          if (g[n0 + u][n0 + v]) ok = false;
        }
        dp[S] = ok;
      }
      for (int i = 0; i < n1; ++i) for (int S = 0; S < 1 << n1; ++S) if (~S >> i & 1) {
        dp[S | 1 << i] += dp[S];
      }
      for (int S = 0; S < 1 << n0; ++S) {
        bool ok = true;
        for (int u = 0; u < n0; ++u) for (int v = 0; v < n0; ++v) if (S >> u & 1 and S >> v & 1) {
          if (g[u][v]) ok = false;
        }
        if (!ok) continue;
        int T = ~(~0U << n1);
        for (int u = 0; u < n0; ++u) if (S >> u & 1) {
          for (int v = 0; v < n1; ++v) if (g[u][n0 + v]) {
            T &= ~(1 << v);
          }
        }
        c += dp[T];
      }
    }
    res -= 2 * c;
  }
  { // 1
    UnionFind uf(n);
    for (int u = 0; u < n; ++u) for (int v = 0; v < n; ++v) if (g[u][v]) {
      uf.unite(u, v);
    }
    set<int> se;
    for (int v = 0; v < n; ++v) {
      se.insert(uf.find(v));
    }
    res -= 1LL << se.size();
  }
  { // 01, 12
    int c = 0;
    for (int v = 0; v < n; ++v) {
      c += !g[v].count();
    }
    res += 2 * (1LL << c);
  }
  { // 02
    UnionFind uf(2 * n);
    for (int u = 0; u < n; ++u) for (int v = 0; v < n; ++v) if (g[u][v]) {
      uf.unite(u, v + n);
      uf.unite(u + n, v);
    }
    bool ok = true;
    for (int v = 0; v < n; ++v) if (uf.same(v, v + n)) {
      ok = false;
      break;
    }
    if (ok) {
      set<int> se;
      for (int v = 0; v < 2 * n; ++v) {
        se.insert(uf.find(v));
      }
      assert(~se.size() & 1);
      res += 1LL << se.size() / 2;
    }
  }
  { // 012
    if (!m) {
      res -= 1LL << n;
    }
  }
  cout << res << '\n';
}