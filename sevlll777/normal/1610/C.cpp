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
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), B(n), C(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i] >> B[i];
    C[i] = A[i] + B[i] + 1;
  }
  int l = 0, r = n + 1;
  while (r - l > 1) {
    int x = (l + r) / 2;
    int xx = x;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (C[i] >= x) {
        if (xx && (A[i] >= xx - 1) && (B[i] >= cnt)) {
          xx--;
          cnt++;
        }
      }
    }
    if (xx == 0) {
      l = x;
    } else {
      r = x;
    }
  }
  cout << l << '\n';
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