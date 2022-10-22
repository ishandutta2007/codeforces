#include <bits/stdc++.h>
using int64 = long long;
const int N = 1005;
int n, a[N];

void work() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (i & 1) {
      a[i] = -a[i];
    }
  }
  int64 res = 0;
  for (int i = 0; i < n; i += 2) {
    int64 min_pre = 0;
    int64 cur_sum = 0;
    for (int j = i + 1; j < n; j += 2) {
      int64 L = 1, R = a[i];
      L = std::max(L, -min_pre);
      L = std::max(L, 1 - cur_sum);
      R = std::min(R, -a[j] - cur_sum);
      if (L <= R) {
        res += R - L + 1;
      }

      // if (a[i] >= -min_pre) {
      //   std::cout << a[i] + min_pre << ' ' << -a[j] << ' '
      //             << std::min(a[i] + min_pre, (int64)-a[j]) << '\n';
      //   res += std::min(a[i] + min_pre, (int64)-a[j]);
      // }

      min_pre = std::min(min_pre, cur_sum + a[j]);
      cur_sum += a[j];
      if (j + 1 < n) {
        min_pre = std::min(min_pre, cur_sum + a[j + 1]);
        cur_sum += a[j + 1];
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  int T = 1;
  while (T--) {
    work();
  }
  return 0;
}