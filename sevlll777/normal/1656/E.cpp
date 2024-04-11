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

void solve() {
  int n;
  cin >> n;
  vector<int> dg(n);
  vector<vector<int>> g(n);
  for (int _ = 0; _ < n - 1; _++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    dg[a]++;
    dg[b]++;
    g[a].pb(b);
    g[b].pb(a);
  }
  vector<bool> used(n, false);
  vector<int> color(n);
  for (int v = 0; v < n; v++) {
    if (!used[v]) {
      used[v] = true;
      vector<int> s = {v};
      while (!s.empty()) {
        int u = s.back();
        s.pop_back();
        for (auto uu : g[u]) {
          if (!used[uu]) {
            used[uu] = true;
            s.pb(uu);
            color[uu] = 1 - color[u];
          }
        }
      }
    }
  }
  for (int v = 0; v < n; v++) {
    if (color[v] == 0) {
      cout << dg[v] << ' ';
    } else {
      cout << -dg[v] << ' ';
    }
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