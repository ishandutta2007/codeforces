#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 405;
ll dp[N][N], f[N], rf[N], c[N][N], w[N];
int n, m;

ll pw(ll x, ll k) {
  ll r = 1;
  while (k) {
    if (k & 1)
      r = r * x % m;
    x = x * x % m;
    k >>= 1;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  f[0] = rf[0] = 1;
  rep(i, n) {
    f[i + 1] = f[i] * (i + 1) % m;
    rf[i + 1] = pw(f[i + 1], m - 2);
  }
  for (int i = 1; i <= n; ++i)
    w[i] = pw(2, i - 1) * rf[i] % m;
  rep(i, n)
    dp[i][i + 1] = w[i + 1];
  rep(i, n) {
    rep(j, i + 2) {
      dp[i + 2][j + 1] = (dp[i + 2][j + 1] + dp[i][j]) % m;
      for (int k = i + 3; k < n; ++k)
        dp[k][j + k - i - 1] = (dp[k][j + k - i - 1] + dp[i][j] * w[k - i - 1]) % m;
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i)
    ans = (ans + dp[n - 1][i] * f[i]) % m;
  cout << ans;
}