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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 998244353;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int bigans = 0;
  int ans = 0;
  vector<pair<int, int>> MC;
  for (int j = n - 1; j >= 0; j--) {
    for (auto p : MC) {
      ans += ((p.second * ((A[j] - 1) / p.first)) % M);
    }
    vector<pair<int, int>> MC2;
    for (auto p : MC) {
      int nxt = A[j] / ((A[j] + p.first - 1) / p.first);
      if (MC2.empty() || MC2.back().first != nxt) {
        MC2.pb({nxt, p.second});
      } else {
        MC2.back().second += p.second;
      }
    }
    if (MC2.empty() || MC2.back().first != A[j]) {
      MC2.pb({A[j], 1});
    } else {
      MC2.back().second++;
    }
    MC = MC2;
    ans %= M;
    bigans += ans;
    bigans %= M;
  }
  cout << bigans << '\n';
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