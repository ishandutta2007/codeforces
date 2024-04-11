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

const int MOD = 1e9 + 7, N = 100003;
ll d1[N], d2[N], f[N], rf[N];

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
  f[0] = 1;
  for (ll i = 1; i < N; ++i)
    f[i] = f[i - 1] * i % MOD;
  rf[N - 1] = pw(f[N - 1], MOD - 2);
  for (ll i = N - 1; i > 0; --i)
    rf[i - 1] = rf[i] * i % MOD;
  ll t, n, k;
  cin >> t;
  rep(z, t) {
    cin >> n >> k;
    vector<ll> w(n + 1);
    w[0] = 1;
    for (ll i = 1; (i - 1) * k + 1 <= n; ++i) {
      ll x = n - (i - 1) * (k - 1);
      w[i] = f[x] * rf[i] % MOD * rf[x - i] % MOD;
    }
    ll ans = 0;
    rep(i, n) {
      ll fin = (w[i] * (n - i) % MOD - w[i + 1] * (i + 1) % MOD + MOD) % MOD;
      ans += fin * f[i] % MOD * f[n - i - 1] % MOD * rf[n] % MOD * (i + 1) % MOD;
      ans %= MOD;
    }
    cout << ans << '\n';
  }
}