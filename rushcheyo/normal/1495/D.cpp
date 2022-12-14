#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;

int n, m;
int d[405][405];
int f[405][405];
int dp[405], inv[405];
int in[405];
int cs[405], cd[405];
vector<int> g[405];
vector<int> go[405][405];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
  }
  for (int i = 1; i <= n; ++i) {
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : g[u]) {
        if (v == i || d[i][v]) {
          continue;
        }
        d[i][v] = d[i][u] + 1;
        go[i][d[i][v]].push_back(v);
        q.push(v);
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      memset(dp, 0, sizeof dp);
      for (int k = 0; k < n; ++k) {
        cs[k] = 1;
        cd[k] = 0;
      }
      dp[i] = 1;
      f[i][j] = 1;
      for (int u = 1; u <= n; ++u) {
        if (u == i || u == j) {
          continue;
        }
        in[u] = 0;
        for (int v : g[u]) {
          in[u] += d[i][u] - d[i][v] == 1 && d[j][u] - d[j][v] == 1;
        }
        if (d[i][u] >= d[i][j]) {
          f[i][j] = 1ll * f[i][j] * in[u] % P;
        } else {
          if (in[u]) {
            cs[d[i][u]] = 1ll * cs[d[i][u]] * in[u] % P;
          } else {
            if (++cd[d[i][u]] == 2) {
              f[i][j] = 0;
            }
          }
        }
      }
      for (int k = 1; k <= d[i][j]; ++k) {
        for (int u : go[i][k]) {
          dp[u] = 0;
          for (int v : g[u]) {
            if (d[i][u] - d[i][v] == 1 && d[j][v] - d[j][u] == 1) {
              dp[u] = (dp[u] + dp[v]) % P;
            }
          }
          if (u != j) {
            dp[u] = 1ll * dp[u] * cs[d[i][u]] % P * inv[in[u]] % P;
          }
        }
      }
      f[j][i] = f[i][j] = 1ll * f[i][j] * dp[j] % P;
    }
  }
  for (int i = 1; i <= n; ++i) {
    f[i][i] = 1;
    for (int u = 1; u <= n; ++u) {
      if (u == i) {
        continue;
      }
      in[u] = 0;
      for (int v : g[u]) {
        in[u] += d[i][u] - d[i][v] == 1;
      }
      f[i][i] = 1ll * f[i][i] * in[u] % P;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      printf("%d ", f[i][j]);
    }
    puts("");
  }
}