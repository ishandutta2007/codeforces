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
const int N = 200500;
const int B = (int) 1e9;
vector<int> g[N];
int dp[N][2];
int par[N];
int w[N];

void dfs(int v) {
  dp[v][1] = B - ((int) g[v].size() - 1);
  dp[v][0] = 0;
  for (auto u : g[v]) {
    if (u != par[v]) {
      par[u] = v;
      dfs(u);
      dp[v][1] += dp[u][0];
      dp[v][0] += max(dp[u][0], dp[u][1]);
    }
  }
}

void dfs2(int v, int c) {
  if (c == -1) {
    if (dp[v][0] > dp[v][1]) {
      c = 0;
    } else {
      c = 1;
    }
  }
  if (c == 1) {
    w[v] = (int) g[v].size();
    for (auto u : g[v]) {
      if (u != par[v]) {
        dfs2(u, 0);
      }
    }
  } else {
    w[v] = 1;
    for (auto u : g[v]) {
      if (u != par[v]) {
        dfs2(u, -1);
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  if (n == 1) {
    cout << "0 1\n1\n";
    exit(0);
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(0);
  int c = 0;
  if (dp[0][1] > dp[0][0]) {
    c = 1;
  }
  dfs2(0, c);
  int kek = 0, sum = 0;
  for (int v = 0; v < n; v++) {
    sum += w[v];
    int jjj = 0;
    for (auto u  : g[v]) {
      jjj += w[u];
    }
    kek += (jjj == w[v]);
  }
  cout << kek << ' ' << sum << '\n';
  for (int v = 0; v < n; v++) {
    cout << w[v] << ' ';
  }
  cout << '\n';
}