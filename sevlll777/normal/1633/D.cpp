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
const int N = 1020;
int dp[N];
int dp2[13][12009];

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> B(n), C(n), D(n);
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> C[i];
  }
  vector<vector<int>> kek(13);
  for (int i = 0; i < n; i++) {
    D[i] = dp[B[i]];
    kek[D[i]].pb(C[i]);
  }
  for (int i = 0; i < 13; i++) {
    sort(rall(kek[i]));
  }
  int sm = 0;
  for (auto x : kek[0]) {
    sm += x;
  }
  k = min(k, 12 * n);
  for (int k0 = 0; k0 <= k; k0++) {
    dp2[0][k0] = sm;
  }
  for (int i = 1; i < 13; i++) {
    for (int k0 = 0; k0 <= k; k0++) {
      dp2[i][k0] = dp2[i - 1][k0];
      int sum = 0;
      for (int j = 0; j < (int) kek[i].size(); j++) {
        if (k0 >= (j + 1) * i) {
          sum += kek[i][j];
          dp2[i][k0] = max(dp2[i][k0], sum + dp2[i - 1][k0 - (j + 1) * i]);
        }
      }
    }
  }
  cout << dp2[12][k] << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  dp[1] = 0;
  for (int n = 2; n < N; n++) {
    dp[n] = (int) 1e9;
    for (int x = 1; x <= n; x++) {
      int q = n / (x + 1);
      int r = n % (x + 1);
      if (r != x) {
        dp[n] = min(dp[n], 1 + dp[n - q]);
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}