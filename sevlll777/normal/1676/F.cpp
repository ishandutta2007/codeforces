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
  map<int, int> cnt;
  while (n--) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  vector<int> w;
  for (auto p : cnt) {
    if (p.second >= k) {
      w.pb(p.first);
    }
  }
  if (w.empty()) {
    cout << -1 << '\n';
    return;
  }
  sort(all(w));
  int ans = 1;
  int cn = 1;
  int r = w[0];
  for (int i = 1; i < w.size(); i++) {
    if (w[i] == 1 + w[i - 1]) {
      cn++;
    } else {
      if (ans < cn) {
        ans = cn;
        r = w[i - 1];
      }
      cn = 1;
    }
  }
  if (ans < cn) {
    ans = cn;
    r = w[(int) w.size() - 1];
  }
  cout << r + 1 - ans << ' ' << r << '\n';

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