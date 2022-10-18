#line 1 "c.cpp"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF_LL = 1LL << 61;

template <typename T>
void chmin(T& var, T x) { var = min(var, x); }
template <typename T>
void chmax(T& var, T x) { var = max(var, x); }

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);

  int n; ll b; cin >> n >> b;
  vector<ll> d(n), c(n);
  vector<vector<int>> graph(n);
  cin >> c[0] >> d[0];
  for (int i = 1; i < n; i++) {
    int x;
    cin >> c[i] >> d[i] >> x;
    x--;
    graph[x].emplace_back(i);
  }

  // dp[0][v][i]: vv
  // dp[1][v][i]: vv
  vector dp(2, vector<vector<ll>>(n));

  auto dfs = [&](auto f, int v)->void{
    // dp[_][v].size(): +1
    dp[0][v] = {0, c[v]};
    dp[1][v] = {INF_LL, c[v] - d[v]};
    for (auto u : graph[v]) {
      f(f, u);  // 

      vector dp2(2, vector<ll>(dp[0][v].size() + dp[0][u].size() - 1, INF_LL));

      for (int i = 0; i < dp[0][v].size(); i++) {
        for (int j = 0; j < dp[0][u].size(); j++) {
          chmin(dp2[0][i+j], dp[0][v][i] + dp[0][u][j]);
          chmin(dp2[1][i+j], dp[1][v][i] + min(dp[0][u][j], dp[1][u][j]));
        }
      }

      dp[0][v] = move(dp2[0]);
      dp[1][v] = move(dp2[1]);
    }
  };
  dfs(dfs, 0);

  int res = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < dp[i][0].size(); j++)
      if (dp[i][0][j] <= b) chmax(res, j);

  cout << res << "\n";
}