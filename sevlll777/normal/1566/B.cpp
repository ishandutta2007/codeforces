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

void solve() {
  string s;
  cin >> s;
  bool zero = false;
  for (auto c : s) {
    zero |= (c == '0');
  }
  if (!zero) {
    cout << "0\n";
  } else {
    int l = -1, r = -1, cnt = 0;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == '0') {
        if (l == -1) {
          l = i;
        }
        r = i;
        cnt++;
      }
    }
    if (cnt == r - l + 1) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }
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