#include <bits/stdc++.h>
using int64 = long long;
const int N = 4000005;
int n, m;

int f[N], d[N];

void add(int& A, int B) {
  A += B;
  if (A >= m) {
    A -= m;
  }
}
int c[N];

void work() {
  scanf("%d%d", &n, &m);
  f[1] = 1;
  int sum = 1;
  for (int k = 1; k <= n; ++k) {
    add(d[k], d[k - 1]);
    if (k != 1) {
      add(f[k], sum);
      add(f[k], d[k]);
    }
    for (int y = k + k, z = 2; y <= n; y += k, z++) {
      add(d[y], f[k]);
      if (y + z <= n) {
        add(d[y + z], m - f[k]);
      }
    }
    if (k != 1) {
      add(sum, f[k]);
    }
  }
  printf("%d\n", f[n]);
}

int main() {
  int T = 1;
  // scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}