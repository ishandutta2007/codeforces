#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

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
const int N = 1000005;

void reduceR(int &x) { x += M & (x >> 31); }
int reduceN(int x) { return x + (M & (x >> 31)); }
void inc(int &x, int y) { reduceR(x += y - M); }
void dec(int &x, int y) { reduceR(x -= y); }
int add(int x, int y) { return reduceN(x + y - M); }
int sub(int x, int y) { return reduceN(x - y); }
constexpr int power(int x, int y) {
  int p = 1;
  for (; y; y >>= 1, x = (ll)x * x % M)
    if (y & 1)
      p = (ll)p * x % M;
  return p;
}
constexpr int inv(int x) { return power(x, M - 2); }

const int inv6 = inv(6);

int rp2(int x) { return (ll)x * (x + 1) / 2 % M; }
int rp3(int x) { return (ll)x * (x + 1) % M * (x + 2) % M * inv6 % M; }

int dp[N], dps[N], ht[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  if (n == 1) { puts("5"); return 0; }
  dp[0] = 1; dps[0] = 1;
  dp[1] = 2; dps[1] = 3; ht[1] = 1;
  for (int i = 2; i <= n; ++i) {
    dp[i] = ((ll)dp[i - 1] * dps[i - 2] + dp[i - 1] + rp2(dp[i - 1])) % M;
    dps[i] = add(dps[i - 1], dp[i]);
    ht[i] = sub(dp[i], dp[i - 1]);
  }
  int res = 2LL * (dp[n] + rp3(dp[n - 1]) + (ll)rp2(dp[n - 1]) * dps[n - 2] + (ll)dp[n - 1] * rp2(dps[n - 2])) % M - 1;
  reduceR(res);
  for (int i = 1; i < n; ++i)
    res = (res + (ll)ht[i] * sub(dp[n - i - 1], 1)) % M;
  printf("%d\n", res);
  return 0;
}