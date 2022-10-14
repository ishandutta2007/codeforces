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
  int c1 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c1 += (f[i][j] == '1');
    }
  }
  if (c1 == n * m) {
    cout << n * m - 2 << '\n';
    return;
  }
  bool e = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (f[i][j] == '0') {
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {
            if (0 <= i + di && i + di < n && 0 <= j + dj && j + dj < m && (di || dj) && f[i + di][j + dj] == '0') {
              e = true;
              break;
            }
          }
        }
      }
    }
  }
  if (e) {
    cout << c1 << '\n';
  } else {
    cout << c1 - 1 << '\n';
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