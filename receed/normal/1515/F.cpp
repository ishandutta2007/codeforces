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

const int N = 300002;
ll a[N], used[N], x;
vector<pair<int, int>> g[N];
vector<int> li;

void dfs(int v, int p, int pe) {
  used[v] = 1;
  for (auto &[u, k] : g[v])
    if (!used[u]) {
      dfs(u, v, k);
    }
  if (p == -1)
    return;
  if (a[v] + a[p] >= x) {
    cout << pe + 1 << '\n';
    a[p] += a[v] - x;
  } else
    li.push_back(pe);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n, m, u, v, s = 0;
  cin >> n >> m >> x;
  rep(i, n) {
    cin >> a[i];
    s += a[i];
  }
  if (s < (n - 1) * x) {
    cout << "NO";
    return 0;
  }
  rep(i, m) {
    cin >> u >> v;
    --u; --v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  cout << "YES\n";
  dfs(0, -1, -1);
  reverse(all(li));
  for (int i : li)
    cout << i + 1 << '\n';
}