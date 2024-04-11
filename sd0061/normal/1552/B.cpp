#include <bits/stdc++.h>
using int64 = long long;

const int N = 50005;

int n, a[N][5], o[N];

bool strong(int x, int y) {
  int c = 0;
  for (int l = 0; l < 5; ++l) {
    c += (a[x][l] < a[y][l]);
  }
  return c >= 3;
}

void work() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  int res = 0;
  for (int i = 1; i < n; ++i) {
    if (strong(i, res)) {
      res = i;
    }
  }
  bool yes = true;
  for (int i = 0; i < n; ++i) {
    if (i != res && !strong(res, i)) {
      yes = false;
      break;
    }
  }
  printf("%d\n", yes ? res + 1 : -1);
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}