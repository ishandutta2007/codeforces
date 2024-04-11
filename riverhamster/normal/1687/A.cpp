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

const int N = 200005;

ll a[N];

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
    for (int i = 1; i <= n; ++i)
      read(a[i]), a[i] += a[i - 1];
    if (k <= n) {
      ll ans = 0;
      for (int i = k; i <= n; ++i)
        ans = max(ans, a[i] - a[i - k]);
      ans += (ll)k * (k - 1) / 2;
      printf("%lld\n", ans);
    }
    else {
      printf("%lld\n", a[n] + (ll)n * k - (ll)n * (n + 1) / 2);
    }
  }
  return 0;
}