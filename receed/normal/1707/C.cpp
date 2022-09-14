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

const int N = 100002, L = 17;
int p[N], h[N], par[N], up[L][N], d[N], ct, tin[N], tout[N];
vector<int> g[N];

int getp(int v) {
  if (p[v] != v)
    p[v] = getp(p[v]);
  return p[v];
}

void dfs(int v, int p) {
  tin[v] = ct++;
  for (int u : g[v]) {
    if (u == p)
      continue;
    h[u] = h[v] + 1;
    up[0][u] = v;
    dfs(u, v);
  }
  tout[v] = ct;
}

int isp(int u, int v) {
  return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int getpar(int u, int v) {
  for (int i = L - 1; i >= 0; --i)
    if (!isp(up[i][u], v))
      u = up[i][u];
  return u;
}

void dfs2(int v, int p) {
  for (int u : g[v]) {
    if (u == p)
      continue;
    d[u] += d[v];
    dfs2(u, v);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  rep(i, n)
    p[i] = i;
  vector<pair<int, int>> e;
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    int pu = getp(u), pv = getp(v);
    if (pu != pv) {
      p[pu] = pv;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    else
      e.push_back({u, v});
  }
  dfs(0, -1);
  rep(i, L - 1)
    rep(j, n)
      up[i + 1][j] = up[i][up[i][j]];
  int nc = 0;
  for (auto [u, v] : e) {
    if (isp(v, u))
      swap(u, v);
    if (isp(u, v)) {
      --d[getpar(v, u)];
      ++d[v];
    } else {
      ++nc;
      ++d[u];
      ++d[v];
    }
  }
  dfs2(0, -1);
  rep(i, n)
    cout << (int) (d[i] == nc);
}