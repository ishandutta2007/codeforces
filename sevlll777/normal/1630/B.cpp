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
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  vector<int> cnt(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    cnt[A[i]]++;
  }
  vector<int> P(n + 1);
  for (int i = 1; i <= n; i++) {
    P[i] = P[i - 1] + cnt[i];
  }
  int l = 0, r = n + 1;
  while (r - l > 1) {
    int len = (l + r) / 2;
    int w = (int) -1e9;
    for (int x1 = 1; x1 <= n - len + 1; x1++) {
      int y1 = x1 + len - 1;
      int kek = P[y1] - P[x1 - 1];
      kek -= (n - kek);
      w = max(w, kek);
    }
    if (w < k) {
      l = len;
    } else {
      r = len;
    }
  }
  int len = l + 1;
  int w = (int) -1e9;
  int x = 1;
  for (int x1 = 1; x1 <= n - len + 1; x1++) {
    int y1 = x1 + len - 1;
    int kek = P[y1] - P[x1 - 1];
    kek -= (n - kek);
    if (w < kek) {
      w = kek;
      x = x1;
    }
  }
  int y = x + len - 1;
  cout << x << ' ' << y << '\n';
  int lf = 0;
  int c = 0;
  int seg = 0;
  for (int i = 0; i < n; i++) {
    c += 1 - 2 * (!(x <= A[i] && A[i] <= y));
    if (c == 1) {
      if (seg == k - 1) {
        cout << lf + 1 << ' ' << n << '\n';
        return;
      }
      cout << lf + 1 << ' ' << i + 1 << '\n';
      lf = i + 1;
      c = 0;
      seg++;
    }
  }
  if (seg < k) {
    cout << lf + 1 << ' ' << n << '\n';
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