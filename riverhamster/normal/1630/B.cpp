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

int cnt[200005], a[200005];
int ans, L, R;

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
    fill(cnt + 1, cnt + 1 + n, 0);
    for (int i = 1; i <= n; ++i) {
      int x;
      read(x);
      a[i] = x;
      ++cnt[x];
    }
    int lim = 0;
    while (lim - (n - lim) < k) ++lim;
    int l = 1, sum = 0;
    ans = n + 1;
    for (int r = 1; r <= n; ++r) {
      sum += cnt[r];
      while (sum - cnt[l] >= lim) sum -= cnt[l++], assert(l <= r);
      if (sum >= lim) {
        if (r - l + 1 < ans) {
          ans = r - l + 1;
          L = l; R = r;
        }
      }
    }
    printf("%d %d\n", L, R);
    for (int i = 1, c = 1; c <= k; ++c) {
      if (c == k) printf("%d %d\n", i, n);
      else {
        int r = i, s = (a[i] >= L && a[i] <= R ? 1 : -1);
        while (s <= 0) {
          ++r;
          s += (a[r] >= L && a[r] <= R ? 1 : -1);
        }
        printf("%d %d\n", i, r);
        i = r + 1;
      }
    }
  }
  return 0;
}