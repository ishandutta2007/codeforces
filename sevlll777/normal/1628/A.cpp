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
  vector<int> M(n + 1);
  M[n] = -1;
  int ms = 0;
  set<int> nums;
  for (int i = n - 1; i >= 0; i--) {
    nums.insert(A[i]);
    while (nums.find(ms) != nums.end()) {
      ms++;
    }
    M[i] = ms;
  }
  vector<int> ans;
  int now = M[0];
  set<int> kek;
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] < now && kek.find(A[i]) == kek.end()) {
      kek.insert(A[i]);
      c++;
    }
    if (c == now) {
      ans.pb(now);
      now = M[i + 1];
      kek = {};
      c = 0;
    }
  }
  if (now != -1) {
    ans.pb(now);
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