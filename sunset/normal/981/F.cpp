#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}

template <typename T> inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T> inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}

const int N = 400005;

int n, ql, qr, l[N], q[N], r[N], L[N], R[N];
LL m, a[N], b[N];

inline bool Check(int mid) {
  for (int i = 0; i < n << 1; ++i) {
    l[i] = lower_bound(b, b + (n << 1), a[i] - mid) - b - i;
    r[i] = upper_bound(b, b + (n << 1), a[i] + mid) - b - i - 1;
  }
  ql = 1, qr = 0;
  for (int i = 0; i < n << 1; ++i) {
    for (; ql <= qr && q[ql] <= i - n; q[ql++] = 0);
    for (; ql <= qr && l[q[qr]] <= l[i]; q[qr--] = 0);
    q[++qr] = i;
    L[i] = l[q[ql]];
  }
  ql = 1, qr = 0;
  for (int i = 0; i < n << 1; ++i) {
    for (; ql <= qr && q[ql] <= i - n; q[ql++] = 0);
    for (; ql <= qr && r[q[qr]] >= r[i]; q[qr--] = 0);
    q[++qr] = i;
    R[i] = r[q[ql]];
  }
  for (int i = n - 1; i < n << 1; ++i) {
    if (L[i] <= R[i]) {
      return true;
    }
  }
  return false;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 0; i < n; ++i) {
    Read(a[i]);
  }
  for (int i = 0; i < n; ++i) {
    Read(b[i]);
  }
  sort(a, a + n);
  sort(b, b + n);
  for (int i = 0; i < n; ++i) {
    a[i + n] = a[i] + m, b[i + n] = b[i] + m;
  }
  int l = 0, r = m - 1, ret = m;
  while (l <= r) {
    int mid = l + r >> 1;
    if (Check(mid)) {
      ret = mid, r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", ret);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}