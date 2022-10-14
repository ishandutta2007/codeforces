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
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<bool> is1(n + 2);
  vector<bool> is0(n + 2);
  s = '-' + s;
  for (int i = 1; i <= n; i++) {
    is0[i] = is0[i - 1] | (s[i] == '0');
  }
  for (int i = n; i >= 1; i--) {
    is1[i] = is1[i + 1] | (s[i] == '1');
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!is0[i - 1] && !is1[i + 1]) {
      ans++;
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