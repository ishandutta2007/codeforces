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
  UnionFind uf(n);
  while (m--) {
    int k; cin >> k;
    V<> a(k); for (auto&& e : a) cin >> e, --e;
    for (int i = 1; i < k; ++i) uf.unite(a[0], a[i]);
  }
  for (int i = 0; i < n; ++i) {
    cout << uf.size(i) << " \n"[!(n + ~i)];
  }
}