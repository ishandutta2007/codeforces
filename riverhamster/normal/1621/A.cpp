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

#define FOR(i, l, r) for (int i = (l); i <= (r); ++i)

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

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n, k;
    read(n, k);
    if (k > (n + 1) / 2) {
      puts("-1");
      continue;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (i & 1) {
        ++cnt;
        for (int j = 1; j <= n; ++j)
          if (j == i && cnt <= k) putchar('R');
          else putchar('.');
        putchar('\n');
      }
      else {
        FOR (j, 1, n)
          putchar('.');
        putchar('\n');
      }
    }
  }
  return 0;
}