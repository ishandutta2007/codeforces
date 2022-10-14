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
#include <complex>
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
  vector<int> A(n + 1);
  for (int i = 1; i <= n; i++) cin >> A[i];
  vector<bool> used(n + 1, false);
  set<int> ind;
  int cc = 0;
  for (int i = 1; i <= n; i++) {
    if (!used[A[i]]) {
      used[A[i]] = true;
      cc++;
    } else {
      ind.insert(i);
    }
  }
  int a = 0;
  set<int> nums;
  for (int x = 1; x <= n; x++) {
    if (!used[x]) {
      nums.insert(x);
      if (ind.find(x) != ind.end()) {
        a++;
      }
    }
  }
  if (a != 1) {
    vector<int> inter;
    set<int> onums = nums;
    for (auto x : ind) {
      if (nums.find(x) != nums.end()) {
        inter.pb(x);
        nums.erase(x);
      }
    }
    for (int i = 0; i < (int) inter.size(); i++) {
      A[inter[i]] = inter[(i + 1) % ((int) inter.size())];
    }
    for (auto x : ind) {
      if (onums.find(x) == onums.end()) {
        A[x] = *nums.begin();
        nums.erase(nums.begin());
      }
    }
  } else {
    if (cc != n - 1) {
      int x = 0;
      for (auto num : ind) {
        if (nums.find(num) != nums.end()) {
          x = num;
        }
      }
      int kek = 0;
      for (auto num : ind) {
        if (num != x) {
          A[num] = x;
          kek = num;
          break;
        }
      }
      ind.erase(kek);
      nums.erase(x);
      vector<int> inter;
      set<int> onums = nums;
      for (auto x : ind) {
        if (nums.find(x) != nums.end()) {
          inter.pb(x);
        }
      }
      for (int i = 0; i < (int) inter.size(); i++) {
        A[inter[i]] = inter[(i + 1) % ((int) inter.size())];
      }
      for (auto x : ind) {
        if (onums.find(x) == onums.end()) {
          A[x] = *nums.begin();
          nums.erase(nums.begin());
        }
      }
    } else {
      int x = 0;
      for (auto num : ind) {
        if (nums.find(num) != nums.end()) {
          x = num;
        }
      }
      int x2 = A[x];
      for (int i = 1; i <= n; i++) {
        if (i == x) {
          A[i] = x2;
        } else if (A[i] == x2) {
          A[i] = x;
        }
      }
    }
  }
  cout << cc << '\n';
  for (int i = 1; i <= n; i++) cout << A[i] << ' ';
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