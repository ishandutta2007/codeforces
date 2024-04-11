#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<> g(n);
  while (m--) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  lint res = 0;
  VV<> a(n);
  for (int v = 0; v < n; ++v) {
    sort(begin(g[v]), end(g[v]));
    lint l = lower_bound(begin(g[v]), end(g[v]), v) - begin(g[v]);
    lint u = end(g[v]) - upper_bound(begin(g[v]), end(g[v]), v);
    res += l * u;
    for (int u : g[v]) if (u > v) {
      a[v].push_back(u);
    }
  }
  cout << res << '\n';

  int q; cin >> q;
  for (int i = 0; i < q; ++i) {
    int v; cin >> v, --v;
    for (int u : a[v]) {
      res -= (int)g[v].size() - (int)a[v].size();
      res -= (int)a[u].size();
      a[u].push_back(v);
      res += (int)g[u].size() - (int)a[u].size();
    }
    V<>().swap(a[v]);
    cout << res << '\n';
  }
}