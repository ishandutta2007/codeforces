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

const int N = 200005;

int a[N];

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
    for (int i = 0; i < n; ++i)
      read(a[i]);
    int ans = 2;
    for (int i = 0; i < n - 1; ++i) {
      int p = upper_bound(a + i + 1, a + n, a[i]) - a;
      int cur = p - i;
      while (p < n) {
        ++cur;
        p = lower_bound(a + p + 1, a + n, (a[p] - a[i]) * 2 + a[i]) - a;
      }
      ans = max(ans, cur);
    }
    printf("%d\n", n - ans);
  }
  return 0;
}