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
// #define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(10);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= 10;
    cnt[a[i]]++;
  }
  for (int u = 0; u < 10; u++) {
    for (int b = 0; b < 10; b++) {
      for (int c = 0; c < 10; c++) {
        if ((u + b + c) % 10 == 3) {
          vector<int> cnt2(10);
          cnt2[u]++;
          cnt2[b]++;
          cnt2[c]++;
          if (cnt[u] >= cnt2[u] && cnt[b] >= cnt2[b] && cnt[c] >= cnt2[c]) {
            cout << "YES\n";
            return;
          }
        }
      }
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