#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

const int M = 1000000007;
const int N = 2022;
int dp[N][N];
ld dp2[N][N];

int binpow(int a, int x) {
  int ans = 1;
  while (x) {
    if (x % 2) {
      ans *= a;
      ans %= M;
    }
    a *= a;
    a %= M;
    x /= 2;
  }
  return ans;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int ans = k * dp[n][m] % M;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int o2 = binpow(2, M - 2);
  for (int n = 1; n < N; n++) {
    for (int m = 0; m <= n; m++) {
      if (m == 0) {
        dp[n][m] = 0;
        dp2[n][m] = (ld) 0;
      } else if (m == n) {
        dp[n][m] = n;
        dp2[n][m] = (ld) n;
      } else {
        ld w = (dp2[n - 1][m] + dp2[n - 1][m - 1]) / (ld) 2;
        dp2[n][m] = w;
        dp[n][m] = (dp[n - 1][m] + dp[n - 1][m - 1]) % M;
        dp[n][m] *= o2;
        dp[n][m] %= M;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}