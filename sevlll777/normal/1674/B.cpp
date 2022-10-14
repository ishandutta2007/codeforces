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
map<string, int> ans;
int cnt = 1;

void solve() {
  string s;
  cin >> s;
  cout << ans[s] << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (char c = 'a'; c <= 'z'; c++) {
    for (char c2 = 'a'; c2 <= 'z'; c2++) {
      if (c != c2) {
        string ff;
        ff += c; ff += c2;
        ans[ff] = cnt++;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}