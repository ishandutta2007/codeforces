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
  int n;
  cin >> n;
  vector<int> P(n);
  for (int i = 0; i < n; i++) cin >> P[i];
  int j = -1;
  for (int i = 0; i < n; i++) {
    if (P[i] != i + 1) {
      j = i;
      break;
    }
  }
  if (j != -1) {
    for (int i = 0; i < n; i++) {
      if (P[i] == j + 1) {
        vector<int> e;
        for (int x = j; x <= i; x++) e.pb(P[x]);
        reverse(all(e));
        for (int x = j; x <= i; x++) P[x] = e[x - j];
      }
    }
  }
  for (auto x : P) {
    cout << x << ' ';
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