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
// #define DBG(f...) printf("%3d: ", __LINE__), printf(f)
#define DBG(f...) void()
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

const int N = 605;
const int M = 1000000007;
const int inv2 = (M + 1) / 2;

int power(int x, int y, int p = 1) {
  for (; y; y >>= 1, x = (ll)x * x % M)
    if (y & 1) p = (ll)p * x % M;
  return p;
}
int inv(int x) { return power(x, M - 2); }

int a[N], p2[N];
int n, k;

int exactk() {
  vector<int> dp(k + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = k - 1; j >= 0; --j)
      dp[j + 1] = (dp[j + 1] + (ll)dp[j] * a[i]) % M;
  }
  return dp[k];
}

int same_sign() {
  vector<int> dp(k + 1);
  // +
  dp[0] = 1;
  int _ans1 = dp[k];
  int _ans2 = 0;
  for (int i = 1, tmp = 0; i <= n; ++i) {
    if (a[i] > 0) {
      for (int j = k - 1; j >= 0; --j)
        dp[j + 1] = (dp[j + 1] + (ll)dp[j] * a[i]) % M;
    }
    _ans1 = (2LL * _ans1 + tmp) % M;
    tmp = (tmp + dp[k]) % M; dp[k] = 0;
  }

  // -
  fill(all(dp), 0);
  dp[0] = 1;
  if (~k & 1) {
    for (int i = 1, tmp = 0; i <= n; ++i) {
      if (a[i] <= 0) {
        for (int j = k - 1; j >= 0; --j)
          dp[j + 1] = (dp[j + 1] + (ll)dp[j] * a[i]) % M;
      }
      _ans2 = (2LL * _ans2 + tmp) % M;
      tmp = (tmp + dp[k]) % M; dp[k] = 0;
    }
  }
  else {
    vector<int> sum(n + 1);
    for (int i = 1, cur = 0; i <= n; ++i) {
      if (a[i] > 0) sum[i] = (ll)a[i] * p2[n - i + cur] % M;
      else ++cur;
    }
    for (int i = n - 1; i; --i)
      sum[i] = (sum[i] + sum[i + 1]) % M;
    for (int i = 1, cur = 1; i <= n; ++i) {
      if (a[i] > 0) continue;
      cur = (ll)cur * inv2 % M;
      if (i != n) _ans2 = (_ans2 + (ll)dp[k - 1] * sum[i + 1] % M * cur) % M;
      for (int c = k - 1; c >= 0; --c)
        dp[c + 1] = (dp[c + 1] + (ll)dp[c] * a[i]) % M;
    }

    sort(a + 1, a + 1 + n, [](int x, int y) { return abs(x) < abs(y); });
    fill(all(dp), 0);
    int cnt = count_if(a + 1, a + 1 + n, [](int x) { return x <= 0; });
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      if (a[i] > 0) continue;
      --cnt;
      _ans2 = (_ans2 + (ll)dp[k] * p2[cnt]) % M;
      for (int c = k - 1; c >= 0; --c)
        dp[c + 1] = (dp[c + 1] + (ll)dp[c] * a[i]) % M;
    }
    sort(a + 1, a + 1 + n, [](int x, int y) { return abs(x) == abs(y) ? x < y : abs(x) > abs(y); });
  }

  return (_ans1 + _ans2) % M;
}

