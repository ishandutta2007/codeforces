#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int N = 200500;
vector<pair<int, int>> g[N];
bool red[N];
bool used[N];
int d[N], par[N];

void dfs(int v) {
  used[v] = true;
  for (auto u : g[v]) {
    if (!used[u.first]) {
      par[u.first] = v;
      d[u.first] = d[v] + 1;
      dfs(u.first);
      red[u.second] = true;
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edg;
  for (int i = 0; i < m + 7; i++) {
    g[i] = {};
    used[i] = false;
    red[i] = false;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].pb({b, i});
    g[b].pb({a, i});
    edg.pb({a, b});
  }
  d[0] = 0;
  dfs(0);
  vector<int> c(n);
  for (int i = 0; i < m; i++) {
    if (!red[i]) {
      c[edg[i].first]++;
      c[edg[i].second]++;
    }
  }
  sort(all(c));
  if (c.size() < 3 || c[(int) c.size() - 3] < 2) {
    for (int i = 0; i < m; i++) {
      cout << red[i];
    }
    cout << '\n';
    return;
  }
  int dj = -1;
  int v = 0;
  for (int i = 0; i < m; i++) {
    if (!red[i]) {
      if (dj < d[edg[i].first]) {
        dj = d[edg[i].first];
        v = edg[i].first;
      }
      if (dj < d[edg[i].second]) {
        dj = d[edg[i].second];
        v = edg[i].second;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (!red[i]) {
      if (edg[i].first == v || edg[i].second == v) {
        red[i] = 1 - red[i];
        break;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if ((edg[i].first == v && edg[i].second == par[v]) || (edg[i].first == par[v] && edg[i].second == v)) {
      red[i] = 1 - red[i];
      break;
    }
  }
  for (int i = 0; i < m; i++) {
    cout << red[i];
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