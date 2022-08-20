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

const int N = 100005;
const int M = 10000005;
const int mod = 1e9 + 7;

int n, m, tot, a[N], ans[N], dep[N], cnt[M], mip[M], pri[M], anc[17][N];
vector <pii> add[N], sub[N];
vector <int> adj[N];

inline int Qow(int x, int y) {
  int r = 1;
  for (; y; y >>= 1, x = 1LL * x * x % mod) {
    if (y & 1) {
      r = 1LL * r * x % mod;
    }
  }
  return r;
}

inline void DFS(int x) {
  for (int i = 1; i < 17; ++i) {
    anc[i][x] = anc[i - 1][anc[i - 1][x]];
  }
  for (auto y : adj[x]) {
    if (y != anc[0][x]) {
      anc[0][y] = x, dep[y] = dep[x] + 1, DFS(y);
    }
  }
}

inline int LCA(int x, int y) {
  if (dep[x] < dep[y]) {
    swap(x, y);
  }
  if (dep[x] > dep[y]) {
    for (int i = 16; ~i; --i) {
      if (dep[x] - dep[y] >> i & 1) {
        x = anc[i][x];
      }
    }
  }
  if (x == y) {
    return x;
  }
  for (int i = 16; ~i; --i) {
    if (anc[i][x] != anc[i][y]) {
      x = anc[i][x], y = anc[i][y];
    }
  }
  return anc[0][x];
}

inline void I(int x) {
  while (x != 1) {
    int p = mip[x], c = 0;
    while (x % p == 0) {
      x /= p, ++c;
    }
    for (int i = 1, t = 1; i <= c; ++i) {
      ++cnt[t *= p];
    }
  }
}

inline void O(int x) {
  while (x != 1) {
    int p = mip[x], c = 0;
    while (x % p == 0) {
      x /= p, ++c;
    }
    for (int i = 1, t = 1; i <= c; ++i) {
      --cnt[t *= p];
    }
  }
}

inline int C(int x) {
  int r = 1;
  while (x != 1) {
    int p = mip[x], b = 0, c = 0;
    while (x % p == 0) {
      x /= p, ++c;
    }
    for (int i = 1, t = 1; i <= c; ++i) {
      b += cnt[t *= p];
    }
    r = 1LL * r * Qow(p, b) % mod;
  }
  return r;
}

inline void Solve(int x) {
  I(a[x]);
  for (auto p : add[x]) {
    ans[p.Y] = 1LL * ans[p.Y] * C(p.X) % mod;
  }
  for (auto p : sub[x]) {
    ans[p.Y] = 1LL * ans[p.Y] * Qow(C(p.X), mod - 3) % mod;
  }
  for (auto y : adj[x]) {
    if (y != anc[0][x]) {
      Solve(y);
    }
  }
  O(a[x]);
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  n = 10000000;
  for (int i = 2; i <= n; ++i) {
    if (!mip[i]) {
      mip[i] = i, pri[++tot] = i;
    }
    for (int j = 1; i * pri[j] <= n; ++j) {
      mip[i * pri[j]] = pri[j];
      if (i % pri[j] == 0) {
        break;
      }
    }
  }
  Read(n);
  for (int i = 1, x, y; i < n; ++i) {
    Read(x), Read(y);
    adj[x].pb(y), adj[y].pb(x);
  }
  for (int i = 1; i <= n; ++i) {
    Read(a[i]);
  }
  DFS(1);
  Read(m);
  for (int i = 1, x, y, z, w; i <= m; ++i) {
    Read(x), Read(y), Read(w), z = LCA(x, y), ans[i] = __gcd(a[z], w);
    add[x].pb(mp(w, i)), add[y].pb(mp(w, i)), sub[z].pb(mp(w, i));
  }
  Solve(1);
  for (int i = 1; i <= m; ++i) {
    printf("%d\n", ans[i]);
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}