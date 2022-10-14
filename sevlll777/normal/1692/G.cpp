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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < k; i++) {
    if (a[i] < 2 * a[i + 1]) {
      cnt++;
    }
  }
  ans += (cnt == k);
  for (int i = k; i < n - 1; i++) {
    if (a[i - k] < 2 * a[i - k + 1]) {
      cnt--;
    }
    if (a[i] < 2 * a[i + 1]) {
      cnt++;
    }
    ans += (cnt == k);
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