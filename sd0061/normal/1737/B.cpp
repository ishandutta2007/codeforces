#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

int64 cal(int64 x) {
  int64 res = 0;
  for (int k = 0; k < 3; ++k) {
    int64 l = 0, r = 2e9 + 5;
    while (l < r) {
      int64 m = (l + r + 1) >> 1;
      if (1LL * m * (m + k) <= x) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    res += l;
  }
  return res;
}

void work() {
  int64 l, r;
  scanf("%lld%lld", &l, &r);
  printf("%lld\n", cal(r) - cal(l - 1));
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    // static int ca = 0;
    // printf("Case #%d: ", ++ ca);
    work();
  }
  return 0;
}