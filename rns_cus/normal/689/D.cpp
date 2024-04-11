#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 30)
#define M 200010
int a[M], b[M], n, f[20][M], g[20][M];

int getmax(int l, int r) {
  int k;
  for (k = 0; ; k++) {
    if ((1 << k) > r - l + 1) break;
  } k--;
  return max(f[k][l], f[k][r - (1 << k) + 1]);
}

int getmin(int l, int r) {
  int k;
  for (k = 0; ; k++) {
    if ((1 << k) > r - l + 1) break;
  } k--;
  return min(g[k][l], g[k][r - (1 << k) + 1]);
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), f[0][i] = a[i];
  for (int i = 1; i <= n; i++) scanf("%d", b + i), g[0][i] = b[i];

  for (int i = 1; i <= 18; i++) {
    for (int j = 1; j + (1 << (i - 1)) <= n; j++) {
      f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
      g[i][j] = min(g[i - 1][j], g[i - 1][j + (1 << (i - 1))]);
    }
  }

  __int64 ans = 0;

  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i]) ans++;
    int l = 1, r = i;
    while (l < r) {
      int mid = (l + r) >> 1;
      int mx = getmax(mid, i);
      int mn = getmin(mid, i);
      if (mx <= mn) r = mid;
      else l = mid + 1;
    }
    if (r < i) {
      if (getmax(r, i) == getmin(r, i)) {
        int L = r, R = i;
        while (L < R) {
          int mid = (L + R) >> 1;
          int mx = getmax(mid, i);
          int mn = getmin(mid, i);
          if (mx >= mn) L = mid + 1;
          else R = mid;
        }
        ans += (R - r);
      }
    }
  }
  printf("%I64d\n", ans);
}