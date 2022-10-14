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
  string s;
  cin >> s;
  set<char> kek;
  for (int i = 0; i < s.size(); i++) {
    for (char c = s[i]; c >= 'b'; c--) {
      if (k > 0 && kek.find(c) == kek.end()) {
        kek.insert(c);
        k--;
      }
    }
  }
  while (!kek.empty()) {
    char c = *kek.rbegin();
    kek.erase(c);
    for (auto &c0 : s) {
      if (c0 == c) {
        c0--;
      }
    }
  }
  cout << s << '\n';
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