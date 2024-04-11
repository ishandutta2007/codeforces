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

const int N = 300005;

int n, p, q;
pii a[N];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(p), Read(q);
  for (int i = 1; i <= n; ++i) {
    Read(a[i].X), a[i].Y = i;
  }
  sort(a + 1, a + n + 1, greater <pii> ());
  for (int itr = 0; itr < 2; ++itr) {
    int x = -1, y = -1;
    for (int i = 1; i <= n; ++i) {
      if (1LL * a[i].X * i >= p) {
        x = i;
        break;
      }
    }
    if (~x) {
      for (int i = x + 1; i <= n; ++i) {
        if (1LL * a[i].X * (i - x) >= q) {
          y = i;
        }
      }
      if (~y) {
        puts("Yes");
        if (!itr) {
          printf("%d %d\n", x, y - x);
          for (int i = 1; i <= x; ++i) {
            printf("%d%c", a[i].Y, i == x ? '\n' : ' ');
          }
          for (int i = x + 1; i <= y; ++i) {
            printf("%d%c", a[i].Y, i == y ? '\n' : ' ');
          }
        } else {
          printf("%d %d\n", y - x, x);
          for (int i = x + 1; i <= y; ++i) {
            printf("%d%c", a[i].Y, i == y ? '\n' : ' ');
          }
          for (int i = 1; i <= x; ++i) {
            printf("%d%c", a[i].Y, i == x ? '\n' : ' ');
          }
        }
        return 0;
      }
    }
    swap(p, q);
  }
  puts("No");
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}