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

const int N = 2e5 + 5;
const int M = 998244353;
void reduceR(int &x) { x += M & (x >> 31); }
int reduceN(int x) { return x + (M & (x >> 31)); }
int add(int x, int y) { return reduceN(x + y - M); }
int sub(int x, int y) { return reduceN(x - y); }
void inc(int &x, int y) { reduceR(x += y - M); }
void dec(int &x, int y) { reduceR(x -= y); }
int power(int x, int y, int p = 1) {
  for (; y; y >>= 1, x = (ll)x * x % M)
    if (y & 1) p = (ll)p * x % M;
  return p;
}
int inv(int x) { return power(x, M - 2); }

int a[N], b[N], cnt[N];
int fac[N], ifac[N];

void prefac(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = (ll)fac[i - 1] * i % M;
  ifac[n] = inv(fac[n]);
  for (int i = n; i; --i)
    ifac[i - 1] = (ll)ifac[i] * i % M;
}

int t[N];
void ins(int p, int v) {
  for (; p < N; p += p & -p)
    inc(t[p], v);
}
int query(int p) {
  int s = 0;
  for (; p; p &= p - 1)
    inc(s, t[p]);
  return s;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  read(n, m);
  prefac(max(n, m));
  for (int i = 1; i <= n; ++i)
    read(a[i]), ++cnt[a[i]];
  for (int i = 1; i <= m; ++i)
    read(b[i]);
  int ans = 1;
  int sum = 0;
  for (int i = 1; i <= 200000; ++i) {
    ans = (ll)ans * ifac[cnt[i]] % M;
    if (cnt[i]) ins(i, (ll)fac[cnt[i]] * ifac[cnt[i] - 1] % M);
  }
  for (int i = 0; i <= min(n, m - 1); ++i) {
    if (i) {
      if (!cnt[b[i]]) break;
      ans = (ll)ans * fac[cnt[b[i]]] % M;
      --cnt[b[i]];
      ans = (ll)ans * ifac[cnt[b[i]]] % M;
      int v = sub(query(b[i]), query(b[i] - 1));
      int nv = 0;
      if (cnt[b[i]]) nv = (ll)fac[cnt[b[i]]] * ifac[cnt[b[i]] - 1] % M;
      ins(b[i], sub(nv, v));
    }
    if (i == n) {
      inc(sum, 1);
      break;
    }
    sum = (sum + (ll)ans * query(b[i + 1] - 1) % M * fac[n - i - 1]) % M;
  }
  printf("%d\n", sum);
  return 0;
}