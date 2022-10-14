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
// #define int long long
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int r = 0;
  while (r < n - 1 && s[r] == s[r + 1]) {
    r++;
  }
  int x = 0;
  for (int i = 1; i < n; i++) {
    if (2 * x + 1 < i) {
      for (int j = 0; j <= x; j++)cout << s[j];
      for (int j = x; j >= 0; j--) cout << s[j];
      cout << '\n';
      return;
    }
    if (s[2 * x + 1 - i] > s[i]) {
      x = i;
    } else if (s[2 * x + 1 - i] == s[i]) {
      if (i <= r) {
        for (int j = 0; j <= x; j++) cout << s[j];
        for (int j = x; j >= 0; j--) cout << s[j];
        cout << '\n';
        return;
      } else {
        x = i;
      }
    } else {
      for (int j = 0; j <= x; j++) cout << s[j];
      for (int j = x; j >= 0; j--) cout << s[j];
      cout << '\n';
      return;
    }
  }
  for (int j = 0; j <= x; j++) cout << s[j];
  for (int j = x; j >= 0; j--) cout << s[j];
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