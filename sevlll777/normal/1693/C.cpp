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
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

const int INF = (int) 2e9;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n), gt(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[v].pb({u, i});
    gt[u].pb({v, i});
  }
  vector<ordered_set> lol(n);
  vector<int> d(n, INF);
  d[n - 1] = 0;
  for (int v = 0; v < n; v++) {
    for (auto u : gt[v]) {
      lol[v].insert({-d[u.first], u.second});
    }
  }
  set<pair<int, int>> q;
  q.insert({0, n - 1});
  while (!q.empty()) {
    pair<int, int> p = *q.begin();
    q.erase(p);
    if (d[p.second] != p.first) continue;
    int v = p.second;
    for (auto u : g[v]) {
      int cnt = lol[u.first].order_of_key({-d[v], -1});
      int w = d[v] + cnt + 1;
      if (w < d[u.first]) {
        for (auto u0 : g[u.first]) {
          lol[u0.first].erase({-d[u.first], u0.second});
          lol[u0.first].insert({-w, u0.second});
        }
        d[u.first] = w;
        q.insert({d[u.first], u.first});
      }
    }
  }

  cout << d[0] << '\n';
}