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
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1), c(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
      c[i] = a[i] - b[i];
      p[i] = p[i - 1] + c[i];
    }
    vector<int> l(m), r(m);
    for (int i = 0; i < m; i++) {
      cin >> l[i] >> r[i];
      l[i]--;
    }
    if (p[n]) {
      cout << "NO\n";
    } else {
      vector<bool> bad(n + 1);
      set<int> bads;
      for (int i = 0; i <= n; i++) {
        bad[i] = (p[i] != 0);
        if (bad[i]) {
          bads.insert(i);
        }
      }
      bads.insert(n + 228);
      vector<vector<int>> w(n + 1);
      for (int i = 0; i < m; i++) {
        w[l[i]].pb(i);
        w[r[i]].pb(i);
      }
      set<pair<int, int>> work;
      for (int i = 0; i < m; i++) {
        int x = bad[l[i]] + bad[r[i]];
        work.insert({x, i});
      }
      while (!work.empty()) {
        pair<int, int> pr = *work.begin();
        work.erase(pr);
        int i = pr.second;
        if (pr.first != 0) {
          break;
        }
        int lf = l[i], rf = r[i];
        auto vl = bads.lower_bound(lf);
        vector<int> to_erase;
        while (*vl <= rf) {
          int j = *vl;
          bad[j] = false;
          to_erase.pb(j);
          for (auto i2 : w[j]) {
            int x = bad[l[i2]] + bad[r[i2]];
            work.insert({x, i2});
          }
          vl++;
        }
        for (auto j : to_erase) {
          bads.erase(j);
        }
      }
      if ((int) bads.size() == 1) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}