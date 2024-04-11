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
  int ans = (int) 1e18;
  for (int i = 0; i < n; i++) {
    int l = 0;
    int cnt = 0;
    for (int j = i - 1; j >= 0; j--) {
      int x = 1 + l / a[j];
      cnt += x;
      l = x * a[j];
    }
    l = 0;
    for (int j = i + 1; j < n; j++) {
      int x = 1 + l / a[j];
      cnt += x;
      l = x * a[j];
    }
    ans = min(ans, cnt);
  }
  cout << ans;
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}