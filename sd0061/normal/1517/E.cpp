#include "bits/stdc++.h"

const int N = 200005;
const int Q = 998244353;
using int64 = long long;
int n, a[N];
int64 pre[N], ord[N];

void gao(int64& res, int64 sum) {
  pre[0] = ord[0] = 0;
  for (int i = 0; i < n; ++i) {
    pre[i + 1] = pre[i] + a[i];
    ord[i + 2] = ord[i] + a[i];
  }
  // for (int i = 0; i <= n; ++i) {
  //   printf("%lld ", pre[i]);
  // }
  // puts("");
  // for (int i = 0; i <= n + 1; ++i) {
  //   printf("%lld ", ord[i]);
  // }
  // puts("");

  // a[0] = 'C'
  for (int i = 0; i + 1 < n; ++i) {
    // j in range[0, (n - i + 1) / 2]
    // num of j -> 2 * ord[i + j + j + 2] < sum - 2 * (pre[i + 1] - ord[i + 2])
    // for (int j = 0; i + j + j < n; ++j) {
    //   int64 s = pre[i + 1] + ord[i + j + j + 2] - ord[i + 2];
    //   if (s < sum - s) {
    //     printf("%d %d\n", i, j);
    //     ++res;
    //   }
    // }
    int l = 0, r = (n - i + 1) / 2;
    while (l < r) {
      int m = l + r >> 1;
      int64 s = pre[i + 1] + ord[i + m + m + 2] - ord[i + 2];
      if (s >= sum - s) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    res += r;
  }

  for (int i = 0; i + 1 < n; ++i) {
    int l = 0, r = (n - i - 2) / 2;
    // for (int j = 0; i + j + j < n; ++j) {
    //   if (n - 1 - (i + j + j) > 2) {
    //     int64 s = pre[i + 1] + ord[i + j + j + 2] - ord[i + 2] + a[n - 1];
    //     if (s < sum - s) {
    //       ++res;
    //     }
    //   }
    // }
    while (l < r) {
      int m = l + r >> 1;
      int64 s = pre[i + 1] + ord[i + m + m + 2] - ord[i + 2] + a[n - 1];
      if (s >= sum - s) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    res += r;
  }
}

void work() {
  int64 res = 0;
  int64 sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  int64 s = 0;
  for (int i = 0; i < n; ++i) {
    s += a[i];
    if (s > sum - s) {
      ++res;
    }
  }
  gao(res, sum);
  for (int i = 0; i + 1 < n; ++i) {
    a[i] = a[i + 1];
  }
  --n;
  gao(res, sum);

  printf("%d\n", int(res % Q));
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
}