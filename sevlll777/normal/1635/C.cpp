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
  if (A[n - 2] > A[n - 1]) {
    cout << "-1\n";
    return;
  }
  if (A[n - 1] >= 0) {
    cout << n - 2 << '\n';
    for (int i = 1; i <= n - 2; i++) {
      cout << i << ' ' << n - 1 << ' ' << n << '\n';
    }
  } else {
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      ok &= (A[i] <= A[i + 1]);
    }
    if (ok) {
      cout << "0\n";
    } else {
      cout << "-1\n";
    }
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