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

const int N = 1005;

int n, p, q, a[N], b[N];
LL ans;

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(p), Read(q), p += q;
  for (int i = 0; i < n; ++i) {
    Read(a[i]);
  }
  for (int i = 0; i < n; ++i) {
    Read(b[i]);
    if (a[i] < b[i]) {
      swap(a[i], b[i]);
    }
  }
  while (p--) {
    int t = 0;
    for (int j = 1; j < n; ++j) {
      if (a[j] - b[j] > a[t] - b[t]) {
        t = j;
      }
    }
    if (a[t] == b[t]) {
      ++a[t];
    } else {
      --a[t];
    }
  }
  for (int i = 0; i < n; ++i) {
    ans += 1LL * (a[i] - b[i]) * (a[i] - b[i]);
  }
  printf("%lld\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}