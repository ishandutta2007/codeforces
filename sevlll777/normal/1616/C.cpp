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
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  int ans = n - 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int d = (A[j] - A[i]);
      int cnt = 0;
      for (int k = 0; k < n; k++) {
        if ((A[i] - A[k]) * (j - i) != d * (i - k)) {
          cnt++;
        }
      }
      ans = min(ans, cnt);
    }
  }
  cout << ans << '\n';
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