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
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = 0, r = (int) 1e9 + 4;
  while (r - l > 1) {
    int m = (l + r) / 2;
    int last = 0;
    vector<int> dl;
    for (int i = 0; i < n; i++) {
      if (a[i] - (m + 1) >= last) {
        last = a[i];
      } else {
        if (i) {
          dl.pb(i - 1);
        }
        dl.pb(i);
      }
    }
    if (dl.size() > 7) {
      r = m;
    } else {
      bool ok = false;
      for (auto i : dl) {
        bool can = true;
        vector<int> b;
        for (int j = 0; j < n; j++) {
          if (j != i) {
            b.pb(a[j]);
          }
        }
        last = 0;
        int md = 0;
        for (int j = 0; j < n - 1; j++) {
          if (b[j] - (m + 1) >= last) {
            md = max(md, b[j] - last);
            last = b[j];
          } else {
            can = false;
            break;
          }
        }
        md = max(md, d + 1 - b.back() + m);
        md--;
        if (md >= 2*m+1) {
          ok |= can;
        }
      }
      if (ok || dl.empty()) {
        l = m;
      } else {
        r = m;
      }
    }
  }
  cout << l << '\n';
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