#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> d(n); for (auto&& e : d) cin >> e;
  V<> idx(n);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) { return d[i] > d[j]; });
  VV<> g(2 * n);
  auto add_edge = [&](int u, int v) -> void {
    g[u].push_back(v);
    g[v].push_back(u);
  };
  for (int i = 0; i < n - 1; ++i) {
    add_edge(2 * idx[i], 2 * idx[i + 1]);
  }
  V<> a;
  for (int v : idx) a.push_back(2 * v);
  for (int i = 0; i < n; ++i) {
    int v = idx[i];
    add_edge(2 * v + 1, a[i + d[v] - 1]);
    if (i + d[v] == (int)a.size()) {
      a.push_back(2 * v + 1);
    }
  }
  for (int v = 0; v < 2 * n; ++v) for (int w : g[v]) if (v < w) {
    cout << v + 1 << ' ' << w + 1 << '\n';
  }
}