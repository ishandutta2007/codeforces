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
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int a, l, r;
  cin >> l >> r >> a;
  int ans = 0;
  for (int x = l; x <= min(l + 100, r); x++) {
    ans = max(ans, x / a + x % a);
  }
  for (int x = max(l, r - 100); x <= r; x++) {
    ans = max(ans, x / a + x % a);
  }
  int mem = r - r % a - 1;
  if (mem >= l) {
    ans = max(ans, mem / a + mem % a);
  }
  cout << ans;
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