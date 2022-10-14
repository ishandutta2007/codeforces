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
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int M = 1000000007;
const int N = 100500;
const int P = 205;
int dp[N][P];
const int INF = (int) 2e18;
bitset<P> go[N];

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<array<int, 3>>> f(n);
  for (int i = 0; i < m; i++) {
    int e, t, p;
    cin >> e >> t >> p;
    e--;
    f[e].pb({t, p, i});
  }
  vector<int> min_time(n, INF);
  vector<int> options;
  for (int d = 0; d < n; d++) {
    dp[0][0] = 0;
    for (int p = 1; p < P; p++) {
      dp[0][p] = INF;
    }
    for (int i = 0; i < (int) f[d].size(); i++) {
      dp[i + 1][0] = 0;
      for (int p = 1; p < P; p++) {
        dp[i + 1][p] = dp[i][p];
        go[i + 1][p] = false;
        if (f[d][i][1] <= p && dp[i + 1][p] > dp[i][p - f[d][i][1]] + f[d][i][0]) {
          dp[i + 1][p] = dp[i][p - f[d][i][1]] + f[d][i][0];
          go[i + 1][p] = true;
        }
      }
    }
    int start = 0;
    for (int p = 100; p < P; p++) {
      if (min_time[d] > dp[(int) f[d].size()][p]) {
        min_time[d] = dp[(int) f[d].size()][p];
        start = p;
      }
    }
    if (min_time[d] == INF) {
      cout << "-1\n";
      return;
    }
    int x = (int) f[d].size();
    while (x > 0) {
      if (go[x][start]) {
        options.pb(f[d][x - 1][2]);
        start -= f[d][x - 1][1];
        x--;
      } else {
        x--;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    min_time[i] += min_time[i - 1];
  }
  for (int i = 0; i < n; i++) {
    if (min_time[i] > a[i]) {
      cout << "-1\n";
      return;
    }
  }
  cout << (int) options.size() << '\n';
  for (auto x : options) {
    cout << x + 1 << ' ';
  }
  cout << '\n';


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