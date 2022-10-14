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
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int INF = (int) 2e9;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), p(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = p[i - 1] ^ a[i];
  }
  vector<int> dp(n + 1, INF);
  dp[0] = 0;
  map<int, int> last;
  last[p[0]] = 0;
  for (int i = 1; i <= n; i++) {
    if (last.find(p[i]) != last.end()) {
      dp[i] = min(dp[i], dp[last[p[i]]] + (i - last[p[i]] - 1));
    }
    last[p[i]] = i;
    dp[i] = min(dp[i - 1] + 1, dp[i]);
    if (a[i] == 0) {
      dp[i] = min(dp[i], dp[i - 1]);
    }
    if (i >= 2 && a[i] == a[i - 1]) {
      dp[i] = min(dp[i], dp[i - 2] + 1);
    }
  }
  cout << dp[n] << '\n';
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