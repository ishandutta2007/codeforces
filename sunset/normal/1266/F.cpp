#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    cin >> v >> u;
    --v; --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  vector<int> pr(n, -1);
  vector<int> foo(n);
  vector<int> bar(n);
  vector<int> baz(n);
  function<void(int)> dfs_up = [&](int v) {
    for (int u : g[v]) {
      if (u != pr[v]) {
        pr[u] = v;
        dfs_up(u);
        bar[v] = max(bar[v], foo[u] + 1);
        if (foo[v] < bar[v]) {
          swap(foo[v], bar[v]);
        }
      }
    }
  };
  function<void(int)> dfs_down = [&](int v) {
    for (int u : g[v]) {
      if (u != pr[v]) {
        baz[u] = 1 + max(baz[v], foo[u] + 1 == foo[v] ? bar[v] : foo[v]);
        dfs_down(u);
      }
    }
  };
  dfs_up(0);
  dfs_down(0);
  vector<int> ans(n * 2 + 1, 1);
  vector<vector<int>> d(n);
  for (int v = 0; v < n; ++v) {
    vector<int> ds;
    for (int u : g[v]) {
      if (u == pr[v]) {
        ds.push_back(baz[v]);
      } else {
        ds.push_back(foo[u] + 1);
      }
    }
    sort(ds.begin(), ds.end(), greater<int>());
    for (int i = 1; i < (int) ds.size(); ++i) {
      ans[2 * ds[i]] = max(ans[2 * ds[i]], i + 1);
      ans[2 * min(ds[i] + 1, ds[i - 1]) - 1] = max(ans[2 * min(ds[i] + 1, ds[i - 1]) - 1], i + 1);
    }
    d[v] = ds;
  }
  vector<int> ord(n);
  for (int i = 0; i < n; ++i) {
    ord[i] = i;
  }
  sort(ord.begin(), ord.end(), [&](int v, int u) { return g[v].size() > g[u].size() || (g[v].size() == g[u].size() && v < u); });
  for (int v : ord) {
    vector<pair<int, int>> cut;
    for (int u : g[v]) {
      if (g[v].size() > g[u].size() || (g[v].size() == g[u].size() && v < u)) {
        for (int i = 1; i < (int) d[u].size(); ++i) {
          cut.emplace_back(d[u][i], i);
        }
      }
    }
    sort(cut.begin(), cut.end(), greater<pair<int, int>>());
    for (int i = 1; i < (int) cut.size(); ++i) {
      cut[i].second = max(cut[i].second, cut[i - 1].second);
    }
    int j = 0;
    for (int i = 1; i < (int) d[v].size(); ++i) {
      while (j < (int) cut.size() && cut[j].first >= d[v][i]) {
        if (i > 1) {
          ans[2 * cut[j].first] = max(ans[2 * cut[j].first], i - 1 + cut[j].second);
        }
        ++j;
      }
      if (j) {
        ans[2 * d[v][i]] = max(ans[2 * d[v][i]], i + cut[j - 1].second);
      }
    }
    while (j < (int) cut.size()) {
      if ((int) d[v].size() > 1) {
        ans[2 * cut[j].first] = max(ans[2 * cut[j].first], (int) d[v].size() - 1 + cut[j].second);
      }
      ++j;
    }
  }
  for (int i = n - 2; i; --i) {
    ans[i] = max(ans[i], ans[i + 2]);
  }
  for (int i = 0; i < n; ++i) {
    ans[1] = max(ans[1], (int) g[i].size() + 1);
  }
  for (int i = 1; i <= n; ++i) {
    if (i != 1) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
  return 0;
}