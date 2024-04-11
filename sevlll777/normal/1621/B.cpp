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
  cin >> n;
  vector<int> L(n), R(n), C(n);
  for (int i = 0; i < n; i++) {
    cin >> L[i] >> R[i] >> C[i];
  }
  map<int, int> costl, costr;
  map<pair<int, int>, int> costp;
  int minl = (int) 1e18, maxr = (int) -1e18;
  for (int i = 0; i < n; i++) {
    minl = min(minl, L[i]);
    maxr = max(maxr, R[i]);
    if (costr.find(R[i]) == costr.end() || costr[R[i]] > C[i]) {
      costr[R[i]] = C[i];
    }
    if (costl.find(L[i]) == costl.end() || costl[L[i]] > C[i]) {
      costl[L[i]] = C[i];
    }
    if (costp.find({L[i], R[i]}) == costp.end() || costp[{L[i], R[i]}] > C[i]) {
      costp[{L[i], R[i]}] = C[i];
    }
    int ans = (int) 1e18;
    if (costp.find({minl, maxr}) != costp.end()) {
      ans = min(ans, costp[{minl, maxr}]);
    }
    if (costl.find(minl) != costl.end() && costr.find(maxr) != costr.end()) {
      ans = min(ans, costl[minl] + costr[maxr]);
    }
    cout << ans << ' ';
  }

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