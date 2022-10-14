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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  vector<int> d;
  for (auto x : a) {
    if (x >= 2 * n) {
      int w = x / n;
      d.pb(w);
    }
  }
  sort(all(d));
  int m2 = m;
  for (auto x : d) {
    if (m2 <= x) {
      m2 = 0;
      break;
    }
    if (x == m2 - 1) {
      if (x > 2) {
        m2 -= (x - 1);
      }
    } else {
      m2 -= x;
    }
  }
  if (m2 == 0) {
    cout << "Yes\n";
    return;
  }
  swap(n, m);
  d = {};
  for (auto x : a) {
    if (x >= 2 * n) {
      int w = x / n;
      d.pb(w);
    }
  }
  sort(all(d));
  m2 = m;
  for (auto x : d) {
    if (m2 <= x) {
      m2 = 0;
      break;
    }
    if (x == m2 - 1) {
      if (x > 2) {
        m2 -= (x - 1);
      }
    } else {
      m2 -= x;
    }
  }
  if (m2 == 0) {
    cout << "Yes\n";
    return;
  }

  cout << "No\n";
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