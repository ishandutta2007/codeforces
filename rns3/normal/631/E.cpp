#include <bits/stdc++.h>

using namespace std;

#define N 200005

typedef __int64 LL;

int a[N], c[N];
LL sum[N];

LL cross(int i, int j, int k) {
  int x = i - j, xx = i - k;
  LL y = sum[i] - sum[j], yy = sum[i] - sum[k];
  return x * yy - y * xx;
}

LL cross1(int i, int j, int k) {
  int x = i - j, xx = i - k;
  LL y = sum[i - 1] - sum[j - 1], yy = sum[i - 1] - sum[k - 1];
  return x * yy - y * xx;
}

main() {
  int n;
  LL pr = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) {
    scanf("%d", a + i);
    sum[i] = sum[i - 1] + a[i];
    pr += 1LL * i * a[i];
  }
  LL rlt = pr;
  int sz = 0;
  for (int i = n; i; i --) {
    int lo = 1, hi = sz;
    while (lo < hi) {
      int m1 = lo + hi >> 1;
      int m2 = m1 + 1;
      LL r1 = 1LL * a[i] * c[m1] - sum[c[m1]];
      LL r2 = 1LL * a[i] * c[m2] - sum[c[m2]];
      if (r1 < r2) lo = m2;
      else hi = m1;
    }
    if (lo == hi) {
      LL tmp = pr + 1LL * a[i] * (c[lo] - i) - (sum[c[lo]] - sum[i]);
      if (rlt < tmp) rlt = tmp;
    }
    while (sz > 1 && cross(i, c[sz], c[sz - 1]) <= 0) sz --;
    c[++ sz] = i;
  }
  sz = 0;
  for (int i = 1; i <= n; i ++) {
    int lo = 1, hi = sz;
    while (lo < hi) {
      int m1 = lo + hi >> 1;
      int m2 = m1 + 1;
      LL r1 = 1LL * a[i] * c[m1] - sum[c[m1] - 1];
      LL r2 = 1LL * a[i] * c[m2] - sum[c[m2] - 1];
      if (r1 < r2) lo = m2;
      else hi = m1;
    }
    if (lo == hi) {
      LL tmp = pr - 1LL * a[i] * (i - c[lo]) + (sum[i - 1] - sum[c[lo] - 1]);
      if (rlt < tmp) rlt = tmp;
    }
    while (sz > 1 && cross1(i, c[sz], c[sz - 1]) >= 0) sz --;
    c[++ sz] = i;
  }
  printf("%I64d\n", rlt);
}