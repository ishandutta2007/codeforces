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
// #define int long long
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int N = 105;
const int S = N * N;
bool dp[N][S];

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }
  int ans = 0, sum = 0;
  for (auto x : A) {
    sum += x;
    ans += (n - 2) * x * x;
  }
  for (auto x : B) {
    sum += x;
    ans += (n - 2) * x * x;
  }
  for (int w = 0; w < S; w++) {
    dp[0][w] = false;
  }
  dp[0][A[0]] = true;
  dp[0][B[0]] = true;
  for (int i = 1; i < n; i++) {
    for (int w = 0; w < S; w++) {
      if ((w >= A[i] && dp[i - 1][w - A[i]]) || (w >= B[i] && dp[i - 1][w - B[i]])) {
        dp[i][w] = true;
      } else {
        dp[i][w] = false;
      }
    }
  }
  int kek = (int) 2e9;
  for (int w = 0; w < S; w++) {
    if (dp[n - 1][w]) {
      kek = min(kek, w * w + (sum - w) * (sum - w));
    }
  }
  ans += kek;
  cout << ans << '\n';
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