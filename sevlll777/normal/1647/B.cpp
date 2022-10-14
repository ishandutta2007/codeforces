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
// #define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> f(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
    f[i] = '-' + f[i];
  }
  vector<vector<int>> right(n + 2, vector<int>(m + 2, m + 1)), down(n + 2, vector<int>(m + 2, n + 1));
  vector<vector<int>> left(n + 2, vector<int>(m + 2, 0)), up(n + 2, vector<int>(m + 2, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      if (f[i][j] == '0') {
        right[i][j] = j;
      } else {
        right[i][j] = right[i][j + 1];
      }
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = n; i >= 1; i--) {
      if (f[i][j] == '0') {
        down[i][j] = i;
      } else {
        down[i][j] = down[i + 1][j];
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (f[i][j] == '0') {
        left[i][j] = j;
      } else {
        left[i][j] = left[i][j - 1];
      }
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (f[i][j] == '0') {
        up[i][j] = i;
      } else {
        up[i][j] = up[i - 1][j];
      }
    }
  }

  vector<vector<int>> pref(n + 2, vector<int>(m + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] = (f[i][j] == '1') + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
  }

  bool ok = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x1 = down[i][j] - 1, x2 = right[i][j] - 1;
      ok &= (f[i][j] == '0' ||
             ((pref[x1][x2] + pref[i - 1][j - 1] - pref[x1][j - 1] - pref[i - 1][x2]) == (x1 - i + 1) * (x2 - j + 1)));
      int y1 = up[i][j] + 1, y2 = left[i][j] + 1;
      ok &= (f[i][j] == '0' ||
             ((pref[i][j] + pref[y1 - 1][y2 - 1] - pref[i][y2 - 1] - pref[y1 - 1][j]) == (i - y1 + 1) * (j - y2 + 1)));

      ok &= (f[i][j] == '0' ||
             ((pref[x1][j] + pref[i - 1][y2 - 1] - pref[x1][y2 - 1] - pref[i - 1][j]) == (x1 - i + 1) * (j - y2 + 1)));

      ok &= (f[i][j] == '0' ||
             ((pref[i][x2] + pref[y1 - 1][j - 1] - pref[i][j - 1] - pref[y1 - 1][x2]) == (i - y1 + 1) * (x2 - j + 1)));
    }
  }

  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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