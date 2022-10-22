#include <bits/stdc++.h>
const int N = 205;
const int Q = 1e9 + 7;
int n, g[N][N];
std::vector<int> e[N];
int f[N], d[N], s[N];
bool vis[N];

int inverse(int x) {
  return x == 1 ? 1 : 1LL * (Q - Q / x) * inverse(Q % x) % Q;
}

void dfs(int x, int fa, int dep) {
  f[x] = fa;
  d[x] = dep;
  s[x] = 1;
  for (auto &y : e[x]) {
    if (y != fa) {
      dfs(y, x, dep + 1);
      s[x] += s[y];
    }
  }
}

void work() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].emplace_back(y);
    e[y].emplace_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    g[i][0] = 1;
    g[0][i] = 0;
  }
  int inv2 = inverse(2);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      g[i][j] = 1LL * (g[i - 1][j] + g[i][j - 1]) * inv2 % Q;
    }
  }

  int res = 0;
  for (int a = 1; a <= n; ++a) {
    dfs(a, 0, 0);
    for (int b = a + 1; b <= n; ++b) {
      int x = b, last = 0;
      int len = d[b];
      while (x) {
        res += 1LL * g[d[x]][len - d[x]] * (s[x] - last) % Q;
        res %= Q;
        last = s[x];
        x = f[x];
      }
    }
  }
  res = 1LL * res * inverse(n) % Q;
  printf("%d\n", res);
}

int main() {
  int T = 1;
  while (T--) {
    work();
  }
  return 0;
}