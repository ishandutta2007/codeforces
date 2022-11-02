#include <bits/stdc++.h>
using namespace std;
#define M 510

int s[3][M][M], b[M][M], a[M][M], n, m;

int sum(int x, int y, int xx, int yy) {
  return b[xx][yy] - b[x - 1][yy] - b[xx][y - 1] + b[x - 1][y - 1];
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      s[0][i][j] = a[i][j];
      b[i][j] = a[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
    }
  }
  int x = 0, ans = -(1 << 30);
  for (int t = 3; t <= min(n, m); t += 2) {
    for (int i = 1; i <= n - t + 1; i++) {
      for (int j = 1; j <= m - t + 1; j++) {
        s[1 - x][i][j] = sum(i, j, i + t - 1, j + t - 1) - s[x][i + 1][j + 1] - a[i + 1][j];
        ans = max(s[1 - x][i][j], ans);
      }
    }
    x ^= 1;
  }
  printf("%d\n", ans);
}