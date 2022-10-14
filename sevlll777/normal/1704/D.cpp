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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> c(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c[i][j];
    }
  }
  vector<pair<int, int>> kek;
  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = 0; j < m; j++) {
      s += c[i][j] * j;
    }
    kek.pb({s, i});
  }
  sort(rall(kek));
  cout << kek[0].second + 1 << ' ' << kek[0].first - kek[1].first << '\n';
  
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