#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

ll v[105];
int a[105];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  read(n, m);
  for (int i = 0; i < n; ++i)
    read(v[i]);
  ll c[2] = {0, 0};
  for (int s = 2; s <= 2 * m; ++s) {
    for (int i = 0; i < n; ++i)
      a[i] = v[i] % s;
    sort(a, a + n);
    int l = s / 2, r = s - s / 2;
    int p = lower_bound(a, a + n, l) - a;
    int dist = min(l - 1, m - r);
    if (p) dist = min(dist, l - a[p - 1] - 1);
    if (p < n) dist = min(dist, a[p] - r);
    if (dist < 0) continue;
    int par = (n - p) & 1;
    if (par) {
      if (n > 1) dist = min(dist, l - a[n - 2] / 2 - 1);
    }
    else dist = min(dist, l - a[n - 1] / 2 - 1);
    if (dist >= 0)
      c[par] += 2 * dist + 1 + (l != r);
  }
  ll rem = ((ll)m * m - c[0] - c[1]) / 2;
  printf("%lld %lld %lld %lld\n", rem, rem, c[1], c[0]);
  return 0;
}