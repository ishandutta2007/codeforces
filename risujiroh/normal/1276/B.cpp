#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> t;
  int num;
  UnionFind(int n) : t(n, -1), num(n) {}
  int find(int v) { return t[v] < 0 ? v : t[v] = find(t[v]); }
  void unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (-t[u] < -t[v]) swap(u, v);
    t[u] += t[v];
    t[v] = u;
    --num;
  }
  int size(int v) { return -t[find(v)]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m, a[2];
    cin >> n >> m >> a[0] >> a[1];
    --a[0], --a[1];
    struct Edge {
      int u, v;
    };
    vector<Edge> es(m);
    for (auto&& e : es) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      e = {u, v};
    }
    vector<int> x(n), y(n);
    for (int k = 0; k < 2; ++k) {
      UnionFind uf(n);
      for (auto e : es) {
        if (e.u == a[k] or e.v == a[k]) {
          continue;
        }
        uf.unite(e.u, e.v);
      }
      for (int v = 0; v < n; ++v) {
        if (k == 0) {
          x[v] = uf.find(v);
        } else {
          y[v] = uf.find(v);
        }
      }
    }
    long long res = (long long)(n - 2) * (n - 3) / 2;
    {
      map<int, long long> mp;
      for (int v = 0; v < n; ++v) {
        if (v == a[0] or v == a[1]) {
          continue;
        }
        ++mp[x[v]];
      }
      for (auto e : mp) {
        res -= e.second * (e.second - 1) / 2;
      }
    }
    {
      map<int, long long> mp;
      for (int v = 0; v < n; ++v) {
        if (v == a[0] or v == a[1]) {
          continue;
        }
        ++mp[y[v]];
      }
      for (auto e : mp) {
        res -= e.second * (e.second - 1) / 2;
      }
    }
    {
      map< pair<int, int>, long long> mp;
      for (int v = 0; v < n; ++v) {
        if (v == a[0] or v == a[1]) {
          continue;
        }
        ++mp[{x[v], y[v]}];
      }
      for (auto e : mp) {
        res += e.second * (e.second - 1) / 2;
      }
    }
    cout << res << '\n';
  }
}