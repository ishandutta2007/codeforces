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
  int ans = n;
  for (int i = 0; i < n - 1; i++) {
    if (i == 0 || A[i] != A[i - 1]) {
      int s = i;
      while (A[s] == A[i]) {
        s++;
      }
      int ors = s;
      if (s >= n) {
        ans = min(ans, i);
      } else {
        int cnt = 0;
        int c = 2 * A[s] - A[i];
        while (A[n - 1] >= c && s < n - 1) {
          int nx = (int) (lower_bound(A.begin(), A.end(), c) - A.begin());
          nx = max(nx, s + 1);
          s = nx;
          c = 2 * A[s] - A[i];
          cnt++;
        }
        ans = min(ans, i + (n - ors - 1) - cnt);
      }
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