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
const int N = 200500;
vector<int> g[N];
bitset<N> used;
int d[N];
int nxt[N], giganxt[N];

void dfs(int v) {
  used[v] = true;
  vector<int> sons;
  for (auto u : g[v]) {
    if (!used[u]) {
      sons.pb(u);
      dfs(u);
    }
  }
  d[v] = 1;
  if (sons.empty()) {
    nxt[v] = giganxt[v] = v;
  }
  for (auto u : sons) {
    if (d[v] < d[u] + 1) {
      d[v] = d[u] + 1;
      nxt[v] = u;
      giganxt[v] = giganxt[u];
    }
  }
}


signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(0);
  int lst = 0;
  for (int v = 1; v < n; v++) {
    if ((int) g[v].size() == 1) {
      lst++;
    }
  }
  if (lst < k) {
    int ans = 0;
    for (int d9 = lst; d9 <= k; d9++) {
      ans = max(ans, d9 * (n - d9));
    }
    cout << ans << '\n';
  } else {
    set<pair<int, int>> pepega;
    for (int v = 0; v < n; v++) {
      pepega.insert({-d[v], v});
    }
    int kek = 0;
    for (int _ = 0; _ < k; _++) {
      if (pepega.empty()) {
        break;
      }
      pair<int, int> p = *pepega.begin();
      kek -= p.first;
      int v = p.second;
      while (nxt[v] != v) {
        pepega.erase({-d[v], v});
        v = nxt[v];
      }
    }
    int ans = (int) 2e18;
    int red = k;
    int mxblue = n - kek;
    for (int b = 0; b <= mxblue; b++) {
      ans = min(ans, (n - red - b) * (red - b));
    }
    cout << ans << '\n';
  }
}