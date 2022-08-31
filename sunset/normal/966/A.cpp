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

const int N = 100005;

int n, m, q, x, y, z, a[N], b[N];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m), Read(x), Read(y), Read(z);
  for (int i = 0; i < x; ++i) {
    Read(a[i]);
  }
  for (int i = 0; i < y; ++i) {
    Read(b[i]);
  }
  sort(a, a + x), sort(b, b + y);
  for (Read(q); q; --q) {
    int p, q, u, v, t, ans = INT_MAX;
    Read(p), Read(q), Read(u), Read(v);
    if (p == u) {
      ans = abs(q - v);
    } else {
      t = lower_bound(a, a + x, q) - a;
      if (t < x) {
        CheckMin(ans, abs(p - u) + abs(q - a[t]) + abs(v - a[t]));
      }
      if (t) {
        CheckMin(ans, abs(p - u) + abs(q - a[t - 1]) + abs(v - a[t - 1]));
      }
      t = lower_bound(b, b + y, q) - b;
      if (t < y) {
        CheckMin(ans, (abs(p - u) + z - 1) / z + abs(q - b[t]) + abs(v - b[t]));
      }
      if (t) {
        CheckMin(ans, (abs(p - u) + z - 1) / z + abs(q - b[t - 1]) + abs(v - b[t - 1]));
      }
    }
    printf("%d\n", ans);
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}