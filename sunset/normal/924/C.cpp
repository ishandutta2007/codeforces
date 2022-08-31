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

int n, a[N], b[N];
LL ans;

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 1; i <= n; ++i) {
    Read(a[i]);
  }
  for (int i = n; i; --i) {
    b[i] = max(b[i + 1] - 1, a[i] + 1);
  }
  for (int i = 1; i <= n; ++i) {
    CheckMax(b[i], b[i - 1]), ans += b[i] - a[i] - 1;
  }
  printf("%lld\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}