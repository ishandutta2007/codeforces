#include <bits/stdc++.h>
using namespace std;

struct HLD {
  const int n;
  int t;
  vector< vector<int> > g;
  vector<int> sz, dep, in, par, anc;
  HLD(const vector< vector<int> >& _g) :
      n(_g.size()), g(_g), sz(n), dep(n), in(n), par(n), anc(n) {
    dfs_sz(0);
    t = 0;
    dfs(0);
  }
  void dfs_sz(int v) {
    sz[v] = 1;
    for (int u : g[v]) {
      dep[u] = dep[v] + 1;
      dfs_sz(u);
      sz[v] += sz[u];
    }
    sort(begin(g[v]), end(g[v]), [&](int l, int r) {
      return sz[l] > sz[r];
    });
  }
  void dfs(int v) {
    in[v] = t++;
    for (int u : g[v]) {
      par[u] = v;
      anc[u] = u == g[v][0] ? anc[v] : u;
      dfs(u);
    }
  }
  int lca(int u, int v) {
    while (true) {
      if (in[u] > in[v]) {
        swap(u, v);
      }
      if (anc[u] == anc[v]) {
        return u;
      }
      v = par[anc[v]];
    }
  }
};

template <class T, class U> void chmin(T& a, U b) { a = min(a, b); }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int a;
  cin >> a;
  vector< vector<int> > g(a);
  for (int v = 1; v < a; ++v) {
    int p;
    cin >> p;
    --p;
    g[p].push_back(v);
  }
  vector<int> x(n);
  for (auto&& e : x) {
    cin >> e;
    --e;
  }
  int b;
  cin >> b;
  vector< vector<int> > h(b);
  for (int v = 1; v < b; ++v) {
    int p;
    cin >> p;
    --p;
    h[p].push_back(v);
  }
  vector<int> y(n);
  for (auto&& e : y) {
    cin >> e;
    --e;
  }
  HLD ha(g);
  HLD hb(h);
  auto fa = [&](int i, int j) {
    if (i == -1) {
      return ha.dep[x[j]];
    }
    return ha.dep[x[j]] - ha.dep[ha.lca(x[i], x[j])];
  };
  auto fb = [&](int i, int j) {
    if (i == -1) {
      return hb.dep[y[j]];
    }
    return hb.dep[y[j]] - hb.dep[hb.lca(y[i], y[j])];
  };
  vector< vector<int> > dp(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int k = max(i, j);
      chmin(dp[k + 1][j], dp[i][j] + fa(i - 1, k));
      chmin(dp[i][k + 1], dp[i][j] + fb(j - 1, k));
    }
  }
  int res = 0x3f3f3f3f;
  for (int i = 0; i <= n; ++i) {
    res = min(res, dp[n][i]);
    res = min(res, dp[i][n]);
  }
  res = (a - 1) + (b - 1) - res;
  cout << res << '\n';
}