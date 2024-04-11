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
  int ans = 1e18;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int c = 0;
      for (int l = 0; l < m; l++) {
        c += abs(f[i][l] - f[j][l]);
      }
      ans = min(ans, c);
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