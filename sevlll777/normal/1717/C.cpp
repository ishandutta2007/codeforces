#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int _ = 0; _ < 7; _++) {
    for (int i = 0; i < n; i++) {
      if (a[i] < b[i] && a[i] <= a[(i + 1) % n]) {
        a[i] = min(a[(i + 1) % n] + 1, b[i]);
      }
    }
  }
  vector<int> kek;
  vector<vector<int>> lol;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      cout << "NO\n";
      return;
    }
    kek.pb(b[i]);
    if (a[i] == b[i]) {
      lol.pb(kek);
      kek = {};
    }
  }
  if (lol.empty()) {
    cout << "NO\n";
    return;
  }
  if (!kek.empty()) {
    vector<int> d = lol[0];
    lol[0] = kek;
    for (auto x : d) {
      lol[0].pb(x);
    }
  }
  for (auto m : lol) {
    if (!is_sorted(all(m))) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";

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