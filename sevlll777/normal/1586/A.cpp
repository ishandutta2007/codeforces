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
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int s = 0;
  for (auto x : A) {
    s += x;
  }
  bool pr = true;
  for (int x = 2; x * x <= s; x++) {
    if (s % x == 0) {
      pr = false;
      break;
    }
  }
  if (!pr) {
    cout << n << '\n';
    for (int x = 1; x <= n; x++) {
      cout << x << ' ';
    }
  } else {
    for (int i = 0; i < n; i++) {
      int s2 = s - A[i];
      pr = true;
      for (int x = 2; x * x <= s2; x++) {
        if (s2 % x == 0) {
          pr = false;
          break;
        }
      }
      if (!pr) {
        cout << n - 1 << '\n';
        for (int x = 1; x <= n; x++) {
          if (x != i + 1) {
            cout << x << ' ';
          }
        }
        break;
      }
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