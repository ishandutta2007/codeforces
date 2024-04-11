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

const int N = 65;

LL tag[N];
int n;

inline int Dep(LL x) {
  int r = 0;
  for (; x != 1; x >>= 1, ++r);
  return r;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  for (Read(n); n; --n) {
    int opt, dep;
    LL x, k;
    Read(opt), Read(x), dep = Dep(x);
    if (opt == 1) {
      Read(k);
      tag[dep] = tag[dep] + k + (1LL << 60) & (1LL << dep) - 1;
    } else if (opt == 2) {
      Read(k);
      for (; dep < 60; ++dep, k <<= 1) {
        tag[dep] = tag[dep] + k + (1LL << 60) & (1LL << dep) - 1;
      }
    } else {
      LL cur = x + tag[dep] & (1LL << dep) - 1;
      for (; ~dep; --dep, cur >>= 1) {
        printf("%lld%c", ((cur - tag[dep] + (1LL << 60)) & (1LL << dep) - 1) | (1LL << dep), dep ? ' ' : '\n');
      }
    }
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}