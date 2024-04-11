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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  vector<int> a2;
  for (int i = 0; i < n; i++) {
    if (a[i]) {
      a2.pb(a[i]);
    } else {
      cnt++;
    }
  }
  a = a2;
  n = (int) a.size();
  while (true) {
    if (n == 0) {
      cout << 0 << '\n';
      return;
    }
    if (n == 1) {
      cout << a[0] << '\n';
      return;
    }
    int c0 = 0;
    vector<int> b;
    if (cnt) {
      b.pb(a[0]);
    }
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1] != a[i]) {
        b.pb(a[i + 1] - a[i]);
      } else {
        c0++;
      }
    }
    cnt -= 1;
    cnt = max(cnt, 0);
    cnt += c0;
    sort(all(b));
    a = b;
    n = (int) a.size();
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