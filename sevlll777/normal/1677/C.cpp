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

void solve() {
  int n;
  cin >> n;
  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> q[i];
    q[i]--;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    g[p[i]].pb(q[i]);
    g[q[i]].pb(p[i]);
  }
  vector<bool> used(n, false);
  vector<int> C;
  for (int v = 0; v < n; v++) {
    if (!used[v]) {
      used[v] = true;
      int cnt = 1;
      vector<int> s = {v};
      while (!s.empty()) {
        int u = s.back();
        s.pop_back();
        for (auto uu : g[u]) {
          if (!used[uu]) {
            used[uu] = true;
            cnt += 1;
            s.pb(uu);
          }
        }
      }
      if (cnt >= 2) {
        C.pb(cnt - cnt % 2);
      }
    }
  }
  sort(all(C));
  int ans = 0;
  int b = n, s = 1;
  for (auto c : C) {

    vector<int> w(c);
    for (int i = 0; i < c; i++) {
      if (i % 2 == 0) {
        w[i] = b--;
      } else {
        w[i] = s++;
      }
      if (i > 0) {
        ans += abs(w[i] - w[i - 1]);
      }
    }
    ans += abs(w[c - 1] - w[0]);

  }
  cout << ans << '\n';


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