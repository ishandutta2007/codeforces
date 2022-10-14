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
  int b = 0;
  for (int i = 0; i <= 35; i++) {
    if ((1LL << i) >= n) {
      b = i - 1;
      break;
    }
  }
  for (int x = n - 1; x >= 0; x--) {
    if (((x >> b) & 1) == 0) {
      cout << x << ' ';
    }
  }
  for (int x = 0; x <= n - 1; x++) {
    if (((x >> b) & 1) == 1) {
      cout << x << ' ';
    }
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