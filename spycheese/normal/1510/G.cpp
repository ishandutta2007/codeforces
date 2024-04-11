#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> e(n);
  vector<int> par(n);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    e[p].push_back(i);
    par[i] = p;
  }
  par[0] = -1;
  vector<int> any(n, -1);
  int mdep = 0;
  function<void(int, int)> dfs1 = [&](int v, int dep) {
    mdep = max(dep, mdep);
    any[dep] = v;
    for (int nv : e[v])
      dfs1(nv, dep + 1);
  };
  dfs1(0, 0);
  mdep = min(mdep, k - 1);
  int rem = k - mdep - 1;

  assert(rem >= 0);
  int v1 = any[mdep];
  vector<int> mark(n);
  {
    int v2 = v1;
    while (true) {
      mark[v2] = 1;
      int pv = v2;
      v2 = par[v2];
      if (v2 == -1) break;
      for (int i = 0; i < sz(e[v2]); ++i) {
        if (e[v2][i] == pv) {
          swap(e[v2][i], e[v2].back());
          break;
        }
      }
    }
  }

  vector<int> ans;
  function<void(int, int)> dfs2 = [&](int v, int dep) {
    ans.push_back(v);
    if (dep == mdep) return;
    if (e[v].empty()) return;
    int lv = mark[v] ? e[v].back() : -1;
    for (int nv : e[v]) {
      if (lv != nv) {
        if (rem == 0) continue;
        --rem;
      }
      dfs2(nv, dep + 1);
      ans.push_back(v);
    }
  };

  dfs2(0, 0);
  while (ans.back() != v1) ans.pop_back();
  cout << sz(ans) - 1 << "\n";
  for (int x : ans) cout << x + 1 << " ";
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}