int normal() {
  auto sign = [](int x) { return x <= 0; };
  static int f[N][2], g[N][2];
  static int sum[N][2], sumsel[N][2];
  static int preprod[N][2], cnt[N][2];
  preprod[0][0] = preprod[0][1] = 1;

  for (int i = 1, p[2] = {1, 1}; i <= n; ++i) {
    if (!sign(a[i])) {
      sum[i][0] = (sum[i - 1][0] + (ll)p[1] * p2[n - i]) % M;
      sumsel[i][0] = (sumsel[i - 1][0] + (ll)p[1] * p2[n - i] % M * a[i]) % M;
    }
    else sum[i][0] = sum[i - 1][0], sumsel[i][0] = sumsel[i - 1][0];
    if (sign(a[i])) {
      sum[i][1] = (sum[i - 1][1] + (ll)p[0] * p2[n - i]) % M;
      sumsel[i][1] = (sumsel[i - 1][1] + (ll)p[0] * p2[n - i] % M * a[i]) % M;
    }
    else sum[i][1] = sum[i - 1][1], sumsel[i][1] = sumsel[i - 1][1];
    p[sign(a[i])] = (ll)p[sign(a[i])] * 2 % M;
  }
  for (int i = 1; i <= n; ++i) {
    preprod[i][0] = preprod[i - 1][0];
    preprod[i][1] = preprod[i - 1][1];
    preprod[i][sign(a[i])] = (ll)preprod[i][sign(a[i])] * inv2 % M;
  }
  for (int i = 1; i <= n; ++i)
    for (int j : {0, 1})
      cnt[i][j] = cnt[i - 1][j] + (sign(a[i]) == j);

  f[0][0] = 1;

  int ans = 0;

  for (int i = 1; i <= n; ++i) {
    memset(g, 0, sizeof(g));
    int sgn = sign(a[i]);
    int inv_ai = inv(a[i]);
    for (int c = k - 1; c >= 0; --c) {
      g[c + 1][sgn] = (ll)f[c][0] * a[i] % M;
      g[c + 1][!sgn] = (ll)f[c][1] * a[i] % M;
    }
    for (int j = i + 1; j <= n; ++j) {
      if (sign(a[i]) == sign(a[j])) continue;
      ans = (ans + (ll)g[k - 1][sign(a[j])] * a[j] % M * (p2[n - j] - 1)) % M;
      int inv_aj = inv(a[j]);

      int val = (ll)g[k - 1][!sign(a[j])] * a[j] % M;

      int pos = j + 1;
      for (int p = j + 1; p <= n; ++p) {
        if (sign(a[j]) != sign(a[p]))
          ans = (ans + (ll)val * p2[n - p] % M * a[p] % M * inv_aj) % M;
        else {
          int lim = ((ll)abs(a[p]) * abs(a[j]) + abs(a[i]) - 1) / abs(a[i]);
          pos = max(pos, p);
          while (pos < n && abs(a[pos + 1]) >= lim) ++pos;
          int si = sign(a[i]);
          int tmp = (ll)preprod[p][!si] * inv_aj % M * (sumsel[pos][si] - sumsel[p][si]) % M;
          tmp = (tmp + (ll)preprod[p][!si] * inv_ai % M * a[p] % M * (sum[n][si] - sum[pos][si])) % M;
          ans = (ans + (ll)tmp * val) % M;
          ans = (ans + (ll)val * inv_ai % M * a[p] % M * p2[cnt[n][sign(a[p])] - cnt[p][sign(a[p])]]) % M;
        }
      }

      for (int c = k - 1, sgn = sign(a[j]); c >= 0; --c) {
        g[c + 1][sgn] = (g[c + 1][sgn] + (ll)g[c][0] * a[j]) % M;
        g[c + 1][!sgn] = (g[c + 1][!sgn] + (ll)g[c][1] * a[j]) % M;
      }
    }
    for (int c = k - 1; c >= 0; --c) {
      f[c + 1][sgn] = (f[c + 1][sgn] + (ll)f[c][0] * a[i]) % M;
      f[c + 1][!sgn] = (f[c + 1][!sgn] + (ll)f[c][1] * a[i]) % M;
    }
  }

  return ans;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, k);
  p2[0] = 1;
  for (int i = 1; i <= n; ++i)
    p2[i] = 2 * p2[i - 1] % M;
  for (int i = 1; i <= n; ++i)
    read(a[i]);

  if (k == 1) {
    sort(a + 1, a + 1 + n, [](int x, int y) { return x > y; });
    int ans = 0;
    for (int i = 1; i <= n; ++i)
      ans = (ans + (ll)a[i] * p2[n - i]) % M;
    ans = (ans + M) % M;
    printf("%d\n", ans);
    return 0;
  }

  sort(a + 1, a + 1 + n, [](int x, int y) { return abs(x) == abs(y) ? x < y : abs(x) > abs(y); });

  int ans1 = exactk();
  int ans2 = same_sign();
  int ans3 = normal();

  int ans = (0LL + ans1 + ans2 + ans3) % M;
  ans = (ans + M) % M;
  printf("%d\n", ans);
  return 0;
}