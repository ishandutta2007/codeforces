#include <bits/stdc++.h>

const int max_N = 2000 + 21;

int n, a[max_N][max_N];

int main() {
  scanf("%d", &n);
  int m = n >> 1;
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      a[(i << 1)][(j << 1)] = cnt++;
      a[(i << 1)][(j << 1) | 1] = cnt++;
      a[(i << 1) | 1][(j << 1)] = cnt++;
      a[(i << 1) | 1][(j << 1) | 1] = cnt++;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d%c", a[i][j], " \n"[j == n - 1]);
    }
  }
}