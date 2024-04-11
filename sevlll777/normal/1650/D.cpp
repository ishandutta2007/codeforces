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
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> q(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    q[p[i]] = i;
  }

  deque<int> sas;
  vector<int> dd;
  for (int el = 1; el <= n; el++) {
    int qq = q[el];
    int prev = -1;
    for (auto x : dd) {
      if (x < qq) {
        prev = max(prev, x);
      }
    }
    dd.pb(qq);
    if (prev == -1 && !dd.empty()) {
      prev = *max_element(all(dd));
    }
    if (el > 1) {
      int cnt = 0;
      while (sas.back() != p[prev]) {
        int h = sas.back();
        sas.pop_back();
        sas.push_front(h);
        cnt++;
      }
      sas.pb(el);
      cout << cnt << ' ';
    } else {
      sas.pb(el);
    }
  }
  int cnt = 0;
  while (sas.back() != p[n - 1]) {
    int h = sas.back();
    sas.pop_back();
    sas.push_front(h);
    cnt++;
  }
  cout << cnt;
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