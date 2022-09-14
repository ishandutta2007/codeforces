#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 200001;
vector<pair<int, int>> g[N], gg[N];
int c[N];

int dfs(int v, int cc) {
  c[v] = cc;
  for (auto [u, w] : gg[v]) {
    int nc = w ? 3 - cc : cc;
    if (c[u] && c[u] != nc || !c[u] && dfs(u, nc))
      return 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, x, y, v;
    cin >> n >> m;
    rep(i, n - 1) {
      cin >> x >> y >> v;
      g[x].push_back({y, v});
      g[y].push_back({x, v});
      if (v != -1) {
        int q = __builtin_popcount(v) % 2;
        gg[x].push_back({y, q});
        gg[y].push_back({x, q});
      }
    }
    rep(i, m) {
      int a, b, p;
      cin >> a >> b >> p;
      gg[a].push_back({b, p});
      gg[b].push_back({a, p});
    }
    int f = 1;
    rep(i, n + 1)
      if (!c[i] && dfs(i, 1)) {
        f = 0;
        break;
      }
    if (f) {
      cout << "YES\n";
      rep(i, n + 1)
        for (auto [j, v] : g[i]) {
          if (i > j)
            continue;
          if (v == -1)
            v = (c[i] != c[j]);
          cout << i << ' ' << j << ' ' << v << '\n';
        }
    } else {
      cout << "NO\n";
    }
    rep(i, n + 1) {
      g[i].clear();
      gg[i].clear();
      c[i] = 0;
    }
  }
}