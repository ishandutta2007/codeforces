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

const int N = 2e5 + 5;

int l[N], r[N];
int n;

bool check(int lim) {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += (l[i] >= ans) && (r[i] >= lim - ans - 1);
  }
  return ans >= lim;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    read(n);
    for (int i = 1; i <= n; ++i)
      read(r[i], l[i]);
    int lb = 0, rb = n, ans = 0;
    while (lb <= rb) {
      int mid = (lb + rb) >> 1;
      if (check(mid)) ans = mid, lb = mid + 1;
      else rb = mid - 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}