#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

void work() {
  int n, k;
  scanf("%d" , &n);
  std::vector<int> a(n);
  int x = 0 , y = 0;
  for (int i = 0 ; i < n ; ++ i) {
    scanf("%d" , &a[i]);
    x += a[i] == 0;
    y += a[i] == 1;
  }

  int res = 1 << 30, u = 0, v = 0;
  for (int i = 0 ; i <= n ; ++ i) {
    res = std::min(res, std::max(v, x - u));
    if (i < n) {
      u += a[i] == 0;
      v += a[i] == 1;
    }
  }
  printf("%d\n", res);
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T --) {
    // static int ca = 0;
    // printf("Case #%d: ", ++ ca);
    work();
  }
  return 0;
}