#include <bits/stdc++.h>
using namespace std;

pair<int, int> dfs(int v, int pr, int val, const vector<vector<int>> &es, vector<int> &prev, vector<int> &x) {
  if (prev[v] == -2) return {-1, -1};
  if (x[v] != -1 && x[v] != val) return {v, pr};
  if (prev[v] != -1 || x[v] != -1) return {-1, -1};
  prev[v] = pr;
  x[v] = val;

  for (int w : es[v]) {
    auto kk = dfs(w, v, val, es, prev, x);
    if (kk.first != -1) return kk;
  }
  return {-1, -1};
}

void solve() {
  int n, m, s;
  cin >> n >> m >> s;
  s--;
  vector<vector<int>> es(n);
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    es[v1].push_back(v2);
  }

  vector<int> prev(n, -1);
  prev[s] = -2;
  vector<int> x(n, -1);

  auto printPath = [&](int v, int add) {
    vector<int> path;
    if (add == -1) path = {v};
    else path = {add, v};

    while (path.back() != s) path.push_back(prev[path.back()]);
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (int w : path) cout << w + 1 << " ";
    cout << "\n";
  };

  for (int w : es[s]) {
    auto k = dfs(w, s, w, es, prev, x);
    if (k.first != -1) {
      cout << "Possible\n";
      printPath(k.first, -1);
      printPath(k.second, k.first);
      return;
    }
  }
  cout << "Impossible\n";
}

int main() {
  int t = 1;
#ifdef SERT
  freopen("../a.in", "r", stdin);
  t = 3;
#endif
  while (t--) {
    solve();
  }
}