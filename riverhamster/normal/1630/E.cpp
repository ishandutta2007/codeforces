#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <utility>
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

const int N = 1000005;
const int M = 998244353;

int power(int x, int y, int p = 1) {
  for (; y; y >>= 1, x = (ll)x * x % M)
    if (y & 1) p = (ll)p * x % M;
  return p;
}
int sub(int x, int y) { return x < y ? x - y + M : x - y; }

int cnt[N], phi[N], p[N], pc = 0;
bool np[N];
int d = 0, n;

int fac[N], ifac[N];

void prefac(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = (ll)fac[i - 1] * i % M;
  ifac[n] = power(fac[n], M - 2);
  for (int i = n; i; --i)
    ifac[i - 1] = (ll)ifac[i] * i % M;
}

void sieve(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!np[i]) p[++pc] = i, phi[i] = i - 1;
    for (int j = 1; j <= pc && p[j] * i <= n; ++j) {
      np[i * p[j]] = true;
      if (i % p[j] == 0) {
        phi[i * p[j]] = phi[i] * p[j];
        break;
      }
      phi[i * p[j]] = phi[i] * (p[j] - 1);
    }
  }
}

pair<int, int> solve(int gsize) {
  int c = fac[n / gsize], s = 0;
  for (int i = 0; i < n; ++i)
    c = (ll)c * ifac[cnt[i] / gsize] % M;
  int t = (ll)c * ifac[n / gsize] % M * fac[n / gsize - 2] % M;
  for (int i = 0; i < n; ++i)
    if (cnt[i] / gsize > 1)
      s = (s + (ll)t * fac[cnt[i] / gsize] % M * ifac[cnt[i] / gsize - 2]) % M;
  return {sub(c, s), c};
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  sieve(1000000);
  prefac(1000000);
  int T;
  read(T);
  while (T--) {
    read(n);
    fill(cnt, cnt + n, 0);
    for (int i = 0; i < n; ++i) {
      int x;
      read(x);
      ++cnt[x - 1];
    }
    int mxv = *max_element(cnt, cnt + n);
    if (mxv == n) {
      puts("1");
      continue;
    }
    d = 0;
    for (int i = 0; i < n; ++i)
      d = gcd(d, cnt[i]);
    int sum = 0, cnt = 0;
    for (int i = 1; i <= n; ++i)
      if (n % i == 0 && d % (n / i) == 0) {
        auto ret = solve(n / i);
        sum = (sum + (ll)ret.first * phi[n / i]) % M;
        cnt = (cnt + (ll)ret.second * phi[n / i]) % M;
      }
    printf("%d\n", power(cnt, M - 2, (ll)sum * n % M));
  }
  return 0;
}