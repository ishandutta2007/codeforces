#include <bits/stdc++.h>

using namespace std;

const int MAX = 80;
const int N = 500010;

double f[N][MAX];
int pr[N];

int main() {
  int tt;
  scanf("%d", &tt);
  int n = 1;
  for (int j = 0; j < MAX; j++) {
    f[n][j] = 1.0;
  }
  while (tt--) {
    int type, v;
    scanf("%d %d", &type, &v);
    if (type == 1) {
      n++;
      pr[n] = v;
      for (int j = 0; j < MAX; j++) {
        f[n][j] = 1.0;
      }
      int t = n;
      double old = 1.0;
      for (int j = 0; j < MAX; j++) {
        if (t == 1) {
          break;
        }
        double new_old = 0.5 * (1 + f[pr[t]][j]);
        f[pr[t]][j] *= 0.5 * (1 + (j == 0 ? 0.0 : f[t][j - 1])) / old;
        old = new_old;
        t = pr[t];
      }
    } else {
      double ans = 0.0;
      for (int j = 0; j < MAX; j++) {
        ans += 1.0 - f[v][j];
      }
      printf("%.17f\n", ans);
    }
  }
  return 0;
}