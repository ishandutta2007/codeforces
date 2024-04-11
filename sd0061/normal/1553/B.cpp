#include <bits/stdc++.h>
const int N = 1005;
char s[N], t[N];
int n, m;
bool f[N][N][2];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", s, t);
    n = strlen(s);
    m = strlen(t);
    std::reverse(t, t + m);
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; ++i) {
      if (s[i] == t[0]) {
        f[1][i][0] = 1;
      }
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (f[i][j][0]) {
          f[i][j][1] = true;
          if (j + 1 < n && s[j + 1] == t[i]) {
            f[i + 1][j + 1][0] = true;
          }
        }
        if (f[i][j][1]) {
          if (j + 1 >= 0 && s[j - 1] == t[i]) {
            f[i + 1][j - 1][1] = true;
          }
        }
      }
    }
    bool g = false;
    for (int i = 0; i < n; ++i) {
      g |= f[m][i][0] || f[m][i][1];
    }
    puts(g ? "YES" : "NO");
  }
  return 0;
}