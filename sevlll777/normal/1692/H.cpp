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
  vector<int> x(n);
  map<int, vector<int>> w;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    w[x[i]].pb(i);
  }
  int mx = 1;
  int a = x[0], l = 0, r = 0;
  for (auto p : w) {
    vector<int> d = p.second;
    int mr = -1e9;
    int dre = 0;
    for (int i = 0; i < d.size(); i++) {
      int cr = d[i] - 2 * i;
      if (mx < mr - cr + 1) {
        mx = mr - cr + 1;
        a = p.first;
        l = dre;
        r = d[i];
      }
      if (mr < cr) {
        mr = cr;
        dre = d[i];
      }
    }
  }
  cout << a << ' ' << l + 1 << ' ' << r + 1 << '\n';
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