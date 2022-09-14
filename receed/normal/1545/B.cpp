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

const int MOD = 998244353, N = 100002;
ll f[N], rf[N];

ll pw(ll x, ll k) {
  ll r = 1;
  while (k) {
    if (k & 1)
      r = r * x % MOD;
    x = x * x % MOD;
    k >>= 1;
  }
  return r;
}

ll c(ll n, ll k) {
  return f[n] * rf[k] % MOD * rf[n - k] % MOD;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  f[0] = 1;
  for (int i = 1; i < N; ++i)
    f[i] = f[i - 1] * i % MOD;
  rf[N - 1] = pw(f[N - 1], MOD - 2);
  for (int i = N - 1; i > 0; --i)
    rf[i - 1] = rf[i] * i % MOD;
  int t, n;
  cin >> t;
  while (t--) {
    string s;
    cin >> n >> s;
    int l = 1, z = 0, g = 0;
    rep(i, n)
      if (s[i] == '0') {
        z++;
        if (l == i % 2)
          g++;
        l = i % 2;
      }
    cout << c((n - z - g) / 2 + z, z) << '\n';
  }
}