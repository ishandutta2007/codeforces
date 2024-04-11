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
const int A = 1000009;
bool prime[A];
int lcd[A];

void solve() {
  int n, e;
  cin >> n >> e;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  vector<int> dp(n), dp1(n);
  for (int i = n - 1; i >= 0; i--) {
    if (i + e >= n) {
      if (prime[a[i]]) {
        dp[i] = 1;
        dp1[i] = 0;
      } else {
        dp[i] = 0;
        if (a[i] == 1) {
          dp1[i] = 1;
        } else {
          dp1[i] = 0;
        }
      }
    } else {
      if (a[i] == 1) {
        dp[i] = dp[i + e];
        dp1[i] = 1 + dp1[i + e];
      } else if (prime[a[i]]) {
        dp1[i] = 0;
        dp[i] = 1 + dp1[i + e];
      } else {
        dp1[i] = 0;
        dp[i] = 0;
      }
    }
    ans += dp[i];
  }
  for (auto x : a) {
    if (prime[x]) {
      ans--;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  lcd[1] = 1;
  for (int x = 2; x < A; x++) {
    if (lcd[x] == 0) {
      for (int y = x; y < A; y += x) {
        lcd[y] = x;
      }
    }
  }
  prime[1] = false;
  for (int x = 2; x < A; x++) {
    if (lcd[x] == x) {
      prime[x] = true;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}