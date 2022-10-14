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
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int k = n;
  for (int i = 1; i <= n; i++) {
    if (b[i] < i) {
      k = i - 1;
      break;
    }
  }
  vector<vector<int>> invb(n + 2);
  for (int i = 1; i <= n; i++) {
    invb[b[i]].pb(i);
  }
  vector<bool> done(n + 1, false);
  vector<int> a;
  set<pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    if (b[i] == 0 || b[i] == n + 1) {
      q.insert({(int) invb[i].size(), i});
    }
  }
  int t = (int) 1e8;
  while (!q.empty()) {
    int i = (*q.begin()).second;
    q.erase(q.begin());
    done[i] = true;
    a.pb(i);
    vector<pair<int, int>> lul;
    for (auto w:invb[i]) {
      lul.pb({invb[w].size(), w});
    }
    sort(all(lul));
    for (auto pr:lul) {
      q.insert({t++, pr.second});
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!done[i]) {
      a.pb(i);
    }
  }
  cout << k << '\n';
  for (auto x : a) {
    cout << x << ' ';
  }
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