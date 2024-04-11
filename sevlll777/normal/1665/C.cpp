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
  int n;
  cin >> n;
  vector<int> dg(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    dg[p]++;
  }
  multiset<int> d = {1};
  for (auto x : dg) {
    if (x != 0) {
      d.insert(x);
    }
  }
  int l = 0, r = n + 77;
  while (r - l > 1) {
    int m = (l + r) / 2;
    multiset<int> d2 = d;
    int kek = 0;
    for (int x = m; x >= 1; x--) {
      if (d2.empty()) {
        break;
      }
      int z = *d2.rbegin();
      d2.erase(d2.find(z));
      z -= x;
      if (z > 0) {
        kek += z;
      }
    }
    if (kek + (int) d.size() <= m) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << l + 1 << '\n';
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