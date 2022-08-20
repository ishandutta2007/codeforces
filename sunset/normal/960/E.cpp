#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}

template <typename T> inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T> inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}

const int N = 200005;
const int mod = 1e9 + 7;

int n, ans, a[N], b[N], par[N], siz[N][2];
vector <int> adj[N];
bool dep[N];

inline void DFS(int x, int p) {
  siz[x][dep[x]] = 1, par[x] = p;
  for (auto y : adj[x]) {
    if (y != p) {
      dep[y] = !dep[x];
      DFS(y, x);
      siz[x][0] += siz[y][0];
      siz[x][1] += siz[y][1];
    }
  }
}

inline void DFS(int x) {
  for (auto y : adj[x]) {
    if (y == par[x]) {
      b[x] = (1LL * (siz[1][dep[x]] - siz[1][!dep[x]] - siz[x][dep[x]] + siz[x][!dep[x]] + mod) * (siz[x][0] + siz[x][1]) + b[x]) % mod;
    } else {
      DFS(y);
      b[x] = (1LL * (siz[y][dep[x]] - siz[y][!dep[x]] + mod) * (n - siz[y][0] - siz[y][1]) + b[x]) % mod;
    }
  }
  b[x] = (b[x] + n) % mod;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 1; i <= n; ++i) {
    Read(a[i]), a[i] = (a[i] + mod) % mod;
  }
  for (int i = 1, x, y; i < n; ++i) {
    Read(x), Read(y);
    adj[x].pb(y), adj[y].pb(x);
  }
  DFS(1, 0), DFS(1);
  for (int i = 1; i <= n; ++i) {
    ans = (1LL * a[i] * b[i] + ans) % mod;
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}