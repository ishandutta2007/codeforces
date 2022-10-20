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

const int N = 250005;

using pii = pair<int, int>;

int a[N];
pii mx[N * 2], mn[N * 2];
int n;

pii qmx(int l, int r) {
  pii ans = {0, 0};
  for (l += n, r += n; l != r; l >>= 1, r >>= 1) {
    if (l & 1) ans = max(ans, mx[l++]);
    if (r & 1) ans = max(ans, mx[--r]);
  }
  return ans;
}
pii qmn(int l, int r) {
  pii ans = {(int)1e9, 0};
  for (l += n, r += n; l != r; l >>= 1, r >>= 1) {
    if (l & 1) ans = min(ans, mn[l++]);
    if (r & 1) ans = min(ans, mn[--r]);
  }
  return ans;
}

int nmx[N], nmn[N];
int stk[N], top = 0;

int solve(int st) {
  int i = 0, ans = 0;
  while (i != n - 1) {
    if (!st) {
      int nxt = nmn[i];
      int mx = qmx(i, nxt).second;
      assert(mx != i);
      i = mx;
    }
    else {
      int nxt = nmx[i];
      int mn = qmn(i, nxt).second;
      assert(mn != i);
      i = mn;
    }
    st ^= 1;
    ++ans;
  }
  return ans;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  setbuf(stdout, 0);
#endif
  int T;
  read(T);
  while (T--) {
    read(n);
    for (int i = 0; i < n; ++i) {
      read(a[i]);
      mx[i + n] = {a[i], i}; mn[i + n] = {a[i], i};
    }
    if (n == 1) {
      puts("0");
      continue;
    }
    for (int i = n - 1; i; --i) {
      mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
      mn[i] = min(mn[i << 1], mn[i << 1 | 1]);
    }
    top = 0; *stk = n;
    for (int i = n - 1; i >= 0; --i) {
      while (top && a[stk[top]] > a[i]) --top;
      nmn[i] = stk[top];
      stk[++top] = i;
    }
    top = 0;
    for (int i = n - 1; i >= 0; --i) {
      while (top && a[stk[top]] < a[i]) --top;
      nmx[i] = stk[top];
      stk[++top] = i;
    }
    int ans = solve(a[1] > a[0] ? 0 : 1);
    printf("%d\n", ans);
  }
  return 0;
}