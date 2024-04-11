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

const int MOD = 998244353, N = 1000002;
ll dp[N], s[N], r2 = (MOD + 1) / 2, r3 = (MOD + 1) / 3, r6 = r2 * r3 % MOD;

ll c3(ll n) {
  return (n + 2) * (n + 1) % MOD * n % MOD * r6 % MOD;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i] = (dp[i - 1] + dp[i - 1] * s[i - 1] % MOD + dp[i - 1] * (dp[i - 1] + 1) % MOD * r2 % MOD) % MOD;
    s[i] = (s[i - 1] + dp[i - 1]) % MOD;
  }
  ll ans = dp[n];
  ll d = dp[n - 1], ss = s[n - 1];
  ans = (ans + c3((d + ss) % MOD) - c3(ss) + MOD) % MOD;
  ans = ans * 2 % MOD;
  rep(i, n - 1) {
    int j = n - 2 - i;
    ll pr = (dp[j] * s[j] % MOD + dp[j] * (dp[j] + 1) % MOD * r2 % MOD) % MOD;
    ans = (ans + (dp[i] + MOD - 1) * pr) % MOD;
  }
  cout << (ans + MOD - 1) % MOD;
}