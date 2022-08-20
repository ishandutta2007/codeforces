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

bitset <N> ans, a[N << 2];
vector <int> tag[N << 2];
int n, m;

inline void Modify(int x, int l, int r, int ql, int qr, int v) {
  if (l == ql && r == qr) {
    tag[x].pb(v);
    return ;
  }
  int mid = l + r >> 1;
  if (qr <= mid) {
    Modify(x << 1, l, mid, ql, qr, v);
  } else if (ql > mid) {
    Modify(x << 1 | 1, mid + 1, r, ql, qr, v);
  } else {
    Modify(x << 1, l, mid, ql, mid, v), Modify(x << 1 | 1, mid + 1, r, mid + 1, qr, v);
  }
}

inline void Build(int x, int l, int r) {
  for (auto e : tag[x]) {
    a[x] |= a[x] << e;
  }
  if (l == r) {
    ans |= a[x];
    return ;
  }
  a[x << 1] = a[x << 1 | 1] = a[x];
  int mid = l + r >> 1;
  Build(x << 1, l, mid), Build(x << 1 | 1, mid + 1, r);
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 1; i <= m; ++i) {
    int l, r, x;
    Read(l), Read(r), Read(x);
    Modify(1, 1, n, l, r, x);
  }
  a[1][0] = true;
  Build(1, 1, n);
  int ret = 0;
  for (int i = 1; i <= n; ++i) {
    if (ans[i]) {
      ++ret;
    }
  }
  printf("%d\n", ret);
  for (int i = 1; i <= n; ++i) {
    if (ans[i]) {
      printf("%d ", i);
    }
  }
  putchar(10);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}