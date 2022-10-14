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
  int n, s;
  cin >> n >> s;
  int su = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    su += a[i];
  }
  if (su < s) {
    cout << "-1\n";
    return;
  }
  if (su == s) {
    cout << "0\n";
    return;
  }
  int d = su - s;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      b.pb(i);
    }
  }
  int ans = min(1 + b[d - 1], n - b[su - d]);
  for (int i = 0; i < d - 1; i++) {
    ans = min(ans, 1 + b[i] + n - b[su - d + (i + 1)]);
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