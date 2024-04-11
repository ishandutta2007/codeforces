#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> t;
  UnionFind(int n) : t(n, -1) {}
  int find(int v) { return t[v] < 0 ? v : t[v] = find(t[v]); }
  void unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (-t[u] < -t[v]) swap(u, v);
    t[u] += t[v];
    t[v] = u;
  }
  int size(int v) { return -t[find(v)]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n - 1);
  for (auto&& e : a) {
    cin >> e;
  }
  cout << a[0] << '\n';
  UnionFind uf(n + 1);
  int v = n;
  for (int i = 0; i < n - 1; ++i) {
    if (i + 1 < n - 1 and uf.find(a[i]) != uf.find(a[i + 1])) {
      cout << a[i] << ' ' << a[i + 1] << '\n';
      uf.unite(a[i], a[i + 1]);
    } else {
      while (uf.find(a[i]) == uf.find(v)) {
        --v;
      }
      uf.unite(a[i], v);
      cout << a[i] << ' ' << v << '\n';
    }
  }
}