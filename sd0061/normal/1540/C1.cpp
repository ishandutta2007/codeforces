#include <bits/stdc++.h>

const int N = 105;
const int Q = 1e9 + 7;
int n, q;
int c[N], b[N];
int f[2][10005], g[2][10005];

inline void add(int &A, int B) {
  A += B;
  if (A >= Q) {
    A -= Q;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c[i]);
  }
  for (int i = 0; i + 1 < n; ++i) {
    scanf("%d", &b[i]);
  }

  scanf("%d", &q);
  scanf("%d", &q);
  int res = 0;
  int delta = 0, sum = 0, sb = 0;
  int cur = 0, nxt = 1;
  memset(f, 0, sizeof(f));
  f[cur][0] = 1;

  for (int i = 0; i < n; ++i) {
    memset(f[nxt], 0, sizeof(f[nxt]));
    delta += sb;
    for (int j = 0; j <= sum; ++j) {
      int prefix_sum = q * (i + 1) + delta - j;
      for (int k = std::max(prefix_sum, 0); k <= c[i]; ++k) {
        add(f[nxt][j + k], f[cur][j]);
      }
    }
    sum += c[i];
    sb += b[i];
    std::swap(cur, nxt);
  }
  for (int i = 0; i <= sum; ++i) {
    add(res, f[cur][i]);
  }
  printf("%d\n", res);
  return 0;
}