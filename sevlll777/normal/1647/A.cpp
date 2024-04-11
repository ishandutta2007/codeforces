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
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n % 3 == 0) {
    for (int _ = 0; _ < n / 3; _++) {
      cout << "21";
    }
  } else if (n % 3 == 1) {
    cout << "1";
    for (int _ = 0; _ < n / 3; _++) {
      cout << "21";
    }
  } else {
    cout << "2";
    for (int _ = 0; _ < n / 3; _++) {
      cout << "12";
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