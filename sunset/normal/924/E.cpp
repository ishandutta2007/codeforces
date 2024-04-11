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

const int N = 10005;
const int inf = 0x3f3f3f3f;

int n, l, r, s, ans[N];
pii a[N];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(r), Read(l);
  for (int i = 1; i <= n; ++i) {
    Read(a[i].Y), s += a[i].Y, a[i].Y = -a[i].Y;
  }
  l = s - l, r = s - r;
  for (int i = 1; i <= n; ++i) {
    Read(a[i].X);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i].Y = -a[i].Y;
  }
  for (int i = 1; i <= s; ++i) {
    ans[i] = -inf;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = r; j >= a[i].Y; --j) {
      CheckMax(ans[j], ans[j - a[i].Y] + a[i].X * (j >= l && j <= r));
    }
  }
  int ret = 0;
  for (int i = 0; i <= s; ++i) {
    CheckMax(ret, ans[i]);
  }
  printf("%d\n", ret);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}