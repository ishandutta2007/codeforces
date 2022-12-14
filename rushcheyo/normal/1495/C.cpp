#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[505][505];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      scanf("%s", s[i] + 1);
    }
    for (int i = 0; i < n; i += 3) {
      for (int j = 1; j <= m; ++j) {
        s[i][j] = 'X';
      }
      if (i + 3 < n) {
        bool flag = false;
        for (int j = 1; j <= m; ++j) {
          if (s[i + 1][j] == 'X' || s[i + 2][j] == 'X') {
            s[i + 1][j] = s[i + 2][j] = 'X';
            flag = true;
            break;
          }
        }
        if (!flag) {
          s[i + 1][1] = s[i + 2][1] = 'X';
        }
      } else {
        if (i + 2 < n) {
          for (int j = 1; j <= m; ++j) {
            if (s[i + 2][j] == 'X') {
              s[i + 1][j] = s[i + 2][j] = 'X';
            }
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      puts(s[i] + 1);
    }
  }
}