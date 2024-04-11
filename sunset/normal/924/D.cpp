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

struct Info {
  int x, y;

  Info(int x = 0, int y = 0):x(x), y(y) {}

  bool operator < (const Info &b) const {
    return 1LL * x * b.y < 1LL * y * b.x;
  }

  bool operator == (const Info &b) const {
    return 1LL * x * b.y == 1LL * y * b.x;
  }
} c[N];

pair <Info, Info> a[N];
int n, m, b[N];
LL ans;

inline void Modify(int x) {
  for (; x <= m; ++b[x], x += x & -x);
}

inline int Query(int x) {
  int r = 0;
  for (; x; r += b[x], x -= x & -x);
  return r;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 1, x, y; i <= n; ++i) {
    Read(x), Read(y);
    if (y < 0) {
      a[i] = mp(Info(x, -y + m), Info(-x, -y - m));
    } else {
      a[i] = mp(Info(-x, y - m), Info(x, y + m));
    }
    c[i] = a[i].Y;
  }
  sort(a + 1, a + n + 1), sort(c + 1, c + n + 1), m = unique(c + 1, c + n + 1) - c - 1;
  for (int i = 1, p; i <= n; ++i) {
    p = lower_bound(c + 1, c + m + 1, a[i].Y) - c, ans += Query(p), Modify(p);
  }
  printf("%lld\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}