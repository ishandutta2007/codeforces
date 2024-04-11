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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> S(n);
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  int ans = 0;
  for (int x = 0; x < 5; x++) {
    vector<int> b;
    for (auto s : S) {
      int cnt = 0;
      for (auto c : s) {
        if (c == (char) ('a' + x)) {
          cnt++;
        } else {
          cnt--;
        }
      }
      b.pb(cnt);
    }
    sort(rall(b));
    int sum = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (sum + b[i] > 0) {
        sum += b[i];
      } else {
        sum = -1;
        j = i;
        break;
      }
    }
    if (sum > 0) {
      ans = max(ans, n);
    }
    ans = max(ans, j);
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