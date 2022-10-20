#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

struct node { string t; int x, y; };

int dfs(int i, vector<node> &g, VI &v) {
  if (g[i].t == "IN") return v[i] = g[i].x;
  if (g[i].t == "NOT") return v[i] = 1 - dfs(g[i].x, g, v);
  if (g[i].t == "AND") return v[i] = dfs(g[i].x, g, v) & dfs(g[i].y, g, v);
  if (g[i].t == "XOR") return v[i] = dfs(g[i].x, g, v) ^ dfs(g[i].y, g, v);
  if (g[i].t == "OR") return v[i] = dfs(g[i].x, g, v) | dfs(g[i].y, g, v);
}

void dfs2(int i, vector<node> &g, VI &v, VI &c) {
  if (g[i].t == "IN") {
    c[i] = 1;
    return;
  }
  if (g[i].t == "NOT") {
    dfs2(g[i].x, g, v, c);
    return;
  }
  if (g[i].t == "AND") {
    if (v[i] == 1) {
      dfs2(g[i].x, g, v, c);
      dfs2(g[i].y, g, v, c);
      return;
    } else {
      if (v[g[i].x] == 0 and v[g[i].y] == 0) return;
      if (v[g[i].x] == 0) {
        dfs2(g[i].x, g, v, c);
        return;
      }
      if (v[g[i].y] == 0) {
        dfs2(g[i].y, g, v, c);
        return;
      }
    }
  }
  if (g[i].t == "XOR") {
    dfs2(g[i].x, g, v, c);
    dfs2(g[i].y, g, v, c);
    return;
  }
  if (g[i].t == "OR") {
    if (v[i] == 0) {
      dfs2(g[i].x, g, v, c);
      dfs2(g[i].y, g, v, c);
      return;
    } else {
      if (v[g[i].x] == 1 and v[g[i].y] == 1) return;
      if (v[g[i].x] == 1) {
        dfs2(g[i].x, g, v, c);
        return;
      }
      if (v[g[i].y] == 1) {
        dfs2(g[i].y, g, v, c);
        return;
      }
    }
  }
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<node> g(n);
  for (int i = 0; i < n; i++) {
    string t; cin >> t;
    int x, y = 0;
    if (t == "IN") cin >> x;
    else if (t == "NOT") cin >> x, x--;
    else cin >> x >> y, x--, y--;
    g[i] = {t, x, y};
  }
  VI v(n);
  dfs(0, g, v);
  VI c(n);
  dfs2(0, g, v, c);
  for (int i = 0; i < n; i++) {
    if (g[i].t != "IN") continue;
    if (v[0] == 0) cout << c[i];
    else cout << 1 - c[i];
  }
  cout << '\n';
  return 0;
}