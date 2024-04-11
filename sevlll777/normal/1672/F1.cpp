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
  vector<int> a(n), c(n + 1);
  int m = 0;
  vector<pair<int, int>> b;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c[a[i]]++;
    m = max(m, c[a[i]]);
    b.pb({a[i], i});
  }
  sort(all(b));
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[b[i].second] = b[(i + m) % n].first;
  }
  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';

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