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
// #define int long long
typedef long long ll;
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  map<int, ll> cnt;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    cnt[A[i]]++;
  }
  vector<int> nums;
  for (auto p : cnt) {
    nums.pb(p.first);
  }
  vector<int> big;
  int s = (int) round(sqrt(n));
  vector<vector<ll>> small(s);
  for (auto p : cnt) {
    if (p.second >= s) {
      big.pb(p.first);
    } else {
      small[p.second].pb((ll) p.first);
    }
  }
  set<pair<int, int>> bad;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    bad.insert({x, y});
  }
  ll ans = 0;
  for (ll x : big) {
    for (ll y : nums) {
      if (x != y && ans < (cnt[x] + cnt[y]) * (x + y) && (bad.find({min(x, y), max(x, y)}) == bad.end())) {
        ans = (cnt[x] + cnt[y]) * (x + y);
      }
    }
  }
  for (ll w = 0; w < s; w++) {
    sort(rall(small[w]));
    if ((int) small[w].size() >= 2) {
      for (int i = 0; i < (int) small[w].size(); i++) {
        for (int j = i + 1; j < (int) small[w].size(); j++) {
          if (ans > (w + w) * (small[w][i] + small[w][j])) {
            break;
          }
          if (bad.find({small[w][j], small[w][i]}) == bad.end()) {
            ans = (w + w) * (small[w][i] + small[w][j]);
            break;
          }
        }
      }
    }
  }
  for (ll w1 = 0; w1 < s; w1++) {
    for (ll w2 = w1 + 1; w2 < s; w2++) {
      for (int i = 0; i < (int) small[w1].size(); i++) {
        for (int j = 0; j < (int) small[w2].size(); j++) {
          if (ans > (w1 + w2) * (small[w1][i] + small[w2][j])) {
            break;
          }
          if (bad.find({min(small[w1][i], small[w2][j]), max(small[w1][i], small[w2][j])}) == bad.end()) {
            ans = (w1 + w2) * (small[w1][i] + small[w2][j]);
            break;
          }
        }
      }
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