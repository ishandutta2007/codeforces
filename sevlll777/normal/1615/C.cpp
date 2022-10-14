#include <iostream>
#include <iomanip>
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
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  int cnt0 = 0, cnt1 = 0, cnt01 = 0, cnt10 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      if (a[i] == '0') {
        cnt0++;
      } else {
        cnt1++;
      }
    } else if (a[i] == '0') {
      cnt01++;
    } else {
      cnt10++;
    }
  }
  int ans = (int) 1e9;
  if (cnt1 == cnt0 + 1) {
    ans = min(ans, cnt1 + cnt0);
  }
  if (cnt10 == cnt01) {
    ans = min(ans, cnt10 + cnt01);
  }
  if (ans == (int) 1e9) {
    ans = -1;
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