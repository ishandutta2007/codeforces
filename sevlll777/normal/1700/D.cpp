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
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int sum = 0;
  for (auto x : v) {
    sum += x;
  }
  vector<ld> p(n);
  p[0] = (ld) v[0];
  int pr = v[0];
  for (int i = 1; i < n; i++) {
    pr += v[i];
    p[i] = max(p[i - 1], (ld) pr / (ld) (i + 1));
  }


  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    int l = -1, r = n;
    while (r - l > 1) {
      int m = (l + r) / 2;
      int d = m + 1;
      int water = d * t;
      if (water < sum) {
        l = m;
      } else {
        if (p[m] > t) {
          l = m;
        } else {
          r = m;
        }
      }
    }
    if (r == n) {
      cout << -1 << '\n';
    } else {
      cout << l + 2 << '\n';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}