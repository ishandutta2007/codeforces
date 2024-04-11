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

const int N = 262145;
const int M = 20;
const int G = 3;
const int mod = 998244353;

int D, L, W[M], R[N];

inline int Qow(int x, int y) {
  int r = 1;
  for (; y; y >>= 1, x = 1LL * x * x % mod) {
    if (y & 1) {
      r = 1LL * r * x % mod;
    }
  }
  return r;
}

inline void DFT(int *x) {
  for (int i = 0; i < D; ++i) {
    if (i < R[i]) {
      swap(x[i], x[R[i]]);
    }
  }
  for (int i = 1, l = L - 1; i < D; i <<= 1, --l) {
    for (int j = 0; j < D; j += i << 1) {
      for (int k = 0, w = 1, u, v; k < i; ++k, w = 1LL * w * W[l] % mod) {
        u = x[j + k], v = 1LL * w * x[j + k + i] % mod;
        x[j + k] = (u + v) % mod, x[j + k + i] = (u - v + mod) % mod;
      }
    }
  }
}

inline vector <int> Mul(vector <int> a, vector <int> b) {
  static int x[N], y[N];
  int n = a.size(), m = b.size();
  vector <int> c(n + m - 1);
  for (D = 1, L = 0; D < n + m - 1; D <<= 1, ++L);
  W[0] = Qow(G, mod - 1 >> L);
  for (int i = 1; i < L; ++i) {
    W[i] = 1LL * W[i - 1] * W[i - 1] % mod;
  }
  for (int i = 0; i < D; ++i) {
    x[i] = i < n ? a[i] : 0, y[i] = i < m ? b[i] : 0;
    R[i] = (R[i >> 1] >> 1) | ((i & 1) << L - 1);
  }
  DFT(x), DFT(y);
  for (int i = 0; i < D; ++i) {
    x[i] = 1LL * x[i] * y[i] % mod;
  }
  W[0] = Qow(W[0], mod - 2);
  for (int i = 1; i < L; ++i) {
    W[i] = 1LL * W[i - 1] * W[i - 1] % mod;
  }
  DFT(x);
  int v = Qow(D, mod - 2);
  for (int i = 0; i < n + m - 1; ++i) {
    c[i] = 1LL * x[i] * v % mod;
  }
  return c;
}

int n, m, ans, tim, tot, lst[N], mem[N], siz[N], seq[N], sum[N];
vector <int> adj[N];

inline vector <int> Solve(int l, int r) {
  if (l == r) {
    return vector <int> {1, seq[l]};
  } else {
    int mid = l + r >> 1;
    return Mul(Solve(l, mid), Solve(mid + 1, r));
  }
}

inline void DFS(int x, int p) {
  siz[x] = 1;
  for (auto y : adj[x]) {
    if (y != p) {
      DFS(y, x);
      ans = (1LL * sum[x] * sum[y] + ans) % mod;
      siz[x] += siz[y], sum[x] = (sum[x] + sum[y]) % mod;
    }
  }
  tot = 0;
  for (auto y : adj[x]) {
    if (y != p) {
      seq[tot++] = siz[y];
    }
  }
  vector <int> ply;
  if (tot) {
    ply = Solve(0, tot - 1);
  } else {
    ply = vector <int> {1};
  }
  for (int i = 0, cur = 1; i <= m && i < ply.size(); ++i) {
    sum[x] = (1LL * cur * ply[i] + sum[x]) % mod;
    cur = 1LL * cur * (m - i) % mod;
  }
  if (p) {
    ply.push_back(0);
    for (int i = ply.size() - 2; ~i; --i) {
      ply[i + 1] = (1LL * ply[i] * (n - siz[x]) + ply[i + 1]) % mod;
    }
  }
  ++tim;
  for (auto y : adj[x]) {
    if (y != p) {
      int s = siz[y];
      if (lst[s] != tim) {
        lst[s] = tim, mem[s] = 0;
        for (int i = 0, cur = 1, rem = 0; i <= m && i < ply.size() - 1; ++i) {
          rem = (ply[i] - 1LL * rem * s % mod + mod) % mod;
          mem[s] = (1LL * cur * rem + mem[s]) % mod;
          cur = 1LL * cur * (m - i) % mod;
        }
      }
      ans = (1LL * mem[s] * sum[y] + ans) % mod;
    }
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 1, x, y; i < n; ++i) {
    Read(x), Read(y);
    adj[x].pb(y), adj[y].pb(x);
  }
  if (m == 1) {
    ans = 1LL * n * (n - 1) / 2 % mod;
  } else {
    DFS(1, 0);
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}