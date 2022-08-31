#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &w[i]);
  }
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    --x;
    --y;
    adj[x].emplace_back(y, w);
    adj[y].emplace_back(x, w);
  }
  long long answer = 0;
  vector<long long> dp(n);
  function<void(int, int)> dfs = [&](int x, int parent) {
    dp[x] = w[x];
    answer = max(answer, dp[x]);
    for (auto p : adj[x]) {
      if (p.first != parent) {
        dfs(p.first, x);
        answer = max(answer, dp[x] + dp[p.first] - p.second);
        dp[x] = max(dp[x], w[x] + dp[p.first] - p.second);
      }
    }
  };
  dfs(0, -1);
  printf("%lld\n", answer);
  return 0;
}