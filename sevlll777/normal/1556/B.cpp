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
  int s = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    A[i] %= 2;
    s += A[i];
  }
  if (s == n / 2 || s == (n + 1) / 2) {
    int ans = (int) 1e17;
    if (s == n / 2) {
      vector<int> B;
      for (int i = 1; i < n; i += 2) B.pb(i);
      vector<int> C;
      for (int i = 0; i < n; i++) {
        if (A[i] == 1) {
          C.pb(i);
        }
      }
      int kek = 0;
      for (int i = 0; i < n / 2; i++) {
        kek += abs(B[i] - C[i]);
      }
      ans = min(ans, kek);
    }
    if (s == (n + 1) / 2) {
      vector<int> B;
      for (int i = 0; i < n; i += 2) B.pb(i);
      vector<int> C;
      for (int i = 0; i < n; i++) {
        if (A[i] == 1) {
          C.pb(i);
        }
      }
      int kek = 0;
      for (int i = 0; i < (n + 1) / 2; i++) {
        kek += abs(B[i] - C[i]);
      }
      ans = min(ans, kek);
    }
    cout << ans << '\n';
  } else {
    cout << "-1\n";
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