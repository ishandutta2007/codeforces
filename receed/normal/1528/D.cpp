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

const int N = 602;
ll inf = 1e17;
ll d[N], f[N], cd[N];
vector<pair<int, int>> g[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, u, v, c;
  cin >> n >> m;
  rep(i, m) {
    cin >> u >> v >> c;
    g[u].push_back({v, c});
  }
  rep(i, n) {
    rep(j, n) {
      d[j] = inf;
      f[j] = 0;
    }
    d[i] = 0;
    rep(j, n) {
      int v = -1;
      rep(k, n) {
        cd[k] = inf;
        if (!f[k] && (v == -1 || d[k] < d[v]))
          v = k;
      }
      f[v] = 1;
      for (auto &[u, c] : g[v])
        cd[(u + d[v]) % n] = d[v] + c;
      int v1 = 0, v2 = 1;
      rep(k, 2 * n) {
        v1 = (v1 == n - 1 ? 0 : v1 + 1);
        v2 = (v2 == n - 1 ? 0 : v2 + 1);
        cd[v2] = min(cd[v2], cd[v1] + 1);
      }
      rep(k, n)
        d[k] = min(d[k], cd[k]);
    }
    rep(j, n)
      cout << d[j] << ' ';
    cout << '\n';
  }
}