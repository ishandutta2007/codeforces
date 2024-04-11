#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector< vector<int> > c(3, vector<int>(n));
  for (auto&& v : c) {
    for (auto&& e : v) {
      cin >> e;
    }
  }
  vector< vector<int> > g(n);
  for (int _ = 0; _ < n - 1; ++_) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int s = -1;
  for (int v = 0; v < n; ++v) {
    if (g[v].size() >= 3) {
      cout << "-1\n";
      return 0;
    }
    if (g[v].size() == 1) {
      s = v;
    }
  }
  vector<int> vs;
  auto dfs = [&](auto& F, int v, int p) -> void {
    vs.push_back(v);
    for (int u : g[v]) {
      if (u != p) {
        F(F, u, v);
      }
    }
  };
  dfs(dfs, s, -1);
  array<int, 3> a{0, 1, 2}, mna;
  long long mn = 1e18;
  do {
    long long crr = 0;
    for (int i = 0; i < n; ++i) {
      crr += c[a[i % 3]][vs[i]];
    }
    if (crr < mn) {
      mn = crr;
      mna = a;
    }
  } while (next_permutation(begin(a), end(a)));
  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    res[vs[i]] = mna[i % 3];
  }
  cout << mn << '\n';
  for (int v = 0; v < n; ++v) {
    cout << res[v] + 1 << " \n"[v == n - 1];
  }
}