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

namespace io {
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT;
  char getc () { return (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++); }
  template <class T> void read(T &x) {
    char ch; int f = 1;
    x = 0;
    while (isspace(ch = getc()));
    if (ch == '-') ch = getc(), f = -1;
    do x = x * 10 + (ch - '0'); while (isdigit(ch = getc()));
    x *= f;
  }
  template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }
}
using io::read;

const int N = 4e6 + 5;
const int M = 998244389;

int a[N];
int c[N], s[N];
int n, d = 0, V = 0;
int mu[N], p[N], pc = 0;
bool np[N];

void sieve(int n) {
  mu[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!np[i]) p[++pc] = i, mu[i] = -1;
    for (int j = 1; j <= pc && i * p[j] <= n; ++j) {
      np[i * p[j]] = true;
      if (i % p[j] == 0) { mu[i * p[j]] = 0; break; }
      mu[i * p[j]] = -mu[i];
    }
  }
}

int main() {
  read(n);
  for (int i = 0; i < n; ++i)
    read(a[i]), d = __gcd(d, a[i]), V = max(V, a[i]);
  if (d != 1) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < n; ++i)
    c[a[i]] = 1;
  int ans = 1;
  if (c[1]) {
    printf("%d\n", ans);
    return 0;
  }
  V = 4e6;
  for (int i = 1; i <= V; ++i) {
    s[i] = c[i];
    for (int j = i * 2; j <= V; j += i)
      s[i] += c[j];
  }
  sieve(V);
  memcpy(c, s, sizeof(s));
  while (true) {
    ++ans;
    int sum = 0;
    for (int i = 1; i <= V; ++i)
      c[i] = (ll)c[i] * s[i] % M;
    for (int i = 1; i <= V; ++i)
      sum = (sum + (ll)c[i] * mu[i]) % M;
    if (sum) break;
  }
  printf("%d\n", ans);
  return 0;
}