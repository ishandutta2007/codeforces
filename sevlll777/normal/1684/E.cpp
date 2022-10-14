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
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(all(a));
  int mex = n;
  int c = 0;
  for (int v = 0; v <= n; v++) {
    c += (cnt[v] == 0);
    if (c == k + 1) {
      mex = v;
      break;
    }
  }
  int cm = 0;
  while (cnt[cm] >= 1) cm++;
  set<pair<int, int>> kek;
  for (auto pr : cnt) {
    if (pr.first >= mex && pr.second > 0) {
      kek.insert({pr.second, pr.first});
    } else if (pr.first < mex && pr.second > 1) {
      kek.insert({(int) 1e9 + pr.second - 1, pr.first});
    }
  }
  while (k--) {
    if (kek.empty()) {
      break;
    }
    pair<int, int> pr = *kek.begin();
    kek.erase(pr);
    cnt[pr.second]--;
    pr.first--;
    cnt[cm]++;
    while (cnt[cm] >= 1) cm++;
    if (pr.first > 0 && pr.first != (int) 1e9) {
      kek.insert(pr);
    }
  }
  int d = 0;
  for (auto pr: cnt) {
    d += (pr.second > 0);
  }
  cout << d - mex << '\n';
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