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

int n, p, ans;

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), ans = n;
  for (int i = 2, x = n; i <= x; ++i) {
    if (x % i == 0) {
      for (p = i; x % p == 0; x /= p);
    }
  }
  for (int i = n - p + 1; i <= n; ++i) {
    int x = i, q = 0;
    for (int j = 2; j * j <= x; ++j) {
      if (x % j == 0) {
        for (q = j; x % j == 0; x /= j);
      }
    }
    if (x != 1) {
      q = x;
    }
    if (i != q) {
      CheckMin(ans, i - q + 1);
    }
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}