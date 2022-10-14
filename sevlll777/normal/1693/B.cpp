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
const int N = 200500;
vector<int> g[N];
int dp[N], L[N], R[N];

void dfs(int v) {
  int r = 0, d = 0;
  for (auto u : g[v]) {
    dfs(u);
    r += R[u];
    d += dp[u];
  }
  if (L[v] <= r) {
    dp[v] = d;
    R[v] = min(r, R[v]);
  } else {
    dp[v] = d + 1;
  }
}

void solve() {
  int n;
  cin >> n;
  for (int v = 0; v < n; v++) {
    g[v] = {};
  }
  vector<int> p(n);
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
    g[p[i]].pb(i);
  }
  for (int v = 0; v < n; v++) {
    cin >> L[v] >> R[v];
    dp[v] = 0;
  }
  dfs(0);
  cout << dp[0] << '\n';
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