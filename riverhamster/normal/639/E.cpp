#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 1.5e5 + 5;
const double eps = 1e-8;

struct item {
  int p, t;
  ll tl, tr;
  bool operator<(const item &rhs) const { return (ll)p * rhs.t > (ll)t * rhs.p; }
} a[N];
ll ts[N];

int n;

bool check(double c) {
  double mxp = 0;
  int last = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == n || a[i].p != a[i + 1].p) {
      for (int j = last + 1; j <= i; ++j)
        if (a[j].p * (1.0 - c * (double)a[j].tr / ts[n]) < mxp)
          return false;
      for (int j = last + 1; j <= i; ++j)
        mxp = max(mxp, a[j].p * (1.0 - c * (double)a[j].tl / ts[n]));
      last = i;
    }
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n);
  for (int i = 1; i <= n; ++i)
    read(a[i].p);
  for (int i = 1; i <= n; ++i)
    read(a[i].t);
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i)
    ts[i] = ts[i - 1] + a[i].t;
  int last = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == n || a[i] < a[i + 1]) {
      for (int j = last + 1; j <= i; ++j)
        a[j].tl = ts[last] + a[j].t, a[j].tr = ts[i];
      last = i;
    }
  }

  sort(a + 1, a + 1 + n, [](const item &a, const item &b) {
    return a.p < b.p;
  });

  double l = 0, r = 1;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    if (check(mid)) l = mid;
    else r = mid;
  }
  printf("%.9lf\n", l);
  return 0;
}