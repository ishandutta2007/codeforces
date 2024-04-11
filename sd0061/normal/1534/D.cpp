#include <bits/stdc++.h>
const int N = 2005;
int n;
bool g[N][N], f[N];
int d[N][N];

void query(int x) {
  printf("? %d\n", x);
  fflush(stdout);
  assert(!f[x]);
  f[x] = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &d[x][i]);
    d[i][x] = d[x][i];
  }
}

void work() {
  scanf("%d", &n);
  query(1);
  int cnt = 0;
  for (int i = 2; i <= n; ++i) {
    if (d[1][i] & 1) {
      ++cnt;
    }
  }
  if (cnt < n - cnt - 1) {
    for (int i = 2; i <= n; ++i) {
      if (d[i][1] & 1) {
        query(i);
      }
    }
  } else {
    for (int i = 2; i <= n; ++i) {
      if (~d[i][1] & 1) {
        query(i);
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (d[1][i] == d[1][j] + 1 && d[i][j] == 1) {
        g[i][j] = g[j][i] = 1;
        break;
      }
    }
  }

  puts("!");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (g[i][j]) {
        printf("%d %d\n", i, j);
      }
    }
  }
  fflush(stdout);
}

int main() {
  int T = 1;
  // scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}