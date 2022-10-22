#include <bits/stdc++.h>
const int N = 400005;
int n, a[N], b[N], p[N], f[N];
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    p[a[i]] = b[i];
  }
  memset(f, 0, sizeof(f));
  int res = 1;
  for (int i = 1; i <= n; ++i) {
    if (!f[i]) {
      res += res;
      res %= 1000000007;
      int x = i;
      do {
        f[x] = 1;
        x = p[x];
      } while (!f[x]);
    }
  }
  std::cout << res << std::endl;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}