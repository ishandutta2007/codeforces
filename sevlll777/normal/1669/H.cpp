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
  int n, k;
  cin >> n >> k;
  vector<int> cnt(32);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int b = 30; b >= 0; b--) {
      if ((a[i] >> b) & 1) {
        cnt[b]++;
      }
    }
  }
  int ans = 0;
  for (int b = 30; b >= 0; b--) {
    int r = n - cnt[b];
    if (k >= r) {
      k -= r;
      ans += (1LL << b);
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