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

inline LL Qul(LL x, LL y, LL mod) {
  return (x * y - (LL)((long double)x * y / mod + 0.5) * mod + mod) % mod;
}

inline LL Qow(LL x, LL y, LL mod) {
  LL r = 1;
  for (; y; y >>= 1, x = Qul(x, x, mod)) {
    if (y & 1) {
      r = Qul(r, x, mod);
    }
  }
  return r;
}

inline int Get(LL x) {
  int r = 0;
  for (; x; x /= 10, ++r);
  return r;
}

int Main() {
  LL a, b;
  Read(a);
  for (int n = Get(a), m = 0; ; a *= 10, ++m) {
    b = -a & (1LL << n + m) - 1;
    if ((a + b) % 5 == 0) {
      b += 1LL << n + m;
    }
    if (Get(b) <= m) {
      LL c = a + b >> n + m, tmp = 0, mod = 5;
      if (c % 5 == 2) {
        tmp = 1;
      } else if (c % 5 == 3) {
        tmp = 3;
      } else if (c % 5 == 4) {
        tmp = 2;
      }
      for (int i = 1; i < n + m; mod *= 5, ++i) {
        while (Qow(2, tmp, mod * 5) != c % (mod * 5)) {
          tmp += mod / 5 * 4;
        }
      }
      printf("%lld\n", tmp + n + m);
      return 0;
    }
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  int T;
  for (Read(T); T; --T) {
    Main();
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}