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
  string s2;
  cin >> s2;
  int cnta = 0, cntb = 0;
  for (auto c : s2) {
    cnta += (c == 'A');
    cntb += (c == 'B');
    if (cntb > cnta) {
      cout << "NO\n";
      return;
    }
  }
  if (s2[(int) s2.size() - 1] == 'A') {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
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