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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> X, Y;
  set<int> of;
  for (int x = 1; x <= 2 * n; x++) of.insert(x);
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    X.pb(x);
    Y.pb(y);
    of.erase(x);
    of.erase(y);
  }
  vector<int> h;
  for (auto x : of) h.pb(x);
  for (int i = 0; i < (int) h.size() / 2; i++) {
    X.pb(h[i]);
    Y.pb(h[i + (int) h.size() / 2]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int cnt = 0;
      if (X[j] > X[i] && X[j] < Y[i]) cnt++;
      if (Y[j] > X[i] && Y[j] < Y[i]) cnt++;
      if (cnt == 1) {
        ans++;
      }
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