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
// #define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (q >= n) {
    for (int _ = 0; _ < n; _++) {
      cout << 1;
    }
    cout << '\n';
    return;
  }
  vector<int> w(n);
  w[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] <= w[i + 1]) {
      w[i] = w[i + 1];
    } else {
      w[i] = w[i + 1] + 1;
    }
  }

  for (int i = 0; i < n; i++) {
    if (w[i] <= q) {
      for (int j = i; j < n; j++) { cout << 1; }
      break;
    }
    if (q == 0) {
      cout << 0;
    } else if (a[i] <= q) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << "\n";
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