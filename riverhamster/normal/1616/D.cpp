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

const int N = 50005;

ll a[N], s[N];
int p[N], pc = 0;
struct item {
  int l, r;
} it[N * 2];
int ic = 0;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n, lim;
    read(n);
    for (int i = 1; i <= n; ++i)
      read(a[i]);
    for (int i = 1; i <= n; ++i)
      s[i] = a[i] + s[i - 1];
    read(lim);
    pc = 0;
    for (int i = 1; i <= n; ++i)
      if (a[i] < lim) p[++pc] = i;
    ic = 0;
    for (int i = 1; i <= pc; ++i) {
      if (p[i] > 1 && a[p[i]] + a[p[i] - 1] < 2 * lim) it[++ic] = {p[i] - 1, p[i]};
      if (p[i] < n && a[p[i] + 1] >= lim && a[p[i]] + a[p[i] + 1] < 2 * lim) it[++ic] = {p[i], p[i] + 1};
      else if (i < pc && a[p[i] + 1] >= lim && a[p[i + 1]] + a[p[i + 1] - 1] >= 2 * lim && s[p[i + 1]] - s[p[i] - 1] < ll(p[i + 1] - p[i] + 1) * lim) it[++ic] = {p[i], p[i + 1]};
    }
    sort(it + 1, it + 1 + ic, [](const item &a, const item &b) { return a.l < b.l; });
    // for (int i = 1; i <= ic; ++i)
    //   printf("%d %d\n", it[i].l, it[i].r);
    bool ok = false;
    int ans = 0;
    it[ic + 1].l = -1000000000;
    for (int i = 1; i <= ic; ++i) {
      if (ok) ok = false;
      else {
        ++ans;
        if (it[i].r == it[i + 1].l) ok = true;
      }
    }
    printf("%d\n", n - ans);
  }
  return 0;
}