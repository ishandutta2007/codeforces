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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < n - 2; i++) {
    if (s.substr(i, 3) == "abc") {
      ans++;
    }
  }
  while (q--) {
    int pos;
    char c;
    cin >> pos >> c;
    pos--;
    for (int i = max(0LL, pos - 2); i <= min(n - 3, pos); i++) {
      if (s.substr(i, 3) == "abc") {
        ans--;
      }
    }
    s[pos] = c;
    for (int i = max(0LL, pos - 2); i <= min(n - 3, pos); i++) {
      if (s.substr(i, 3) == "abc") {
        ans++;
      }
    }
    cout << ans << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}