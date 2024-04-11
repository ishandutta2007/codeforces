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

const int N = 200001, M = 30;
int f[M], sz[N], d[N];
vector<pair<int, int>> g[N];
pair<int, int> e[N];
int n;

void csz(int v, int p, int num, vector<int> &ee) {
  sz[v] = 1;
  for (auto &pp : g[v])
    if (!d[pp.second] && pp.first != p) {
      csz(pp.first, v, num, ee);
      sz[v] += sz[pp.first];
      if (sz[pp.first] == f[num - 1] || sz[pp.first] == f[num - 2])
        ee.push_back(pp.second);
    }
}

bool dfs(int v, int num) {
  if (num <= 3)
    return 1;
  vector<int> ee;
  csz(v, -1, num, ee);
  for (int i : ee) {
    d[i] = 1;
    if (sz[e[i].first] == f[num - 1] || sz[e[i].second] == f[num - 2]) {
      if (dfs(e[i].first, num - 1) && dfs(e[i].second, num - 2))
        return 1;
    } else {
      if (dfs(e[i].first, num - 2) && dfs(e[i].second, num - 1))
        return 1;
    }
    d[i] = 0;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  f[0] = f[1] = 1;
  for (int i = 2; i < M; ++i)
    f[i] = f[i - 1] + f[i - 2];
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    e[i] = {u, v};
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  int num = -1;
  rep(i, M)
    if (f[i] == n) {
      num = i;
      break;
    }
  if (num == -1) {
    cout << "NO";
    return 0;
  }
  if (dfs(0, num))
    cout << "YES";
  else
    cout << "NO";
}