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

#define FOR(i, l, r) for (int i = (l); i <= (r); ++i)

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
    int n, mn = 1 << 30, mnv = 1 << 30, mx = -(1 << 30), mxv = 1 << 30;
    int mxcov = 0x7fffffff, cl = -1, cr = -1;
    read(n);
    FOR(i, 1, n) {
      int l, r, c;
      read(l, r, c);
      if (l < mn || (l == mn && c < mnv)) { mn = l; mnv = c; }
      if (r > mx || (r == mx && c < mxv)) { mx = r; mxv = c; }
      if (cl != mn || cr != mx) mxcov = 0x7fffffff;
      if (l == mn && r == mx) {
        cl = l; cr = r;
        mxcov = min(mxcov, c);
      }
      printf("%d\n", min(mxcov, mnv + mxv));
    }
  }
  return 0;
}