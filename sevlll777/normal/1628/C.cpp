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
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> A(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n / 2; i += 2) {
    vector<pair<int, int>> cells;
    int r = n - 1 - i;
    for (int i0 = i; i0 <= r; i0++) {
      cells.pb({i, i0});
    }
    for (int i0 = i + 1; i0 <= r; i0++) {
      cells.pb({i0, r});
    }
    for (int i0 = r - 1; i0 >= i; i0--) {
      cells.pb({r, i0});
    }
    for (int i0 = r - 1; i0 >= i + 1; i0--) {
      cells.pb({i0, i});
    }
    for (int j = 0; j < (int) cells.size(); j += 4) {
      ans ^= A[cells[j].first][cells[j].second];
      ans ^= A[cells[j + 1].first][cells[j + 1].second];
    }
  }
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