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

const int N = 500005;

int n, m, ans, a[N], val[N << 2];

inline void Build(int x, int l, int r) {
  if (l == r) {
    val[x] = a[l];
    return ;
  }
  int mid = l + r >> 1;
  Build(x << 1, l, mid);
  Build(x << 1 | 1, mid + 1, r);
  val[x] = __gcd(val[x << 1], val[x << 1 | 1]);
}

inline void Modify(int x, int l, int r, int p, int v) {
  if (l == r) {
    val[x] = v;
    return ;
  }
  int mid = l + r >> 1;
  if (p <= mid) {
    Modify(x << 1, l, mid, p, v);
  } else {
    Modify(x << 1 | 1, mid + 1, r, p, v);
  }
  val[x] = __gcd(val[x << 1], val[x << 1 | 1]);
}

inline void Query(int x, int l, int r, int ql, int qr, int v) {
  if (val[x] % v == 0 || ans > 1) {
    return ;
  }
  if (l == r) {
    ++ans;
    return ;
  }
  int mid = l + r >> 1;
  if (qr <= mid) {
    Query(x << 1, l, mid, ql, qr, v);
  } else if (ql > mid) {
    Query(x << 1 | 1, mid + 1, r, ql, qr, v);
  } else {
    Query(x << 1, l, mid, ql, mid, v), Query(x << 1 | 1, mid + 1, r, mid + 1, qr, v);
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 1; i <= n; ++i) {
    Read(a[i]);
  }
  Build(1, 1, n);
  Read(m);
  for (int i = 1, opt; i <= m; ++i) {
    Read(opt);
    if (opt == 1) {
      int l, r, x;
      Read(l), Read(r), Read(x), ans = 0;
      Query(1, 1, n, l, r, x);
      puts(ans <= 1 ? "YES" : "NO");
    } else {
      int p, v;
      Read(p), Read(v);
      Modify(1, 1, n, p, v);
    }
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}