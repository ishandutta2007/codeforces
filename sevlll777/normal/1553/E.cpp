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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> P(n), Q(n);
  for (int i = 0; i < n; i++) {
    cin >> P[i];
    P[i]--;
    Q[P[i]] = i;
  }
  vector<int> kek(n);
  for (int i = 0; i < n; i++) {
    int p = Q[i];
    int val = (n + p - i) % n;
    kek[val]++;
  }
  vector<int> ch;
  for (int i = 0; i < n; i++) {
    if (kek[i] >= (n / 3)) {
      ch.pb(i);
    }
  }
  vector<int> ans;
  for (auto k : ch) {
    vector<vector<int>> g(n);
    vector<bool> used(n, false);
    int c = 0;
    for (int i = n - k; i < n; i++) {
      g[i].pb(P[c]);
      g[P[c]].pb(i);
      c++;
    }
    for (int i = 0; i < n - k; i++) {
      g[i].pb(P[c]);
      g[P[c]].pb(i);
      c++;
    }
    int cmp = 0;
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        cmp++;
        vector<int> st = {i};
        while (!st.empty()) {
          int v = st.back();
          st.pop_back();
          for (auto u:  g[v]) {
            if (!used[u]) {
              used[u] = true;
              st.pb(u);
            }
          }
        }
      }
    }
    if (cmp >= n - m) {
      ans.pb(k);
    }
  }
  cout << ans.size() << ' ';
  for (auto k : ans) cout << k << ' ';
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