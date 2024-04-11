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
  string s, t;
  cin >> s >> t;
  if (t == "a") {
    cout << "1\n";
    return;
  }
  int mda = 1;
  for (int _ = 0; _ < (int) s.size(); _++) {
    mda *= 2;
  }
  for (auto c : t) {
    if (c == 'a') {
      cout << "-1\n";
      return;
    }
  }
  cout << mda << '\n';
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