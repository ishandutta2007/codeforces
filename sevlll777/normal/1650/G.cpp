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
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int M = 1000000007;

long long binpow(long long a, int x) {
  long long ans = 1;
  while (x) {
    if (x % 2) {
      ans *= a;
      ans %= M;
    }
    a *= a;
    a %= M;
    x /= 2;
  }
  return ans;
}

void solve() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<vector<int>> g(n + 1);
  vector<pair<int, int>> e;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
    e.pb({a, b});
    e.pb({b, a});
  }
  vector<int> ds(n + 1);
  vector<int> crs(n + 1);
  crs[s] = 1;
  deque<int> q = {s};
  vector<bool> used(n + 1, false);
  used[s] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto u : g[v]) {
      if (!used[u]) {
        ds[u] = ds[v] + 1;
        crs[u] += crs[v];
        if (crs[u] > M) {
          crs[u] -= M;
        }
        used[u] = true;
        q.pb(u);
      } else if (ds[u] == ds[v] + 1) {
        crs[u] += crs[v];
        if (crs[u] > M) {
          crs[u] -= M;
        }
      }
    }
  }
  vector<int> dt(n + 1);
  vector<int> crt(n + 1);
  crt[t] = 1;
  q = {t};
  used.assign(n + 1, false);
  used[t] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto u : g[v]) {
      if (!used[u]) {
        dt[u] = dt[v] + 1;
        crt[u] += crt[v];
        if (crt[u] > M) {
          crt[u] -= M;
        }
        used[u] = true;
        q.pb(u);
      } else if (dt[u] == dt[v] + 1) {
        crt[u] += crt[v];
        if (crt[u] > M) {
          crt[u] -= M;
        }
      }
    }
  }
  long long ans = 0;
  for (auto p : e) {
    if (ds[p.first] + dt[p.second] == ds[t] && ds[p.first] == ds[p.second]) {
      ans += ((long long) crs[p.first] * (long long) crt[p.second]) % M;
    }
  }
  ans += crs[t];
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