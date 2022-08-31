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
const int mod = 1e9 + 9;

int n, m, x, y, ans, cur;
char s[N];

inline int Qow(int x, int y) {
  int r = 1;
  for (; y; y >>= 1, x = 1LL * x * x % mod) {
    if (y & 1) {
      r = 1LL * r * x % mod;
    }
  }
  return r;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(m), Read(x), Read(y), Read(n);
  scanf("%s", s), cur = Qow(x, m);
  int mul = 1LL * y * Qow(x, mod - 2) % mod;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '+') {
      ans = (ans + cur) % mod;
    } else {
      ans = (ans - cur + mod) % mod;
    }
    cur = 1LL * cur * mul % mod;
  }
  mul = Qow(mul, n), m = (m + 1) / n;
  if (mul == 1) {
    printf("%d\n", 1LL * ans * m % mod);
  } else if (!mul) {
    printf("%d\n", ans);
  } else {
    int tmp = 1LL * (Qow(mul, m) - 1) * Qow(mul - 1, mod - 2) % mod;
    printf("%d\n", 1LL * ans * tmp % mod);
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}