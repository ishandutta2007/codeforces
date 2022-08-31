#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const int inf = 0x3f3f3f3f;

int n, a[N], f[N][N][2][2];

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(f, 0x3f, sizeof f);
  f[0][0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int cur = 0; cur < 2; ++cur) {
        for (int last = 0; last < 2; ++last) {
          if (f[i][j][cur][last] != inf) {
            for (int next = 0; next < 2; ++next) {
              if (!cur || !next) {
                int value = f[i][j][cur][last];
                if (!cur) {
                  int limit = inf;
                  if (next) {
                    limit = min(limit, a[i + 1]);
                  }
                  if (last && i > 1) {
                    limit = min(limit, a[i - 1]);
                  }
                  value += max(a[i] - limit + 1, 0);
                }
                f[i + 1][j + next][next][cur] = min(f[i + 1][j + next][next][cur], value);
              }
            }
          }
        }
      }
    }
  }
  for (int i = 1; i <= n + 1 >> 1; ++i) {
    int answer = inf;
    for (int cur = 0; cur < 2; ++cur) {
      for (int last = 0; last < 2; ++last) {
        if (f[n][i][cur][last] != inf) {
          int value = f[n][i][cur][last];
          if (last) {
            value += max(a[n] - a[n - 1] + 1, 0);
          }
          answer = min(answer, value);
        }
      }
    }
    printf("%d%c", answer, i == n + 1 >> 1 ? '\n' : ' ');
  }
  return 0;
}