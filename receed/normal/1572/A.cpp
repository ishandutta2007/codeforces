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

const int N = 200001;
vector<vector<int>> g;
int used[N], ans[N], res;

int dfs(int v) {
  used[v] = 1;
  for (int u : g[v]) {
    if (used[u] == 1)
      return 1;
    if (!used[u] && dfs(u))
        return 1;
    if (u < v)
      ans[v] = max(ans[v], ans[u]);
    else
      ans[v] = max(ans[v], ans[u] + 1);
    res = max(res, ans[v]);
  }
  used[v] = 2;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  rep(z, t) {
    int n, k, v;
    cin >> n;
    g = vector<vector<int>>(n);
    res = 0;
    rep(i, n) {
      ans[i] = used[i] = 0;
      cin >> k;
      g[i].resize(k);
      rep(j, k) {
        cin >> g[i][j];
        g[i][j]--;
      }
    }
    rep(i, n)
      if (!used[i] && dfs(i)) {
        res = -1;
        break;
      }
    if (res != -1)
      ++res;
    cout << res << '\n';
  }
}