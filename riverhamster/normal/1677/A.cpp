#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
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

const int N = 5005;

int p[N], ps[N][N], ss[N][N];

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
    for (int i = 1; i <= n; ++i)
      read(p[i]);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        ps[i][j] = ps[i - 1][j] + (p[i] <= j);
    for (int j = 1; j <= n; ++j)
      ss[n + 1][j] = 0;
    for (int i = n; i >= 1; --i)
      for (int j = 1; j <= n; ++j)
        ss[i][j] = ss[i + 1][j] + (p[i] <= j);
    ll ans = 0;
    for (int i = 1; i < n; ++i)
      for (int j = i + 1; j <= n; ++j)
        ans += ps[i - 1][p[j] - 1] * ss[j + 1][p[i] - 1];
    printf("%lld\n", ans);
  }
  return 0;
}