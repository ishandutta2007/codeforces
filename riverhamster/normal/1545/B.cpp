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

const int N = 100005;
const int M = 998244353;

void reduceR(int &x) { x += M & (x >> 31); }
int reduceN(int x) { return x + (M & (x >> 31)); }
int add(int x, int y) { return reduceN(x + y - M); }
int sub(int x, int y) { return reduceN(x - y); }
void inc(int &x, int y) { reduceR(x += y - M); }
void dec(int &x, int y) { reduceR(x -= y); }
int power(int x, int y) {
  int p = 1;
  for (; y; y >>= 1, x = (ll)x * x % M)
    if (y & 1) p = (ll)p * x % M;
  return p;
}
int inv(int x) { return power(x, M - 2); }

char s[N];
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

int binom(int n, int m) {
  if (n < m || m < 0) return 0;
  return (ll)fac[n] * ifac[m] % M * ifac[n - m] % M;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  prefac(100000);
  while (T--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int cnt = 0, d2 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
      cnt += s[i] - '0';
      if (s[i] == '0') d2 += cnt / 2, c1 += cnt & 1, cnt = 0;
    }
    d2 += cnt / 2;
    c1 += cnt & 1;
    printf("%d\n", binom(n - c1 - d2, d2));
  }
  return 0;
}