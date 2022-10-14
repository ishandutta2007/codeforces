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
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  sort(all(a));
  vector<int> d;
  for (int i = 0; i < m - 1; i++) {
    d.pb(a[i + 1] - a[i] - 1);
  }
  d.pb(n - a[m - 1] + a[0] - 1);
  sort(rall(d));
  int sur = 0;
  int p = 0;
  int i = 0;
  while (i < m) {
    int rest = d[i] - 2 * p;
    if (rest <= 0) {
      break;
    }
    if (rest <= 2) {
      sur++;
      i++;
    }
    if (rest >= 3) {
      sur += rest - 1;
      i++;
      p++;
    }
    p++;
  }
  cout << n - sur << '\n';
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