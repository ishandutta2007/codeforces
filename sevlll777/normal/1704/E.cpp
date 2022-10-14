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
const int M = 998244353;
const int N = 1007;
vector<int> g[N];
bitset<N> used;
vector<int> ts;

void dfs(int v) {
  used[v] = true;
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
  ts.pb(v);
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    g[i] = {};
  }
  used.reset();
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].pb(y);
  }
  int fin = 0;
  for (int v = 0; v < n; v++) {
    if (g[v].empty()) {
      fin = v;
      break;
    }
  }
  ts = {};
  for (int v = 0; v < n; v++) {
    if (!used[v]) {
      dfs(v);
    }
  }
  vector<int> dp(n);
  dp[fin] = 1;
  for (auto v : ts) {
    for (auto u : g[v]) {
      dp[v] += dp[u];
    }
    dp[v] %= M;
  }
  int ans = 0;
  for (int v = 0; v < n; v++) {
    ans += (a[v] * dp[v]) % M;
  }
  for (int _ = 0; _ < m+7; _++) {
    if (*max_element(all(a)) == 0) {
      break;
    }
    ans += (a[fin] == 0);
    vector<int> a2 = a;
    for (int v = 0; v < n; v++) {
      if (a[v] > 0) {
        a2[v]--;
        for (auto u : g[v]) {
          a2[u]++;
        }
      }
    }
    a = a2;
  }
  ans %= M;
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