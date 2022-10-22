#include <bits/stdc++.h>

const int N = 200005;

int n, a[N], b[N], c[N];

void work() {
  scanf("%d", &n);
  int n0 = 0, n1 = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (i & 1) {
      b[n1++] = a[i];
    } else {
      c[n0++] = a[i];
    }
  }
  std::sort(b, b + n1);
  std::sort(c, c + n0);
  n0 = 0;
  n1 = 0;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      a[i] = b[n1++];
    } else {
      a[i] = c[n0++];
    }
    if (i && a[i] < a[i - 1]) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}