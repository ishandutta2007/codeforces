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
  int a, b;
  cin >> a >> b;
  vector<int> ans;
  int p1 = (a + b + 1) / 2, p2 = (a + b) / 2;
  for (int _ = 0; _ < 2; _++) {
    for (int x = 0; x <= p1; x++) {
      int y = a - (p1 - x);
      if (0 <= y && y <= p2) {
        ans.pb(x + y);
      }
    }
    swap(p1, p2);
  }
  sort(all(ans));
  vector<int> ans2 = {ans[0]};
  for (int i = 1; i < (int) ans.size(); i++) {
    if (ans[i] != ans[i-1]) {
      ans2.pb(ans[i]);
    }
  }
  cout << (int) ans2.size() << '\n';
  for (auto x : ans2) cout << x << ' ';
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