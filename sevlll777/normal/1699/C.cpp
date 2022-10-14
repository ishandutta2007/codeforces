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
const int M = 1000000007;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<int> pref(n), suf(n);
  pref[0] = p[0];
  for (int i = 1; i < n; i++) {
    pref[i] = min(p[i], pref[i - 1]);
  }
  suf[n - 1] = p[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = min(p[i], suf[i + 1]);
  }
  set<int> not_fixed;
  for (int v = 0; v < n; v++) {
    not_fixed.insert(v);
  }
  for (int i = 0; i < n; i++) {
    not_fixed.erase(pref[i]);
    not_fixed.erase(suf[i]);
  }
  vector<int> nf;
  for (auto x : not_fixed) {
    nf.pb(x);
  }
  vector<int> bs;
  for (int i = 1; i < n - 1; i++) {
    if (pref[i] == pref[i - 1] && suf[i] == suf[i + 1]) {
      int val = max(pref[i], suf[i]);
      int j = (lower_bound(all(nf), val) - nf.begin());
      bs.pb((int) nf.size() - j);
    }
  }
  sort(all(bs));
  int ans = 1;
  for (int i = 0; i < (int) bs.size(); i++) {
    ans *= (bs[i] - i);
    ans %= M;
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