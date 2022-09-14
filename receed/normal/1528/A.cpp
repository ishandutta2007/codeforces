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

const int N = 100002;
ll dp[N][2], a[N][2];
vector<int> g[N];

void dfs(int v, int p) {
  for (int u : g[v]) {
    if (u == p)
      continue;
    dfs(u, v);
    rep(i, 2)
      dp[v][i] += max(dp[u][0] + abs(a[v][i] - a[u][0]), dp[u][1] + abs(a[v][i] - a[u][1]));
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t, n;
  cin >> t;
  rep(z, t) {
    cin >> n;
    rep(i, n)
      rep(j, 2)
        cin >> a[i][j];
    int u, v;
    rep(i, n - 1) {
      cin >> u >> v;
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << '\n';
    rep(i, n) {
      g[i].clear();
      rep(j, 2)
        dp[i][j] = 0;
    }
  }
}