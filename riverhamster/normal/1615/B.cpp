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

int s[200005][20];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  for (int i = 1; i <= 200000; ++i) {
    for (int j = 0; j < 20; ++j)
      s[i][j] = ((i >> j) & 1) + s[i - 1][j];
  }
  int T;
  read(T);
  while (T--) {
    int l, r;
    read(l, r);
    int ans = 0;
    for (int p = 0; p < 20; ++p) {
      ans = max(ans, s[r][p] - s[l - 1][p]);
    }
    printf("%d\n", r - l + 1 - ans);
  }
  return 0;
}