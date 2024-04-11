#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

int a[505][505];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n;
    read(n);
    ll ans = 0;
    int add = numeric_limits<int>::max();
    for (int i = 1; i <= 2 * n; ++i)
      for (int j = 1; j <= 2 * n; ++j)
        read(a[i][j]);
    for (int i = n + 1; i <= 2 * n; ++i)
      for (int j = n + 1; j <= 2 * n; ++j)
        ans += a[i][j];
    for (int i : {n + 1, 2 * n})
      for (int j : {1, n})
        add = min(add, a[i][j]);
    for (int i : {1, n})
      for (int j : {n + 1, 2 * n})
        add = min(add, a[i][j]);
    printf("%lld\n", ans + add);
  }
  return 0;
}