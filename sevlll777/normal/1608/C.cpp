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
const int M = 998244353;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> B[i];
    }
    vector<pair<int, int>> ia, ib;
    for (int i = 0; i < n; i++) {
      ia.pb({A[i], i});
      ib.pb({B[i], i});
    }
    sort(all(ia));
    sort(all(ib));
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      g[ia[i].second].pb(ia[i + 1].second);
      g[ib[i].second].pb(ib[i + 1].second);
    }
    vector<bool> used(n, false);
    vector<int> s = {ia.back().second, ib.back().second};
    for (auto v : s) used[v] = true;
    while (!s.empty()) {
      int v = s.back();
      s.pop_back();
      for (auto u : g[v]) {
        if (!used[u]) {
          used[u] = true;
          s.pb(u);
        }
      }
    }
    for (int i = 0; i < n; i++)
      cout << used[i];
    cout << '\n';
  }

}