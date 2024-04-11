#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline int mul(int x, int y) {
  return (long long) x * y % md;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> inv2(n + 1);
  inv2[0] = 1;
  for (int i = 1; i <= n; ++i) {
    inv2[i] = mul(inv2[i - 1], md + 1 >> 1);
  }
  vector<vector<int>> dp(n, vector<int>(m + 1));
  vector<int> res(m + 1);
  vector<int> sz(n);
  function<void(int, int)> dfs = [&](int x, int pr) {
    dp[x][0] = 1;
    sz[x] = 1;
    for (auto y : adj[x]) {
      if (y != pr) {
        dfs(y, x);
        for (int i = min(sz[y] - 1, m - 1); ~i; --i) {
          int w = dp[y][i];
          if (!i) {
            w = mul(w, md + 1 - inv2[sz[y]]);
          }
          add(res[i + 1], mul(w, md + 1 - inv2[n - sz[y]]));
          add(dp[y][i + 1], w);
        }
        for (int i = min(sz[x] - 1, m); ~i; --i) {
          for (int j = 1; j <= min(sz[y], m - i); ++j) {
            int w = mul(dp[x][i], dp[y][j]);
            if (i) {
              add(res[i + j], w);
            }
            add(dp[x][i + j], w);
          }
        }
        sz[x] += sz[y];
      }
    }
  };
  dfs(0, -1);
  vector<vector<int>> stir(m + 1, vector<int>(m + 1));
  stir[0][0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= i; ++j) {
      stir[i][j] = stir[i - 1][j - 1];
      add(stir[i][j], mul(stir[i - 1][j], j));
    }
  }
  int ans = 0;
  for (int i = 1, fact = 1; i <= m; ++i) {
    fact = mul(fact, i);
    add(ans, mul(res[i], mul(stir[m][i], fact)));
  }
  for (int i = 1; i <= n; ++i) {
    ans = mul(ans, 2);
  }
  cout << ans << "\n";
  return 0;
}