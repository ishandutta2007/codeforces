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
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> P(n);
  int f = 0;
  for (int i = 0; i < n; i++) {
    cin >> P[i];
    if (P[i] % 2 == i % 2) {
      f = 1;
    }
  }
  if (f) {
    cout << "-1\n";
    return;
  }
  vector<int> ans;
  for (int N = n; N >= 3; N -= 2) {
    int q = 0;
    for (int i = 0; i < n; i++) {
      if (P[i] == N) {
        q = i;
        break;
      }
    }
    ans.pb(q + 1);
    reverse(P.begin(), P.begin() + q + 1);
    q = 0;
    for (int i = 0; i < n; i++) {
      if (P[i] == N - 1) {
        q = i;
        break;
      }
    }
    ans.pb(q);
    reverse(P.begin(), P.begin() + q);
    ans.pb(q + 2);
    reverse(P.begin(), P.begin() + q + 2);
    ans.pb(3);
    reverse(P.begin(), P.begin() + 3);
    ans.pb(N);
    reverse(P.begin(), P.begin() + N);
  }
  cout << (int) ans.size() << '\n';
  for (auto x : ans) {
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