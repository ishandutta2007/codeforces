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

vector<pair<int, int>> ops;
int cnt[20];

void F(int n, int e) {
  if (n == 0) return;
  if (n == 1) {
    ++cnt[e];
    return;
  }
  if (n == 2) {
    ++cnt[e]; ++cnt[e + 1];
    return;
  }
  if (!(n & (n - 1))) {
    F(n - 1, e);
    ++cnt[__lg(n) + e];
    return;
  }
  int t = __lg(n), m = 1 << t;
  int i;
  ++cnt[t + e];
  for (i = 1; m + i <= n; ++i) {
    ops.emplace_back((m + i) << e, (m - i) << e);
    ++cnt[t + 1 + e];
  }
  --i;
  F(i, e + 1);
  F(m - i - 1, e);
}

void solve() {
  int n;
  read(n);
  if (n == 2) {
    puts("-1");
    return;
  }
  ops.clear();
  memset(cnt, 0, sizeof(cnt));
  F(n, 0);
  int lim = n & (n - 1) ? __lg(n) + 1 : __lg(n);
  bool eq = false;
  for (int i = 0; i <= lim; ++i) {
    if (cnt[i] > 1) {
      cnt[i] -= 2;
      ops.emplace_back(1 << i, 1 << i);
      ++cnt[i + 1];
      eq = true;
      break;
    }
  }
  assert(eq);
  for (int i = 0; i < lim; ++i) {
    while (cnt[i]) {
      --cnt[i]; ++cnt[i + 1];
      ops.emplace_back(0, 1 << i);
      ops.emplace_back(1 << i, 1 << i);
    }
  }
  ops.emplace_back(0, 1 << lim);
  printf("%d\n", (int)ops.size());
  for (const auto &p : ops)
    printf("%d %d\n", p.first, p.second);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) solve();
  return 0;
}