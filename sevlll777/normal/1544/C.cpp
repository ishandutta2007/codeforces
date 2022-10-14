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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }
  sort(rall(A));
  sort(rall(B));
  vector<int> PA(n + 1), PB(n + 1);
  for (int i = 1; i <= n; i++) {
    PA[i] = PA[i - 1] + A[i - 1];
    PB[i] = PB[i - 1] + B[i - 1];
  }
  int l = -1, r = (int) 1e9;
  while (r - l > 1) {
    int m = (l + r) / 2;
    int k = n + m - ((n + m) / 4);
    int moi = 0;
    if (k < m) {
      moi = 100 * k;
    } else {
      moi = 100 * m + PA[k - m];
    }
    int ilii = PB[min(n, k)];
    if (moi >= ilii) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << l + 1 << '\n';
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