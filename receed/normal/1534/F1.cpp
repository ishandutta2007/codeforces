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

const int N = 400002;
vector<int> g[N], rg[N], ord;
int c[N], used[N], dd[N], cc;
int n, m;

int getn(int x, int y) {
  return x * m + y;
}

void add(int ax, int ay, int bx, int by) {
  int u = getn(ax, ay), v = getn(bx, by);
  g[u].push_back(v);
  rg[v].push_back(u);
}

void dfs(int v) {
  used[v] = 1;
  for (int u : g[v])
    if (!used[u])
      dfs(u);
  ord.push_back(v);
}

void rdfs(int v) {
  c[v] = cc;
  for (int u : rg[v]) {
    if (!used[u])
      continue;
    if (!c[u])
      rdfs(u);
    else if (c[u] != c[v])
      dd[cc] = 1;
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  vector<string> a(n);
  rep(i, n)
    cin >> a[i];
  rep(i, n)
    rep(j, m) {
      if (i < n - 1)
        add(i, j, i + 1, j);
      if (a[i][j] == '#') {
        if (j > 0)
          add(i, j - 1, i, j);
        if (j < m - 1)
          add(i, j + 1, i, j);
        if (i < n - 1)
          add(i + 1, j, i, j);
      }
    }
  rep(i, n)
    rep(j, m) {
      int v = getn(i, j);
      if (a[i][j] == '#' && !used[v]) {
        dfs(v);
      }
    }
  reverse(all(ord));
  int ans = 0;
  for (int i : ord)
    if (!c[i]) {
      ++cc;
      rdfs(i);
      if (!dd[cc])
        ++ans;
    }
  cout << ans;
}