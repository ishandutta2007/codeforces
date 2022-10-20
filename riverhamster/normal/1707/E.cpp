#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while (isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 100005;
const int STEP = 34;
const int INF = 0x3f3f3f3f;

struct interval {
  int l, r;
  interval operator+(const interval &rhs) const { return {min(l, rhs.l), max(r, rhs.r)}; }
  void operator+=(const interval &rhs) { l = min(l, rhs.l); r = max(r, rhs.r); }
};

int len, n;
int a[N];

interval lf[STEP][N * 2];

interval query(const interval *a, int l, int r) {
  interval ans = {INF, -INF};
  for (l += len, r += len; l != r; l >>= 1, r >>= 1) {
    if (l & 1) ans += a[l++];
    if (r & 1) ans += a[--r];
  }
  return ans;
}
void init(interval *a) {
  for (int i = len - 1; i > 0; --i)
    a[i] = a[i << 1] + a[i << 1 | 1];
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, qc;
  read(n, qc);
  for (int i = 0; i < n; ++i)
    read(a[i]), --a[i];
  len = n - 1;
  for (int i = 0; i < len; ++i)
    lf[0][i + len] = {min(a[i], a[i + 1]), max(a[i], a[i + 1])};
  init(lf[0]);
  for (int i = 1; i < STEP; ++i) {
    for (int j = 0; j < len; ++j) {
      if (lf[i - 1][j + len].l >= lf[i - 1][j + len].r)
        lf[i][j + len] = {INF, -INF};
      else
        lf[i][j + len] = query(lf[i - 1], lf[i - 1][j + len].l, lf[i - 1][j + len].r);
    }
    init(lf[i]);
  }
  while (qc--) {
    interval I;
    read(I.l, I.r);
    --I.l; --I.r;
    if (I.l == 0 && I.r == n - 1) {
      puts("0");
      continue;
    }
    ll ans = 0;
    for (int i = STEP - 1; i >= 0; --i) {
      interval J = query(lf[i], I.l, I.r);
      if (J.l >= J.r) { ans = -2; break; }
      if (J.l != 0 || J.r != n - 1) {
        ans |= 1LL << i;
        I = J;
      }
    }
    if (ans > n * (n + 1) / 2)
      puts("-1");
    else
      printf("%lld\n", ans + 1);
  }
  return 0;
}