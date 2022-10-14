#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  vector<pair<int, int>> gg;
  for (int i = 0; i < n; i++) {
    gg.pb({d[i], i});
  }
  vector<vector<int>> g(n);
  vector<bool> used(n, false);
  sort(rall(gg));
  for (auto p : gg) {
    int v = p.second;
    if (used[v]) {
      continue;
    }
    used[v] = true;
    for (int _ = 0; _ < d[v]; _++) {
      cout << "? " << v + 1 << endl;
      int w;
      cin >> w;
      w--;
      if (used[w]) {
        g[w].pb(v);
        g[v].pb(w);
        break;
      }
      used[w] = true;
      g[v].pb(w);
      g[w].pb(v);
    }
  }
  vector<int> c(n);
  int cr = 1;
  used.assign(n + 1, false);
  for (int v = 0; v < n; v++) {
    if (!used[v]) {
      used[v] = true;
      c[v] = cr;
      vector<int> q = {v};
      while (!q.empty()) {
        int u = q.back();
        q.pop_back();
        for (auto uu : g[u]) {
          if (!used[uu]) {
            used[uu] = true;
            c[uu] = cr;
            q.pb(uu);
          }
        }
      }
      cr++;
    }
  }
  cout << "! ";
  for (auto h : c) {
    cout << h << ' ';
  }
  cout << endl;
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