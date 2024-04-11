#include <cstdio>
#include <cctype>
#include <cstring>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)

using ll = long long;

const int N = 205;
int M;

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

int n;
int dp[N][30][N];
int fac[N], ifac[N];
int lim[N];

void prefac(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = (ll)fac[i - 1] * i % M;
  ifac[n] = inv(fac[n]);
  for (int i = n; i; --i)
    ifac[i - 1] = (ll)ifac[i] * i % M;
}

int solve(int st) {
  int min_sum = 0;
  for (int i = st + 1; i <= n; ++i)
    min_sum += i - st;
  if (min_sum > st) return 0;

  for (int i = 1; i <= st; ++i)
    lim[i] = 0;
  for (int i = st + 1; i <= n; ++i)
    lim[i] = i + 1 - st;

  int V = n + 1 - st;

  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= st; ++i)
    dp[i][0][0] = ifac[i];
  for (int i = 1; i < n; ++i)
    for (int lst = 0; lst <= V; ++lst)
      for (int sum = 0; sum <= st; ++sum) {
        if (!dp[i][lst][sum] || (lst + 1) * (n - i - 1) + sum + V > st) continue;
        for (int val = lst + 1; val <= V; ++val)
          for (int j = i + 1, s = sum + val; j <= n && val >= lim[j] && s <= st; ++j, s += val)
            dp[j][val][s] = (dp[j][val][s] + (ll)dp[i][lst][sum] * ifac[j - i]) % M;
      }

  ll ans = 0;
  for (int s = 0; s <= st; ++s)
    ans += dp[n][V][s];
  return ans % M * fac[n] % M;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &M);
  prefac(n);
  ll ans = 1; // all n
  for (int i = 1; i <= n + 1; ++i)
    ans += solve(i);
  printf("%lld\n", ans % M);
  return 0;
}