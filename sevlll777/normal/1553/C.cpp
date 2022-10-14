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
  string s;
  cin >> s;
  int ans = 10;
  for (int mask = 0; mask < 1024; mask++) {
    string ss = s;
    for (int i = 0; i < 10; i++) {
      if (s[i] == '?') {
        ss[i] = (char) ('0' + ((mask >> i) & 1));
      }
    }
    int o1 = 5, o2 = 5, g1 = 0, g2 = 0;
    for (int i = 0; i < 10; i++) {
      if (i % 2 == 0) {
        if (ss[i] == '1') {
          o1--;
          g1++;
        } else {
          o1--;
        }
      } else {
        if (ss[i] == '1') {
          o2--;
          g2++;
        } else {
          o2--;
        }
      }
      if (g1 > g2 + o2 || g2 > g1 + o1) {
        ans = min(ans, i + 1);
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