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

const int N = 202, MOD = 1e9 + 7;
vector<int> g[N], ord;
int sz[N], lca[N][N], h[N], par[N];
ll dp[N][N];

void dfs(int v, int p) {
  ord.push_back(v);
  sz[v] = 1;
  h[v] = h[p] + 1;
  par[v] = p;
  for (int u : g[v])
    if (u != p) {
      dfs(u, v);
      sz[v] += sz[u];
    }
}

ll pw(ll x, ll k) {
  ll r = 1;
  while (k) {
    if (k & 1)
      r = r * x % MOD;
    k >>= 1;
    x = x * x % MOD;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, x, y;
  cin >> n;
  rep(i, n - 1) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  ll ans = 0;
  ll r2 = pw(2, MOD - 2);
  rep(i, n + 1)
    rep(j, n + 1) {
      if (i == 0)
        dp[i][j] = 1;
      else if (j == 0)
        dp[i][j] = 0;
      else
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * r2 % MOD;
    }
  rep(i, n) {
    ord.clear();
    dfs(i, i);
    for (int j : ord)
      for (int k : ord) {
        if (j == k) {
          lca[j][k] = j;
          break;
        }
        if (h[j] > h[k])
          lca[j][k] = lca[k][j] = lca[par[j]][k];
        else
          lca[j][k] = lca[k][j] = lca[j][par[k]];
      }
    rep(j, n)
      rep(k, j) {
        int h1 = h[j] - h[lca[j][k]];
        int h2 = h[k] - h[lca[j][k]];
        ans = (ans + dp[h1][h2]) % MOD;
      }
  }
  ans = ans * pw(n, MOD - 2) % MOD;
  cout << ans;
}