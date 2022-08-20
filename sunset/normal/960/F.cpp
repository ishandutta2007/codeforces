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

unordered_map <int, int> f[N];
int n, m, ans;

inline void Modify(int x, int y, int z) {
  for (; y < N; y += y & -y) {
    CheckMax(f[x][y], z);
  }
}

inline int Query(int x, int y) {
  int r = 0;
  for (; y; y -= y & -y) {
    CheckMax(r, f[x][y]);
  }
  return r;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 1, x, y, w; i <= m; ++i) {
    Read(x), Read(y), Read(w), ++w;
    Modify(y, w, Query(x, w - 1) + 1);
  }
  for (int i = 1; i <= n; ++i) {
    CheckMax(ans, Query(i, N - 1));
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}