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

const int N = 200005;
const int M = 1000000007;

int out[N * 2];

int power(int x, int y, int p = 1) {
  for (; y; y >>= 1, x = (ll)x * x % M)
    if (y & 1) p = (ll)p * x % M;
  return p;
}

int fac[N * 2], ifac[N * 2];

void prefac(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = (ll)fac[i - 1] * i % M;
  ifac[n] = power(fac[n], M - 2);
  for (int i = n; i; --i)
    ifac[i - 1] = (ll)ifac[i] * i % M;
}

int binom(int n, int m) {
  if (m < 0 || m > n) return 0;
  return (ll)fac[n] * ifac[m] % M * ifac[n - m] % M;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  prefac(400008);
  int n;
  read(n);
  int x;
  read(x);
  if (x == 0) {
    puts("0");
    return 0;
  }
  out[x] = 1;
  for (int i = 1; i <= n + 1; ++i) {
    int y;
    if (i <= n) read(y);
    else y = 0;
    while (x > y) out[x + i - 1] = (out[x + i - 1] + binom(x - 1 + i - 1, i - 1)) % M, --x;
    if (!y) break;
    out[y + i] = (out[y + i] + binom(y - 1 + i, i)) % M;
  }
  int cur = 1, ans = 1;
  for (int i = 1; i <= 400006; ++i) {
    cur = (2 * cur - out[i]) % M;
    cur = (cur + M) % M;
    ans = (ans + cur) % M;
  }
  printf("%d\n", ans);
  return 0;
}