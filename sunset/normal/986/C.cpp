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

const int N = 4194305;

bool a[N], b[N];
int n, m, s;

inline void DFS(int x) {
  if (!b[x]) {
    b[x] = true;
    if (a[x]) {
      DFS((1 << n) - 1 ^ x);
    }
    for (int i = 0; i < n; ++i) {
      if (x >> i & 1) {
        DFS(x ^ 1 << i);
      }
    }
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 0, x; i < m; ++i) {
    Read(x), a[x] = true;
  }
  for (int i = 0; i < 1 << n; ++i) {
    if (a[i] && !b[i]) {
      ++s, DFS((1 << n) - 1 ^ i);
    }
  }
  printf("%d\n", s);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}