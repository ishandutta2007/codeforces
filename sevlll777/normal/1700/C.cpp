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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> p(n);
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans += abs(a[i] - a[i + 1]);
    if (a[i] > a[i + 1]) {
      p[i] += -(a[i] - a[i + 1]);
    } else {
      p[n - 1] += -(a[i + 1] - a[i]);
      p[i] += (a[i + 1] - a[i]);
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    p[i] += p[i + 1];
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, abs(a[i] + p[i]));
  }
  cout << ans + mx << '\n';
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