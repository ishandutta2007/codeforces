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
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  string s, t;
  cin >> s >> t;
  int n = (int) s.size();
  int m = (int) t.size();
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int c = 0;
      bool ok = true;
      for (int x = i; x <= j; x++) {
        if (s[x] != t[c++]) {
          ok = false;
          break;
        }
      }
      for (int x = j - 1; x >= 0; x--) {
        if (c == m) {
          break;
        }
        if (s[x] != t[c++]) {
          ok = false;
          break;
        }
      }
      if (ok && c == m) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
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