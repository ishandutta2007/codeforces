#include <iostream>
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
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int N = 2020;
int dp[N][N];

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (j <= i) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = (int) -1e9;
      }
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      int op1 = dp[i-1][j] + (i-j==A[i]);
      int op2 = dp[i-1][j-1];
      dp[i][j] = max(op1, op2);
    }
  }
  for (int j = 0; j <= n; j++) {
    if (dp[n][j] >= k) {
      cout << j << '\n';
      return;
    }
  }
  cout << "-1\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}