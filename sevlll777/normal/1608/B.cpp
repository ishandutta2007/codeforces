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
typedef long long ll;
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a + b > n - 2 || abs(a - b) > 1) {
    cout << -1 << '\n';
  } else {
    if (a > b) {
      vector<bool> fuck(n + 1, false);
      int x = 1;
      int last = 0;
      for (int _ = 0; _ < 1 + a + b; _++) {
        if (x % 2 == 1) {
          cout << x / 2 + 1 << ' ';
          fuck[x / 2 + 1] = true;
          last = 0;
        } else {
          cout << n + 1 - x / 2 << ' ';
          fuck[n + 1 - x / 2] = true;
          last = -1;
        }
        x++;
      }
      if (last == 0) {
        for (int p = 1; p <= n; p++) {
          if (!fuck[p]) {
            cout << p << ' ';
          }
        }
      } else {
        for (int p = n; p >= 1; p--) {
          if (!fuck[p]) {
            cout << p << ' ';
          }
        }
      }
    } else {
      vector<bool> fuck(n + 1, false);
      int x = 1;
      int last = 0;
      for (int _ = 0; _ < 1 + a + b; _++) {
        if (x % 2 == 0) {
          cout << x / 2 << ' ';
          fuck[x / 2] = true;
          last = 0;
        } else {
          cout << n - x / 2 << ' ';
          fuck[n - x / 2] = true;
          last = -1;
        }
        x++;
      }
      if (last == 0) {
        for (int p = 1; p <= n; p++) {
          if (!fuck[p]) {
            cout << p << ' ';
          }
        }
      } else {
        for (int p = n; p >= 1; p--) {
          if (!fuck[p]) {
            cout << p << ' ';
          }
        }
      }
    }
    cout << '\n';
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