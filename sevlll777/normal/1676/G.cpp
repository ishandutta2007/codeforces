#include <iostream>
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
#include <complex>
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
const int N = 4020;
vector<int> g[N];
string s;
int ans = 0;

int dfs(int v) {
  int w = 0;
  for (auto u : g[v]) {
    w += dfs(u);
  }
  if (s[v] == 'W') {
    w++;
  } else {
    w--;
  }
  if (w == 0) {
    ans++;
  }
  return w;
}

void solve() {
  int n;
  cin >> n;
  for (int v = 0; v < n; v++) {
    g[v] = {};
  }
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    g[p].pb(i);
  }
  cin >> s;
  ans = 0;
  dfs(0);
  cout << ans << '\n';

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}