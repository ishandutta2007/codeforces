#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  vector<int> goes(m, -1);
  vector<int> offset(m);
  vector<int> from(m);
  vector<int> to(m);
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    from[i] = --v;
    to[i] = --u;
    g[v].emplace_back(u, i);
    g[u].emplace_back(v, i);
  }
  vector<int> pr(n, -1);
  vector<int> dfn(n, -1);
  vector<int> low(n, -1);
  vector<int> val(n, -1);
  int tt = 0;
  function<void(int)> tarjan = [&](int v) {
    dfn[v] = low[v] = tt++;
    for (auto e : g[v]) {
      int u = e.first;
      int w = e.second;
      if (u != pr[v]) {
        if (dfn[u] == -1) {
          pr[u] = v;
          val[u] = w;
          tarjan(u);
          low[v] = min(low[v], low[u]);
        } else {
          low[v] = min(low[v], dfn[u]);
        }
      }
    }
    for (auto e : g[v]) {
      int u = e.first;
      int w = e.second;
      if (pr[u] != v && dfn[v] < dfn[u]) {
        vector<int> cycle;
        cycle.push_back(w);
        for (int t = u; t != v; t = pr[t]) {
          cycle.push_back(val[t]);
        }
        rotate(cycle.begin(), min_element(cycle.begin(), cycle.end()), cycle.end());
        int p = max_element(cycle.begin(), cycle.end()) - cycle.begin();
        bool valid = true;
        for (int i = 0; i < p - 1; ++i) {
          if (cycle[i] > cycle[i + 1]) {
            valid = false;
            break;
          }
        }
        for (int i = p; i < (int) cycle.size() - 1; ++i) {
          if (cycle[i] < cycle[i + 1]) {
            valid = false;
            break;
          }
        }
        if (valid) {
          goes[cycle[p]] = cycle[0];
        }
      }
    }
  };
  tarjan(0);
  vector<int> dp(n, 1);
  for (int i = m - 1; ~i; --i) {
    int v = from[i];
    int u = to[i];
    int w = dp[v] + dp[u] - offset[i];
    dp[v] = dp[u] = w;
    if (goes[i] != -1) {
      offset[goes[i]] = w;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i) {
      cout << " ";
    }
    cout << dp[i] - 1;
  }
  cout << "\n";
  return 0;
}