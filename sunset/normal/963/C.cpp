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

const int N = 200005;

LL g, all, x[N], y[N], z[N];
map <LL, LL> a, b;
int n, ans;

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 0; i < n; ++i) {
    Read(x[i]), Read(y[i]), Read(z[i]);
    a[x[i]] += z[i], b[y[i]] += z[i];
    all += z[i], g = __gcd(g, z[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (fabs((LD)a[x[i]] / all - (LD)z[i] / b[y[i]]) > (LD)1e-16) {
      puts("0");
      return 0;
    }
  }
  for (LL i = 1; i * i <= g; ++i) {
    if (g % i == 0) {
      ++ans;
      if (i * i != g) {
        ++ans;
      }
    }
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}