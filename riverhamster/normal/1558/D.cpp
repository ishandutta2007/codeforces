#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int M = 998244353;
int power(int x, int y) {
  int p = 1;
  for (; y; y >>= 1, x = (ll)x * x % M)
    if (y & 1) p = (ll)p * x % M;
  return p;
}
int inv(int x) { return power(x, M - 2); }

vector<int> fac, ifac;

void prefac(int n) {
  fac.resize(n + 1); ifac.resize(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = (ll)fac[i - 1] * i % M;
  ifac[n] = inv(fac[n]);
  for (int i = n; i; --i)
    ifac[i - 1] = (ll)ifac[i] * i % M;
}

const int N = 200005;

int t[N];
const int LEN = 200000;

void insert(int p, int v) {
  for (; p <= LEN; p += p & -p)
    t[p] += v;
}
int kth(int k) {
  int p = 0;
  for (int i = __lg(LEN); i >= 0; --i) {
    int np = p | (1 << i);
    if (np <= LEN && t[np] < k)
      p = np, k -= t[np];
  }
  return p + 1;
}

int x[N], y[N];
int del[N];
int vis[N], vt = 0;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  prefac(400005);
  for (int i = 1; i <= LEN; ++i)
    t[i] = i & -i;
  while (T--) {
    ++vt;
    int n, m;
    read(n, m);
    for (int i = 1; i <= m; ++i)
      read(x[i], y[i]);
    int c = 0;
    for (int i = m; i >= 1; --i) {
      int p = kth(y[i]), q = kth(y[i] + 1);
      insert(p, -1);
      del[i] = p;
      if (vis[q] != vt)
        vis[q] = vt, ++c;
    }
    for (int i = 1; i <= m; ++i)
      insert(del[i], 1);
    printf("%lld\n", (ll)fac[2 * n - 1 - c] * ifac[n] % M * ifac[n - 1 - c] % M);
  }
  return 0;
}