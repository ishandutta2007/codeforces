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

const int N = 400005;
const int mod = 1e9 + 7;

int n, m, k, p, s, P, S, tot, b[N], f[N], l[N], r[N], B[N], F[N], L[N], R[N], all[N];

inline int Qow(int x, int y) {
  int r = 1;
  for (; y; y >>= 1, x = 1LL * x * x % mod) {
    if (y & 1) {
      r = 1LL * r * x % mod;
    }
  }
  return r;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(k), Read(n), Read(m), all[tot++] = 0, all[tot++] = k;
  for (int i = 1; i <= n; ++i) {
    Read(l[i]), --l[i], Read(r[i]);
    all[tot++] = l[i], all[tot++] = r[i];
  }
  for (int i = 1; i <= m; ++i) {
    Read(L[i]), --L[i], Read(R[i]);
    all[tot++] = L[i], all[tot++] = R[i];
  }
  sort(all, all + tot), tot = unique(all, all + tot) - all;
  for (int i = 1; i <= n; ++i) {
    CheckMax(b[lower_bound(all, all + tot, r[i]) - all], (int)(lower_bound(all, all + tot, l[i]) - all + 1));
  }
  for (int i = 1; i <= m; ++i) {
    CheckMax(B[lower_bound(all, all + tot, R[i]) - all], (int)(lower_bound(all, all + tot, L[i]) - all + 1));
  }
  f[0] = s = 1;
  for (int i = 1; i < tot; ++i) {
    int t = s, T = S;
    f[i] = 1LL * (t + T) * (Qow(2, all[i] - all[i - 1]) - 2) % mod, s = (s + f[i]) % mod;
    f[i - 1] = (f[i - 1] + T) % mod, s = (s + T) % mod;
    F[i - 1] = (F[i - 1] + t) % mod, S = (S + t) % mod;
    for (; p < b[i]; s = (s - f[p++] + mod) % mod);
    for (; P < B[i]; S = (S - F[P++] + mod) % mod);
  }
  printf("%d\n", (s + S) % mod);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}