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
  for (int i = 0; i < n; i++) cin >> A[i];
  if (n % 2) {
    n--;
    A.pop_back();
  }
  int ans = 0;
  for (int i = 0; i < n; i += 2) {
    int df = 0;
    int mn = 0;
    for (int j = i + 1; j < n; j += 2) {
      int l1 = -mn + df, r1 = A[i] + df, l2 = 1, r2 = A[j];
      ans += max(0LL, min(r1, r2) - max(l1, l2) + 1);
      mn = min(mn, df - A[j]);
      df += A[j + 1] - A[j];
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}