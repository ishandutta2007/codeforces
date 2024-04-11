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
const int N = 200500;
int LOG[N];

void solve() {
  int n;
  cin >> n;
  vector<int> A(n + 1);
  for (int i = 1; i <= n; i++) cin >> A[i];
  vector<int> B(n);
  for (int i = 1; i < n; i++) {
    B[i] = abs(A[i] - A[i + 1]);
  }
  int ST[n + 1][LOG[n] + 1];
  for (int i = 0; i < n; i++) {
    ST[i][0] = B[i];
  }
  for (int l = 1; l <= LOG[n]; l++) {
    for (int i = 0; i < n; i++) {
      if (i + (1 << (l - 1)) < n) {
        ST[i][l] = gcd(ST[i][l - 1], ST[i + (1 << (l - 1))][l - 1]);
      } else {
        ST[i][l] = ST[i][l - 1];
      }
    }
  }
  int l = 0, r = n + 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    int lg = LOG[m];
    bool can = false;
    for (int i = 1; i <= n - m; i++) {
      if (gcd(ST[i][lg], ST[(i + m - 1) - (1 << lg) + 1][lg]) >= 2) {
        can = true;
        break;
      }
    }
    if (can) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l + 1 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (int i = 2; i < N; i++) {
    LOG[i] = 1 + LOG[i / 2];
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}