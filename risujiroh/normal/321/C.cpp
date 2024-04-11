#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int _ = n - 1; _--; ) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<bool> be(n, true);
  vector<int> sz(n), par(n);
  auto cent = [&](int r) -> int {
    vector<int> vs;
    auto dfs = [&](auto&& self, int v, int p) -> void {
      vs.push_back(v);
      par[v] = p;
      sz[v] = 1;
      for (int u : g[v]) {
        if (be[u] and u != p) {
          self(self, u, v);
          sz[v] += sz[u];
        }
      }
    };
    dfs(dfs, r, -1);
    for (int v : vs) {
      bool ok = vs.size() - sz[v] <= vs.size() / 2;
      for (int u : g[v]) {
        if (be[u] and u != par[v]) {
          if (sz[u] > (int)vs.size() / 2) {
            ok = false;
            break;
          }
        }
      }
      if (ok) {
        return v;
      }
    }
    return -1;
  };
  vector<char> res(n);
  auto rec = [&](auto&& self, int v, char ch) -> void {
    int c = cent(v);
    be[c] = false;
    res[c] = ch;
    for (int u : g[c]) {
      if (be[u]) {
        self(self, u, ch + 1);
      }
    }
    be[c] = true;
  };
  rec(rec, 0, 'A');
  for (int v = 0; v < n; ++v) {
    cout << res[v] << " \n"[v == n - 1];
  }
}