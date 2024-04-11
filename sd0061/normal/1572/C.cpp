#include <bits/stdc++.h>
using int64 = long long;
const int N = 3005;

int n, a[N], nxt[N];
int f[N][N];

void work() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (i && a[i] == a[i - 1]) {
      --i;
      --n;
    }
  }
  std::map<int, int> h;
  for (int i = n - 1; i >= 0; --i) {
    if (!h.count(a[i])) {
      nxt[i] = n;
    } else {
      nxt[i] = h[a[i]];
    }
    h[a[i]] = i;
  }

  for (int i = 0; i <= n; ++i) {
    memset(f[i], 0, sizeof(f[i]));
  }
  for (int k = 2; k <= n; ++k) {
    for (int i = 0, j = k - 1; j < n; ++i, ++j) {
      f[i][j] = f[i + 1][j];
      for (int x = nxt[i]; x <= j; x = nxt[x]) {
        f[i][j] = std::max(f[i][j], f[i + 1][x - 1] + f[x][j] + 1);
      }
    }
  }
  printf("%d\n", n - 1 - f[0][n - 1]);
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}