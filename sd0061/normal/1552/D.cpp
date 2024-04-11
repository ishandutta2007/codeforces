#include <bits/stdc++.h>
using int64 = long long;

const int N = 10;

int n, a[N];

void work() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  // if (n == 1) {
  //   puts(a[0] == 0 ? "YES" : "NO");
  //   return;
  // }
  int pow = 1;
  for (int i = 0; i < n; ++i) {
    pow *= 3;
  }
  for (int i = 0; i < pow; ++i) {
    int s = 0;
    int mask = i;
    for (int j = 0; j < n; ++j) {
      int k = mask % 3;
      mask /= 3;
      if (k == 0) {
        s += a[j];
      }
      if (k == 1) {
        s -= a[j];
      }
    }

    mask = i;
    for (int j = 0; j < n; ++j) {
      int k = mask % 3;
      mask /= 3;
      if (k == 2 && s == a[j]) {
        puts("YES");
        return;
      }
    }
  }
  puts("NO");
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}