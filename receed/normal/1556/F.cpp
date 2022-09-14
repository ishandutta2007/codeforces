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

const int N = 14, MOD = 1e9 + 7;
ll a[N], dp[1 << N], pr[N][N];

ll pw(ll x, ll k) {
  ll r = 1;
  while (k) {
    if (k & 1)
      r = r * x % MOD;
    k >>= 1;
    x = x * x % MOD;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  rep(i, n)
    cin >> a[i];
  rep(i, n)
    rep(j, n)
      pr[i][j] = a[i] * pw(a[i] + a[j], MOD - 2) % MOD;
  int pw = 1 << n;
  ll ans = 0;
  for (int i = 1; i < pw; ++i) {
    dp[i] = 1;
    for (int j = (i - 1) & i; j; j = (j - 1) & i) {
      ll cs = 1;
      rep(k, n)
        rep(l, n)
          if (((j >> k) & 1) && ((i >> l) & 1) && !((j >> l) & 1))
            cs = cs * pr[k][l] % MOD;
      dp[i] = (dp[i] + MOD - dp[j] * cs % MOD) % MOD;
    }
    ll cs = 1, cc = 0;
    rep(k, n)
      rep(l, n)
        if (((i >> k) & 1) && !((i >> l) & 1))
          cs = cs * pr[k][l] % MOD;
    rep(k, n)
      if ((i >> k) & 1)
        ++cc;
    ans = (ans + dp[i] * cs % MOD * cc) % MOD;
  }
  cout << ans;
}