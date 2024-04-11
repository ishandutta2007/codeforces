#include <bits/stdc++.h>
const int N = 105;

bool s[N][N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int lx = -2, ly = -2;
    memset(s, 0, sizeof(s));
    for (int i = 0; i < m; ++i) {
      int x = 0, y = i;
      if (std::abs(x - lx) <= 1 && std::abs(y - ly) <= 1) {
        continue;
      } else {
        s[x][y] = 1;
        lx = x;
        ly = y;
      }
    }
    for (int i = 0; i < n; ++i) {
      int x = i, y = m - 1;
      if (std::abs(x - lx) <= 1 && std::abs(y - ly) <= 1) {
        continue;
      } else {
        s[x][y] = 1;
        lx = x;
        ly = y;
      }
    }
    for (int i = m - 1; i >= 0; --i) {
      int x = n - 1, y = i;
      if (std::abs(x - lx) <= 1 && std::abs(y - ly) <= 1) {
        continue;
      } else {
        s[x][y] = 1;
        lx = x;
        ly = y;
      }
    }
    for (int i = n - 1; i > 1; --i) {
      int x = i, y = 0;
      if (std::abs(x - lx) <= 1 && std::abs(y - ly) <= 1) {
        continue;
      } else {
        s[x][y] = 1;
        lx = x;
        ly = y;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        printf("%d", s[i][j]);
      }
      puts("");
    }
  }
  return 0;
}