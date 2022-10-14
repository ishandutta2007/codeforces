#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> V(n), T(n);
  for (int i = 0; i < n; i++) cin >> V[i];
  for (int i = 0; i < n; i++) cin >> T[i];
  for (int i = 0; i < n; i++) {
    V[i] -= T[i];
  }
  int s = 0;
  for (auto x : V) {
    s += x;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  if (abs(s) % 2) {
    cout << "NO\n";
    return;
  }
  vector<bool> used(n, false);
  vector<int> color(n);
  for (int v = 0; v < n; v++) {
    if (!used[v]) {
      used[v] = true;
      deque<int> q = {v};
      while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (auto uu : g[u]) {
          if (!used[uu]) {
            q.pb(uu);
            used[uu] = true;
            color[uu] = 1 - color[u];
          } else if (color[u] == color[uu]) {
            cout << "YES\n";
            return;
          }
        }
      }
    }
  }
  int s1 = 0, s2 = 0;
  for (int v = 0; v < n; v++) {
    if (color[v]) {
      s1 += V[v];
    } else {
      s2 += V[v];
    }
  }
  if (s1 == s2) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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