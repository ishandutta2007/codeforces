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
  vector<string> f(n);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
  }
  vector<vector<int>> p(n, vector<int>(m, n));
  for (int j = 0; j < m; j++) {
    if (f[n - 1][j] == 'o') {
      p[n - 1][j] = n - 1;
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (f[i][j] == 'o') {
        p[i][j] = i;
      } else {
        p[i][j] = p[i + 1][j];
      }
    }
  }
  vector<string> ans(n);
  vector<vector<int>> tr(n + 1, vector<int>(m));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      tr[i][j] = i;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (f[i][j] != '*') {
        ans[i] += f[i][j];
      } else {
        ans[i] += '.';
        int r = tr[p[i][j]][j];
        ans[r - 1][j] = '*';
        tr[p[i][j]][j]--;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
  cout << '\n';
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