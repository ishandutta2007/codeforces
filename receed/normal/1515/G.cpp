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

const int N = 200002;
vector<pair<ll, ll>> g[N];
vector<int> rg[N], ord;
ll used[N], c[N], cc, res[N], vis[N], d[N];

void dfs(int v) {
  used[v] = 1;
  for (auto &[u, w] : g[v])
    if (!used[u])
      dfs(u);
  ord.push_back(v);
}

void rdfs(int v) {
  c[v] = cc;
  for (int u : rg[v])
    if (!c[u])
      rdfs(u);
}

void dfs2(int v) {
  vis[v] = 1;
  for (auto &[u, w] : g[v]) {
    if (c[u] != c[v])
      continue;
    if (!vis[u]) {
      d[u] = d[v] + w;
      dfs2(u);
    } else
      res[c[v]] = __gcd(res[c[v]], abs(d[v] + w - d[u]));
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, u, v, w;
  cin >> n >> m;
  rep(i, m) {
    cin >> u >> v >> w;
    --u; --v;
    g[u].push_back({v, w});
    rg[v].push_back(u);
  }
  rep(i, n)
    if (!used[i])
      dfs(i);
  reverse(all(ord));
  for (int i : ord)
    if (!c[i]) {
      ++cc;
      rdfs(i);
      dfs2(i);
    }
  int q;
  cin >> q;
  rep(i, q) {
    ll s, t;
    cin >> v >> s >> t;
    v = c[v - 1];
    if (s == 0 || (res[v] && s % __gcd(t, res[v]) == 0))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}