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

const int MOD = 998244353;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  ll n = s.size(), m = 0, c2 = 0, c1 = 0;
  for (char c : s) {
    int d = c - '0';
    m = (m * 2 + d) % MOD;
  }
  ll pw = 1;
  vector<vector<ll>> dp(n + 1, vector<ll>(8));
  dp[0][7] = 1;
  rep(i, n) {
    int d = s[i] - '0';
    rep(ms, 8)
      rep(q, 8) {
        int nm = 0;
        if (q == 5 || q == 2)
          continue;
        rep(j, 3) {
          int fm = (ms >> j) & 1;
          int fq = (q >> j) & 1;
          if (fm && fq && !d) {
            nm = -1;
            break;
          }
          if (fm && (fq || d == 0))
            nm |= 1 << j;
        }
        if (nm != -1)
          dp[i + 1][nm] = (dp[i + 1][nm] + dp[i][ms]) % MOD;
      }
  }
  rep(i, 8)
    c2 = (c2 + dp[n][i]) % MOD;
  dp = vector<vector<ll>>(n + 1, vector<ll>(8));
  dp[0][7] = 1;
  rep(i, n) {
    int d = s[i] - '0';
    rep(ms, 8)
      rep(q, 8) {
        int nm = 0;
        if (q == 5 || q == 2 || q == 4 || q == 3)
          continue;
        rep(j, 3) {
          int fm = (ms >> j) & 1;
          int fq = (q >> j) & 1;
          if (fm && fq && !d) {
            nm = -1;
            break;
          }
          if (fm && (fq || d == 0))
            nm |= 1 << j;
        }
        if (nm != -1)
          dp[i + 1][nm] = (dp[i + 1][nm] + dp[i][ms]) % MOD;
      }
  }
  rep(i, 8)
    c1 = (c1 + dp[n][i]) % MOD;
  m++;
  m %= MOD;
  ll ans = (m * m % MOD * m % MOD - c2 * 3 % MOD + c1 * 3 % MOD - m % MOD + MOD * 2) % MOD;
  cout << ans;
}