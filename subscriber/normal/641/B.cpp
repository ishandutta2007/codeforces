#include <bits/stdc++.h>

using namespace std;

const int N = 777;

int res[N][N];
pair <int, int> a[N][N];

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = make_pair(i, j);
      res[i][j] = 0;
    }
  }
  for (int it = 0; it < q; it++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int r;
      scanf("%d", &r);
      r--;
      pair <int, int> tmp = a[r][0];
      for (int j = 1; j < m; j++) {
        a[r][j - 1] = a[r][j];
      }
      a[r][m - 1] = tmp;
    }
    if (type == 2) {
      int c;
      scanf("%d", &c);
      c--;
      pair <int, int> tmp = a[0][c];
      for (int j = 1; j < n; j++) {
        a[j - 1][c] = a[j][c];
      }
      a[n - 1][c] = tmp;
    }
    if (type == 3) {
      int i, j, x;
      scanf("%d %d %d", &i, &j, &x);
      i--; j--;
      res[a[i][j].first][a[i][j].second] = x;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j > 0) putchar(' ');
      printf("%d", res[i][j]);
    }
    printf("\n");
  }
  return 0;
}