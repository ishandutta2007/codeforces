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

const int N = 205;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll f[N][N], g[N][N], h[N][N], hg[N][N];
ll a[N], b[N], c[N], sa[N], sb[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, t, K;
  read(n, t, K);
  for (int i = 1; i <= n; ++i) {
    read(a[i], b[i], c[i]);
    sa[i] = sa[i - 1] + a[i];
    sb[i] = sb[i - 1] + b[i];
  }
  a[n + 1] = K; b[n + 1] = K; c[n + 1] = 1e17;
  sa[n + 1] = sa[n] + K; sb[n + 1] = sb[n] + K;
  memset(f, 0x3f, sizeof(f));
  memset(g, 0x3f, sizeof(g));
  memset(h, 0x3f, sizeof(h));
  memset(hg, 0x3f, sizeof(hg));
  memset(f[0], 0, sizeof(f[0]));
  memset(g[0], 0, sizeof(g[0]));
  memset(h[0], 0, sizeof(h[0]));
  memset(hg[0], 0, sizeof(hg[0]));

  for (int i = 1; i <= n + 1; ++i) {
    f[i][0] = h[i][0] = hg[i][0] = 0;
    g[i][0] = (sa[i - 1] + K - 1) / K;
    if (g[i][0] * K > sa[i])
      g[i][0] = INF;
    for (int j = 1; j <= t; ++j) {
      ll v = a[i] + b[i] * j;
      if (v <= c[i] && f[i - 1][j] <= 1e17) {
        f[i][j] = f[i - 1][j];
        g[i][j] = (sa[i - 1] + sb[i - 1] * j + K - 1) / K;
      }
      for (int p = 1; p <= j; ++p) {
        ll before = g[i][p - 1];
        if (before > 1e17) continue;
        ll v = sa[i] + (p - 1) * sb[i] - before * K;
        ll r = v % K;
        ll add = (j - p + 1) * b[i];
        if (r + add <= c[i]) {
          ll at = max(0LL, (v + add - c[i] + K - 1) / K);
          ll after = h[i - 1][j - p + 1];
          if (after > 1e17) continue;
          f[i][j] = min(f[i][j], before + at + after);
          ll extra = (sb[i - 1] * (j - p + 1) + K - 1) / K;
          g[i][j] = min(g[i][j], before + at + extra);
        }
      }
      if (f[i][j] <= 1e17 && f[i][j] * K > sa[i] + sb[i] * (j - 1))
        f[i][j] = INF, g[i][j] = INF;//, puts("UPDATE 1");
      else if (g[i][j] <= 1e17 && g[i][j] * K > sa[i] + sb[i] * j)
        g[i][j] = INF;

      // identical transitions for h
      v = b[i] * j;
      if (v <= c[i]) h[i][j] = h[i - 1][j];
      for (int p = 1; p <= j; ++p) {
        ll before = hg[i][p - 1];
        if (before > 1e17) continue;
        ll v = (p - 1) * sb[i] - before * K;
        ll r = v % K;
        ll add = (j - p + 1) * b[i];
        if (r + add <= c[i]) {
          ll at = max(0LL, (v + add - c[i] + K - 1) / K);
          ll after = h[i - 1][j - p + 1];
          if (after > 1e17) continue;
          h[i][j] = min(h[i][j], before + at + after);
          ll extra = (sb[i - 1] * (j - p + 1) + K - 1) / K;
          hg[i][j] = min(hg[i][j], before + at + extra);
        }
      }
      if (h[i][j] <= 1e17 && h[i][j] * K > sb[i] * (j - 1))
        h[i][j] = INF, hg[i][j] = INF;
      else if (hg[i][j] <= 1e17 && hg[i][j] * K > sb[i] * j)
        hg[i][j] = INF;
    }
  }
  printf("%lld\n", f[n + 1][t]);
  return 0;
}