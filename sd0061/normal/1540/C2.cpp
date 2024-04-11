#include <bits/stdc++.h>

const int N = 105;
const int Q = 1e9 + 7;
int n, p, q;
int c[N], b[N];
int f[2][10005];
int ans[200];
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
  int min_prefix = 1 << 30;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k < j; ++k) {
        sum += b[k];
      }
    }
    min_prefix = std::min(min_prefix, -sum / (i + 1));
  }

  int mn = min_prefix - 45;
  int mx = min_prefix + 150;
  memset(ans, -1, sizeof(ans));

  scanf("%d", &p);
  while (p--) {
    scanf("%d", &q);
    q = std::min(mx, std::max(mn, q));
    if (~ans[q - mn]) {
      printf("%d\n", ans[q - mn]);
      continue;
    }
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
        int b = std::max(prefix_sum, 0);
        if (b <= c[i]) {
          add(f[nxt][j + b], f[cur][j]);
          add(f[nxt][j + c[i] + 1], Q - f[cur][j]);
        }
      }
      sum += c[i];
      for (int j = 1; j <= sum; ++j) {
        add(f[nxt][j], f[nxt][j - 1]);
      }
      sb += b[i];
      std::swap(cur, nxt);
    }
    for (int i = 0; i <= sum; ++i) {
      add(res, f[cur][i]);
    }
    ans[q - mn] = res;
    printf("%d\n", res);
  }
  return 0;
}