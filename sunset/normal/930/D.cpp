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
const int inf = 0x3f3f3f3f;

pii pre[N], suf[N];
LL ans;
int n;

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 0; i < N; ++i) {
    pre[i] = suf[i] = mp(inf, -inf);
  }
  for (int i = 1, x, y, z = 200000; i <= n; ++i) {
    Read(x), Read(y);
    CheckMin(pre[x + y + z].X, x - y);
    CheckMax(pre[x + y + z].Y, x - y);
    CheckMin(suf[x + y + z].X, x - y);
    CheckMax(suf[x + y + z].Y, x - y);
  }
  for (int i = 2; i < N; ++i) {
    CheckMin(pre[i].X, pre[i - 2].X);
    CheckMax(pre[i].Y, pre[i - 2].Y);
  }
  for (int i = N - 3; ~i; --i) {
    CheckMin(suf[i].X, suf[i + 2].X);
    CheckMax(suf[i].Y, suf[i + 2].Y);
  }
  for (int i = 1; i < N - 1; ++i) {
    ans += max(min(pre[i - 1].Y, suf[i + 1].Y) - max(pre[i - 1].X, suf[i + 1].X) >> 1, 0);
  }
  printf("%lld\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}