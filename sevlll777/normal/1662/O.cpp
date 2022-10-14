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
const int L = 41;
const int A = 360;
const int M = (L + 2) * (A + 2) + 7;

void solve() {
  vector<set<int>> g(M);
  for (int lvl = 1; lvl <= L; lvl++) {
    for (int a = 0; a < A; a++) {
      int v = lvl * A + a;
      int u = lvl * A + ((a + 1) % A);
      g[v].insert(u);
      g[u].insert(v);
    }
  }
  for (int lvl = 1; lvl < L; lvl++) {
    for (int a = 0; a < A; a++) {
      int v = lvl * A + a;
      int u = (lvl + 1) * A + a;
      g[v].insert(u);
      g[u].insert(v);
    }
  }
  for (int a = 0; a < A; a++) {
    int v = A + a;
    g[0].insert(v);
    g[v].insert(0);
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    int x, y, z;
    cin >> c >> x >> y >> z;
    if (c == 'C') {
      x *= 2;
      int a1 = y;
      int a2 = z;
      while (a1 != a2) {
        int v = x * A + a1;
        g[v] = {};
        a1++;
        if (a1 == 360) a1 = 0;
      }
    } else {
      int r1 = 2 * x;
      int r2 = 2 * y;
      for (int r = r1; r <= r2; r++) {
        int v = r * A + z;
        int v3 = r * A + ((A + z - 1) % A);
        g[v].erase(v3);
        g[v3].erase(v);
      }
    }
  }
  vector<bool> used(M, false);
  used[0] = true;
  vector<int> s = {0};
  while (!s.empty()) {
    int v = s.back();
    s.pop_back();
    for (auto u : g[v]) {
      if (!used[u]) {
        used[u] = true;
        s.pb(u);
        if (u / A == L) {
          cout << "YES\n";
          return;
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