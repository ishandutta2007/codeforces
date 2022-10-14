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
  int f = 0, l = n - 1;
  while (f < l) {
    if (A[f] == A[l]) {
      f++;
      l--;
    } else {
      break;
    }
  }
  if (f >= l) {
    cout << "YES\n";
    return;
  }
  vector<int> c = {A[f], A[l]};
  for (auto x : c) {
    vector<int> B;
    for (auto y : A) {
      if (y != x) {
        B.pb(y);
      }
    }
    vector<int> C = B;
    reverse(all(B));
    if (B == C) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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