#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
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

int a[75];

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
      read(a[i]);
    int ans = max(n - 2, 0);
    for (int i = 1; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j) {
        int cur = 0;
        for (int p = 1; p <= n; ++p) {
          if (p == i || p == j) continue;
          int pi = (p - j) * (a[i] - a[p]);
          int pj = (p - i) * (a[j] - a[p]);
          if (pi != pj) ++cur;
        }
        ans = min(ans, cur);
      }
    printf("%d\n", ans);
  }
  return 0;
}