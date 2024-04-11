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

const int N = 1001, MOD = 998244353;
int a[N][N], c[N][N], d[N], col[N];
vector<vector<int>> cl;
vector<int> g[N];
int t, n;

void dfs(int v, int cc) {
  cl[cc - 1].push_back(v);
  col[v] = cc;
  for (int u : g[v]) {
    if (!col[u])
      dfs(u, 3 - cc);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    rep(i, 2 * n) {
      d[i] = 0;
      col[i] = 0;
      g[i].clear();
    }
    rep(i, n)
      rep(j, n)
        c[i][j] = 0;
    rep(i, 2 * n)
      rep(j, n) {
        cin >> a[i][j];
        --a[i][j];
        ++c[j][a[i][j]];
      }
    while (1) {
      int x = -1, y = -1;
      rep(i, n)
        rep(j, n)
          if (c[i][j] == 1) {
            x = i;
            y = j;
          }
      if (x == -1)
        break;
      int pos = -1;
      rep(i, 2 * n)
        if (!d[i] && a[i][x] == y) {
          pos = i;
          break;
        }
      d[pos] = 2;
      rep(j, n)
        --c[j][a[pos][j]];
      rep(i, 2 * n) {
        if (d[i])
          continue;
        rep(j, n)
          if (a[i][j] == a[pos][j]) {
            d[i] = 1;
            break;
          }
        if (!d[i])
          continue;
        rep(j, n)
          --c[j][a[i][j]];
      }
    }
    rep(i, 2 * n) {
      if (d[i])
        continue;
      rep(j, i) {
        if (d[j])
          continue;
        rep(k, n)
          if (a[i][k] == a[j][k]) {
            g[i].push_back(j);
            g[j].push_back(i);
            break;
          }
      }
    }
    ll ans = 1;
    rep(i, 2 * n)
      if (!d[i] && !col[i]) {
        cl = vector<vector<int>>(2);
        ans = ans * 2 % MOD;
        dfs(i, 1);
      }
    cout << ans << '\n';
    vector<int> li;
    rep(i, 2 * n)
      if (d[i] == 2 || d[i] == 0 && col[i] == 2) {
        cout << i + 1 << ' ';
        li.push_back(i);
      }
    cout << '\n';
  }
}