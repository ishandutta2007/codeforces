#include <bits/stdc++.h>
const int N = 100005;

int n, a[N], b[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &b[i]);
    }
    std::sort(a, a + n);
    std::sort(b, b + n);
    std::reverse(a, a + n);
    std::reverse(b, b + n);

    int l = 0, r = n * 10;
    while (l < r) {
      int m = l + r >> 1;
      int p = n + m - (n + m) / 4;
      int sa = 0, sb = 0;
      for (int i = 0; i < p && i < n; ++i) {
        sb += b[i];
      }
      int k = m;
      while (p > 0 && k > 0) {
        sa += 100;
        p--;
        k--;
      }
      for (int i = 0; i < p && i < n; ++i) {
        sa += a[i];
      }
      if (sa >= sb) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    printf("%d\n", r);
  }
  return 0;
}