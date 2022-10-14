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
  int n, k;
  cin >> n >> k;
  if (k == n - 1) {
    if (n == 4) {
      cout << -1 << '\n';
    } else {
      cout << n - 2 << ' ' << n - 1 << '\n';
      cout << 1 << ' ' << 3 << '\n';
      cout << 2 << ' ' << n - 3 << '\n';
      cout << 0 << ' ' << n - 4 << '\n';
      for (int i = 4; i < n / 2; i++) {
        cout << i << ' ' << n - 1 - i << '\n';
      }
    }
    return;
  }
  for (int i = 1; i < n / 2; i++) {
    if (i != k && n - 1 - i != k) {
      cout << i << ' ' << n - 1 - i << '\n';
    }
  }
  if (k != 0) {
    cout << k << ' ' << n - 1 << '\n';
  }
  cout << 0 << ' ' << n - 1 - k << '\n';
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