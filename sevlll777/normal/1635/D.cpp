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
const int N = 200500;
int dp[N], pdp[N];

void solve() {
  int n, p;
  cin >> n >> p;
  vector<int> A(n);
  set<int> buba;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    buba.insert(A[i]);
  }
  vector<int> kek;
  for (auto x : A) {
    int y = x;
    bool flag = true;
    while (y > 0) {
      if (y % 4 == 0) {
        y /= 4;
      } else if (y % 2 == 1) {
        y -= 1;
        y /= 2;
      } else {
        break;
      }
      if (buba.find(y) != buba.end()) {
        flag = false;
        break;
      }
    }
    if (flag) {
      kek.pb(x);
    }
  }
  int ans = 0;
  for (auto a : kek) {
    int bt = 0;
    for (int b = 0; b < 40; b++) {
      if (a < (1LL << b)) {
        bt = b;
        break;
      }
    }
    if (bt <= p) {
      ans += pdp[p - bt];
      ans %= M;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  dp[0] = 1;
  pdp[0] = 1;
  dp[1] = 1;
  pdp[1] = 2;
  for (int i = 2; i < N; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
    if (dp[i] > M) {
      dp[i] -= M;
    }
    pdp[i] = pdp[i - 1] + dp[i];
    if (pdp[i] > M) {
      pdp[i] -= M;
    }
  }
  int t = 1;
  while (t--) {
    solve();
  }
}