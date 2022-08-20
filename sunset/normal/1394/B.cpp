#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; ++i) {
    int v, u, w;
    cin >> v >> u >> w;
    --v; --u;
    g[v].emplace_back(w, u);
  }
  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end());
  }
  vector<vector<int>> id(k + 1, vector<int>(k + 1));
  int t = 0;
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < i; ++j) {
      id[i][j] = t++;
    }
  }
  vector<long long> cant(t);
  vector<long long> clique(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (int) g[i].size(); ++j) {
      if (clique[g[i][j].second] >> id[g[i].size()][j] & 1) {
        cant[id[g[i].size()][j]] = true;
      } else {
        clique[g[i][j].second] |= 1ll << id[g[i].size()][j];
      }
    }
  }
  vector<long long> ban(t);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < t; ++j) {
      if (clique[i] >> j & 1) {
        ban[j] |= clique[i];
      }
    }
  }
  long long take = 0;
  int ans = 0;
  function<void(int)> dfs = [&](int p) {
    if (p > k) {
      bool valid = true;
      for (int i = 0; i < t; ++i) {
        if ((take >> i & 1) && __builtin_popcountll(take & ban[i]) > 1) {
          valid = false;
        }
      }
      if (valid) {
        ++ans;
      }
    } else {
      for (int i = 0; i < p; ++i) {
        if (cant[id[p][i]]) {
          continue;
        }
        take ^= 1ll << id[p][i];
        dfs(p + 1);
        take ^= 1ll << id[p][i];
      }
    }
  };
  dfs(1);
  cout << ans << "\n";
  return 0;
}