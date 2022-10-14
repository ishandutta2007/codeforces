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
  vector<int> bl, id;
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      cnt++;
    } else {
      if (cnt > 1) {
        bl.pb(cnt);
        id.pb(i - 1);
      }
      cnt = 1;
    }
  }
  if (cnt > 1) {
    bl.pb(cnt);
    id.pb(n - 1);
  }
  if (bl.empty()) {
    cout << "0\n";
    return;
  }
  if (bl.size() == 1) {
    cout << max(0LL, bl[0] - 3 + (bl[0] == 3)) << '\n';
    return;
  }
  int start = id[0] - bl[0] + 1;
  int end = id.back();
  int ans = end - start - 2;
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