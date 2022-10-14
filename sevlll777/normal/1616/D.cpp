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
const int N = 100509;
int LG[N];

void solve() {
  int n;
  cin >> n;
  vector<int> A(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  int x;
  cin >> x;
  A[0] = x;
  for (auto &el : A) {
    el -= x;
  }
  vector<int> P(n + 1);
  P[0] = 0;
  for (int i = 1; i <= n; i++) {
    P[i] = A[i] + P[i - 1];
  }
  int L = LG[n] + 2;
  vector<vector<int>> ST(n + 1, vector<int>(L, 0));
  for (int i = 0; i <= n; i++) {
    ST[i][0] = P[i];
  }
  for (int l = 1; l < L; l++) {
    for (int i = 0; i <= n; i++) {
      ST[i][l] = ST[i][l - 1];
      if (i + (1 << (l - 1)) <= n) {
        ST[i][l] = max(ST[i][l], ST[i + (1 << (l - 1))][l - 1]);
      }
    }
  }
  vector<int> kek(n + 1, -1);
  for (int i = 2; i <= n; i++) {
    int lf = -1, rf = i - 1;
    while (rf - lf > 1) {
      int md = (lf + rf) / 2;
      int len = (i - 2) - md + 1;
      int lg = LG[len];
      int mx = max(ST[md][lg], ST[i - 2 - (1 << lg) + 1][lg]);
      if (mx <= P[i]) {
        rf = md;
      } else {
        lf = md;
      }
    }
    kek[i] = lf;
  }
  for (int i = 0; i <= n; i++) {
    ST[i][0] = kek[i];
  }
  for (int l = 1; l < L; l++) {
    for (int i = 0; i <= n; i++) {
      ST[i][l] = ST[i][l - 1];
      if (i + (1 << (l - 1)) <= n) {
        ST[i][l] = max(ST[i][l], ST[i + (1 << (l - 1))][l - 1]);
      }
    }
  }
  vector<int> dp(n + 1);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    if (kek[i] == -1) {
      dp[i] = dp[i - 1];
    } else {
      int l = -1, r = i - 1;
      while (r - l > 1) {
        int m = (l + r) / 2;
        int len = i - m + 1;
        int lg = LG[len];
        int mx = max(ST[m][lg], ST[i - (1 << lg) + 1][lg]);
        if (mx <= m) {
          r = m;
        } else {
          l = m;
        }
      }
      dp[i] = min(dp[i], dp[l + 1] + 1);
      if (dp[i] < dp[i - 1]) {
        dp[i] = dp[i - 1];
      }
    }
  }
  cout << n - dp[n] << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  LG[1] = 0;
  for (int i = 2; i < N; i++) {
    LG[i] = 1 + LG[i / 2];
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}