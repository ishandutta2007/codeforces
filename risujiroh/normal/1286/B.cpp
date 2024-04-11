#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> par(n), c(n);
  vector<vector<int>> ch(n);
  int r = -1;
  for (int v = 0; v < n; ++v) {
    cin >> par[v] >> c[v];
    --par[v];
    if (par[v] != -1) {
      ch[par[v]].push_back(v);
    } else {
      r = v;
    }
  }
  vector<int> sz(n), res(n);
  auto add = [&](auto&& self, int v, int x) -> void {
    res[v] += x;
    for (int u : ch[v]) {
      self(self, u, x);
    }
  };
  auto add1 = [&](auto&& self, int v, int th) -> void {
    if (res[v] >= th) {
      ++res[v];
    }
    for (int u : ch[v]) {
      self(self, u, th);
    }
  };
  auto dfs = [&](auto&& self, int v) -> void {
    sz[v] = 1;
    for (int u : ch[v]) {
      self(self, u);
      sz[v] += sz[u];
    }
    if (c[v] >= sz[v]) {
      cout << "NO\n";
      exit(0);
    }
    int x = 0;
    for (int u : ch[v]) {
      add(add, u, x);
      x += sz[u];
    }
    res[v] = c[v];
    for (int u : ch[v]) {
      add1(add1, u, res[v]);
    }
  };
  dfs(dfs, r);
  cout << "YES\n";
  for (int v = 0; v < n; ++v) {
    cout << res[v] + 1 << " \n"[v == n - 1];
  }
}