#include <bits/stdc++.h>
using int64 = long long;
const int N = 100005;
const int Q = 998244353;
int n, m, l[N], r[N];
int f[2][N];

inline void add(int &A, int B) {
  A += B;
  if (A >= Q) {
    A -= Q;
  }
}

bool v[N];
int prime[N], tot;
int mu[N];
void init(int n) {
  int i, j, x;
  mu[1] = 1;
  for (i = 2; i <= n; ++i) {
    if (!v[i]) {
      prime[tot++] = i;
      mu[i] = -1;
    }
    for (j = 0; j < tot; ++j) {
      x = i * prime[j];
      if (x > n)
        break;
      v[x] = 1;
      if (i % prime[j] == 0) {
        mu[x] = 0;
        break;
      } else {
        mu[x] = -mu[i];
      }
    }
  }
}

void work() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", l + i, r + i);
  }
  init(m);
  int res = 0;
  for (int d = 1; d <= m; ++d) {
    if (mu[d] == 0) {
      continue;
    }
    int K = m / d;
    int cur = 0, nxt = 1;
    memset(f[cur], 0, sizeof(int) * (K + 1));
    f[cur][0] = 1;
    for (int i = 0; i < n; ++i) {
      memset(f[nxt], 0, sizeof(int) * (K + 1));
      int L = (l[i] + d - 1) / d;
      int R = r[i] / d;
      for (int j = 0; j <= K; ++j) {
        if (j + L <= K) {
          add(f[nxt][j + L], f[cur][j]);
        }
        if (j + R + 1 <= K) {
          add(f[nxt][j + R + 1], Q - f[cur][j]);
        }
      }
      for (int j = 1; j <= K; ++j) {
        add(f[nxt][j], f[nxt][j - 1]);
      }
      std::swap(cur, nxt);
    }
    int sum = 0;
    for (int i = 0; i <= K; ++i) {
      add(sum, f[cur][i]);
    }
    if (mu[d] > 0) {
      add(res, sum);
    } else {
      add(res, Q - sum);
    }
  }
  printf("%d\n", res);
}

int main() {
  int T = 1;
  // scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}