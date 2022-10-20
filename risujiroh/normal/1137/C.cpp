#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int scc(const VV<>& g, V<>& comp) {
  int n = g.size();
  VV<> rg(n);
  for (int v = 0; v < n; v++) for (int w : g[v]) {
    rg[w].push_back(v);
  }
  V<> vs;
  V<bool> vis(n);
  comp.resize(n);
  auto dfs = [&](const auto& dfs, int v) -> void {
    vis[v] = true;
    for (int w : g[v]) if (!vis[w]) {
      dfs(dfs, w);
    }
    vs.push_back(v);
  };
  auto rdfs = [&](const auto& rdfs, int v, int k) -> void {
    vis[v] = true;
    comp[v] = k;
    for (int w : rg[v]) if (!vis[w]) {
      rdfs(rdfs, w, k);
    }
  };
  for (int v = 0; v < n; v++) if (!vis[v]) {
    dfs(dfs, v);
  }
  vis.assign(n, false);
  int k = 0;
  reverse(begin(vs), end(vs));
  for (int v : vs) if (!vis[v]) {
    rdfs(rdfs, v, k++);
  }
  return k;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int k, s;
  V<> a;
  VV<> h;
  {
    int n, m, d; cin >> n >> m >> d;
    VV<> g(n * d);
    while (m--) {
      int u, v; cin >> u >> v, --u, --v;
      for (int i = 0; i < d; ++i) {
        g[u * d + i].push_back(v * d + (i + 1) % d);
      }
    }
    V<> comp;
    k = scc(g, comp);
    s = comp[0];
    h.resize(k - s);
    for (int v = 0; v < n; ++v) for (int i = 0; i < d; ++i) {
      int x = comp[v * d + i] - s;
      if (x < 0) continue;
      for (int w : g[v * d + i]) {
        int y = comp[w] - s;
        if (y < 0) continue;
        if (x == y) continue;
        h[x].push_back(y);
      }
    }
    for (int i = 0; i < k - s; ++i) {
      sort(begin(h[i]), end(h[i]));
      h[i].erase(unique(begin(h[i]), end(h[i])), end(h[i]));
    }
    a.resize(k - s);
    for (int v = 0; v < n; ++v) {
      string str; cin >> str;
      set<int> se;
      for (int i = 0; i < d; ++i) {
        int x = comp[v * d + i] - s;
        if (x < 0) continue;
        if (str[i] == '1') {
          if (se.count(x)) continue;
          se.insert(x);
          ++a[x];
        }
      }
    }
  }

  V<> dp(k - s, -1e9);
  dp[0] = 0;
  // int res = 0;
  // for (int i = 0; i < k - s; ++i) {
  //   for (int j : h[i]) {
  //     dp[j] = max(dp[j], dp[i] + a[i]);
  //   }
  //   res = max(res, dp[i] + a[i]);
  // }
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int i = que.front(); que.pop();
    for (int j : h[i]) {
      dp[j] = max(dp[j], dp[i] + a[i]);
      que.push(j);
    }
  }
  for (int i = 0; i < k - s; ++i) dp[i] += a[i];
  cout << *max_element(begin(dp), end(dp)) << '\n';
}