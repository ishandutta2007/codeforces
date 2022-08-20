#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 4005;
const int M = 80;
const int mod = 998244353;

int binom[M][M];

int add(int x, int y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0) {
    x += mod;
  }
  return x;
}

int mul(int x, int y) {
  return (ll)x * y % mod;
}

struct tree_t {
  int n, m, dp[N][M], up[N][M], sum[N][M], down[N][M];
  vector<int> adj[N];

  void dpu(int x, int parent) {
    for (auto y : adj[x]) {
      if (y != parent) {
        dpu(y, x);
        for (int i = 0; i <= m; i += 2) {
          sum[x][i] = add(sum[x][i], up[y][i]);
        }
      }
    }
    up[x][0] = 1;
    for (int i = 2; i <= m; i += 2) {
      for (int j = 0; j <= i - 2; j += 2) {
        up[x][i] = add(up[x][i], mul(sum[x][j], up[x][i - j - 2]));
      }
    }
  }

  void dpd(int x, int parent) {
    for (int i = 0; i <= m; i += 2) {
      sum[x][i] = add(sum[x][i], down[x][i]);
    }
    dp[x][0] = 1;
    for (int i = 2; i <= m; i += 2) {
      for (int j = 0; j <= i - 2; j += 2) {
        dp[x][i] = add(dp[x][i], mul(sum[x][j], dp[x][i - j - 2]));
      }
    }
    for (auto y : adj[x]) {
      if (y != parent) {
        for (int i = 0; i <= m; i += 2) {
          sum[x][i] = sub(sum[x][i], up[y][i]);
        }
        down[y][0] = 1;
        for (int i = 2; i <= m; i += 2) {
          for (int j = 0; j <= i - 2; j += 2) {
            down[y][i] = add(down[y][i], mul(sum[x][j], down[y][i - j - 2]));
          }
        }
        for (int i = 0; i <= m; i += 2) {
          sum[x][i] = add(sum[x][i], up[y][i]);
        }
        dpd(y, x);
      }
    }
  }

  void init() {
    for (int i = 1; i < n; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    dpu(1, 0);
    dpd(1, 0);
  }
} p, q;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int m;
  scanf("%d %d %d", &p.n, &q.n, &m);
  p.m = q.m = m;
  if (m & 1) {
    puts("0");
    return 0;
  }
  p.init();
  q.init();
  for (int i = 0; i <= m; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      binom[i][j] = add(binom[i - 1][j], binom[i - 1][j - 1]);
    }
  }
  int answer = 0;
  for (int i = 0; i <= m; i += 2) {
    int x = 0, y = 0;
    for (int j = 1; j <= p.n; ++j) {
      x = add(x, p.dp[j][i]);
    }
    for (int j = 1; j <= q.n; ++j) {
      y = add(y, q.dp[j][m - i]);
    }
    answer = add(answer, mul(binom[m][i], mul(x, y)));
  }
  printf("%d\n", answer);
  return 0;
}