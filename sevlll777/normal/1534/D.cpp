#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

void solve() {
  int n;
  cin >> n;
  cout << "? 1" << endl;
  vector<int> d(n);
  for (int i = 0; i < n; i++) cin >> d[i];
  vector<int> ev, od;
  set<pair<int, int>> ans;
  for (int i = 1; i < n; i++) {
    if (d[i] % 2 == 0) {
      ev.pb(i);
    } else {
      if (d[i] == 1) {
        ans.insert({0, i});
      }
      od.pb(i);
    }
  }
  if ((int) ev.size() < (int) od.size()) {
    for (auto v : ev) {
      cout << "? " << v + 1 << endl;
      for (int i = 0; i < n; i++) cin >> d[i];
      for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
          ans.insert({min(v, i), max(v, i)});
        }
      }
    }
  } else {
    for (auto v : od) {
      cout << "? " << v + 1 << endl;
      for (int i = 0; i < n; i++) cin >> d[i];
      for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
          ans.insert({min(v, i), max(v, i)});
        }
      }
    }
  }
  cout << "!" << endl;
  for (auto p : ans) {
    cout << p.first + 1 << ' ' << p.second + 1 << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}