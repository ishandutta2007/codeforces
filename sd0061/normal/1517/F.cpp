#include "bits/stdc++.h"

using int64 = long long;
const int N = 305;
const int Q = 998244353;

inline void add(int &x, int y) {
  x += y;
  if (x >= Q) x -= Q;
}

int n, dep[N];
std::vector<int> e[N];
int f[N][N];  // x , y : max uncovered depth
int g[N][N];  // x , y : min dominator depth

void dfs(int x, int fa, int K) {
  dep[x] = 0;

  for (auto &y : e[x]) {
    if (y == fa) {
      continue;
    }
    dfs(y, x, K);
  }

  static int nf[2][N];
  static int ng[2][N];
  int cur = 0, nxt = 1;
  memset(nf[cur], 0, sizeof(nf[cur]));
  memset(ng[cur], 0, sizeof(ng[cur]));
  nf[cur][0] = 1;
  ng[cur][0] = 1;

  for (auto &y : e[x]) {
    if (y == fa) {
      continue;
    }
    memset(nf[nxt], 0, sizeof(nf[nxt]));
    memset(ng[nxt], 0, sizeof(ng[nxt]));
    for (int i = 0; i <= dep[x]; ++i) {
      if (nf[cur][i]) {
        for (int j = 0; j <= dep[y]; ++j) {
          int depth = std::max(i, j + 1);
          if (depth < K) {
            add(nf[nxt][depth], (int64)nf[cur][i] * f[y][j] % Q);
          }
        }
        for (int j = 0; j <= dep[y]; ++j) {
          if (K >= j + 1 + i) {
            add(ng[nxt][j + 1], (int64)nf[cur][i] * g[y][j] % Q);
          } else {
            add(nf[nxt][i], (int64)nf[cur][i] * g[y][j] % Q);
          }
        }
      }
    }
    for (int i = 0; i <= dep[x]; ++i) {
      if (ng[cur][i] > 0) {
        for (int j = 0; j <= dep[y]; ++j) {
          if (K >= i + j + 1) {
            add(ng[nxt][i], (int64)ng[cur][i] * f[y][j] % Q);
          } else {
            add(nf[nxt][j + 1], (int64)ng[cur][i] * f[y][j] % Q);
          }
        }
        for (int j = 0; j <= dep[y]; ++j) {
          int depth = std::min(i, j + 1);
          add(ng[nxt][depth], (int64)ng[cur][i] * g[y][j] % Q);
        }
      }
    }
    std::swap(cur, nxt);
    dep[x] = std::max(dep[x], dep[y] + 1);
  }

  for (int i = 0; i <= dep[x]; ++i) {
    f[x][i] = nf[cur][i];
    g[x][i] = ng[cur][i];
  }
  // printf("=== %d\n", x);
  // for (int i = 0; i <= dep[x]; ++i) {
  //   printf("%d ", f[x][i]);
  // }
  // puts("");
  // for (int i = 0; i <= K; ++i) {
  //   printf("%d ", g[x][i]);
  // }
  // puts("");
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x = i, y = i + 1;
    scanf("%d%d", &x, &y);
    e[x].emplace_back(y);
    e[y].emplace_back(x);
  }
  int res = Q - 1, pow2 = 1, inv = (Q + 1) / 2, inv2 = 1;
  for (int i = 1; i <= n; ++i) {
    add(pow2, pow2);
    inv2 = (int64)inv2 * inv % Q;
  }
  for (int i = 1; i <= n; ++i) {
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    dfs(1, 0, i);
    add(res, pow2);
    for (int j = 0; j <= dep[1]; ++j) {
      add(res, Q - g[1][j]);
    }
    // std::cout << ": " << i << ' ' << res << std::endl;
  }
  printf("%d\n", (int)((int64)res * inv2 % Q));
}