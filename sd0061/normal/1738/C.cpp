#include <bits/stdc++.h>
using int64 = long long;
const int N = 105;

int n, a ,b;
bool f[N][N][2];
void work() {
  scanf("%d", &n);
  a = b = 0;
  for (int i = 0 ; i < n ; ++ i) {
    int x;
    scanf("%d", &x);
    if (x & 1) {
      b ++;
    } else {
      a ++;
    }
  }

  for (int i = 0 ; i <= a ; ++ i) {
    for (int j = 0 ; j <= b ; ++ j) {
      int t = (n - i - j) % 2;
      for (int k = 0 ; k < 2 ; ++ k) {
        if (i + j == 0) {
          f[i][j][k] = k == 0;
        } else {
          if (t == 0) {
            int x = 0;
            if (i && f[i - 1][j][k]) {
              x = 1;
            } else if (j && f[i][j - 1][k ^ 1]) {
              x = 1;
            }
            f[i][j][k] = x;
          } else {
            int x = 1;
            if (i && !f[i - 1][j][k]) {
              x = 0;
            } else if (j && !f[i][j - 1][k]) {
              x = 0;
            }

            f[i][j][k] = x;
          }


        }

      }
    }
  }
  puts(f[a][b][0] ? "Alice" : "Bob");
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T --) {
    work();
  }
  return 0;
}