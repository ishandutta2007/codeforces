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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> W;
  for (int i = 0; i < m; i++) {
    int x, w;
    cin >> x >> w;
    W.pb({w, x, i});
  }
  sort(all(W));
  int ans = 0;
  vector<pair<int, int>> xs;
  for (int i = 0; i < n + n; i++) {
    ans += W[i][0];
    xs.pb({W[i][1], W[i][2]});
  }
  cout << ans;
  cout << '\n';
  sort(all(xs));
  for (int i = 0; i < n; i++) {
    cout << xs[i].second + 1 << ' ' << xs[2 * n - 1 - i].second + 1 << '\n';
  }
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