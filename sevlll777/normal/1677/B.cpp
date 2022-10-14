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
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  s = '0' + s;
  vector<int> cnt1(n * m + 1), cnt2(n * m + 1);
  vector<int> p(n * m + 1);
  for (int i = 1; i <= n * m; i++) {
    p[i] = p[i - 1] + (s[i] - '0');
  }
  vector<int> t(1 + n * m), is(1 + n * m);
  for (int i = 1; i <= n * m; i++) {
    if (i <= m) {
      if (s[i] == '1') {
        t[i] = 1;
        is[i] = 1;
      }
    } else {
      is[i] = is[i - m];
      if (!is[i] && s[i] == '1') {
        is[i] = 1;
        t[i] = 1;
      }
    }
  }
  for (int i = 1; i <= n * m; i++) {
    if (s[i] == '0') {
      if (i >= m) {
        cnt1[i] = cnt1[i - m] + ((p[i] - p[i - m]) > 0);
      } else {
        cnt1[i] = (p[i] > 0);
      }
      cnt2[i] = cnt2[i - 1];
    } else {
      if (i >= m) {
        cnt1[i] = cnt1[i - m] + 1;
      } else {
        cnt1[i] = 1;
      }
      cnt2[i] = cnt2[i - 1] + t[i];
    }
    cout << cnt1[i] + cnt2[i] << ' ';
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