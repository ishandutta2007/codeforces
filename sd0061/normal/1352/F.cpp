#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 102;

int f[N][N][N][2];

int main() {
  memset(f, -1, sizeof(f));
  f[0][0][0][0] = 233;
  f[0][0][0][1] = 233;

  for (int i = 0; i <= 100; ++i) {
    for (int j = 0; j <= 100; ++j) {
      for (int k = 0; k <= 100; ++k) {
        for (int l = 0; l < 2; ++l) {
          if (f[i][j][k][l] != -1) {
            for (int w = 0; w < 2; ++w) {
              int ni = i, nj = j, nk = k, nl = w;
              if (w + l == 0) ++ni;
              if (w + l == 1) ++nj;
              if (w + l == 2) ++nk;
              if (f[ni][nj][nk][nl] == -1) {
                f[ni][nj][nk][nl] = l;
              }
            }
          }
        }
      }
    }
  }

  int T;
  scanf("%d ", &T);
  while (T--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int d = 1;
    if (f[a][b][c][0] != -1) {
      d = 0;
    }
    string res = "";
    while (true) {
      res = char(d + '0') + res;
      int p = f[a][b][c][d];
      if (p == 233) break;
      if (p + d == 0) --a;
      if (p + d == 1) --b;
      if (p + d == 2) --c;
      d = p;
    }
    puts(res.c_str());
  }
}