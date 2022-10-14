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
  vector<int> w(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    p[i] = w[i];
  }
  for (int i = 1; i < n; i++) {
    p[i] += p[i - 1];
  }
  map<int, vector<int>> kek;
  for (int i = 0; i < n; i++) {
    kek[p[i]].pb(i);
  }
  int s = 0;
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    kek[p[i]].pop_back();
    s += w[i];
    if (kek.find(s) != kek.end() && !kek[s].empty()) {
      ans = max(ans, kek[s].back() + 1 + n - i);
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