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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] < 0) {
    cout << "NO\n";
    return;
  }
  int w = a[0];
  for (int i = 1; i < n; i++) {
    if (w < 0) {
      cout << "NO\n";
      return;
    }
    if (w == 0) {
      for (int j = i; j < n; j++) {
        if (a[j]) {
          cout << "NO\n";
          return;
        }
      }
      cout << "YES\n";
      return;
    }
    w += a[i];
  }
  if (w != 0) {
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