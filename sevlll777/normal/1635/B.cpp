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
  vector<bool> kek(n, false);
  for (int i = 1; i < n - 1; i++) {
    if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
      kek[i] = true;
    }
  }
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    if (kek[i]) {
      if (i + 2 < n && kek[i + 2]) {
        A[i + 1] = max(A[i], A[i + 2]);
        ans++;
        kek[i + 2] = false;
      } else {
        A[i] = max(A[i - 1], A[i + 1]);
        ans++;
      }
    }
  }
  cout << ans << '\n';
  for (auto x : A) {
    cout << x << ' ';
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