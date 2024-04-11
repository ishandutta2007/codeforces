#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
const int M = 50;

int n, m, d, tt, cc, last[N], scc[N][M], w[N * M], dp[N * M], px[N * M], py[N * M], qx[N * M], qy[N * M];
vector<int> adj[N], rev_adj[N];
bool open[N][M], visit[N][M];

void dfs(int x, int y) {
  visit[x][y] = true;
  for (auto z : adj[x]) {
    if (!visit[z][(y + 1) % d]) {
      dfs(z, (y + 1) % d);
    }
  }
  px[tt] = x;
  py[tt] = y;
  ++tt;
}

void dfs_rev(int x, int y) {
  scc[x][y] = cc;
  if (open[x][y] && last[x] != cc) {
    last[x] = cc;
    ++w[cc];
  }
  qx[tt] = x;
  qy[tt] = y;
  ++tt;
  for (auto z : rev_adj[x]) {
    if (scc[z][(y + d - 1) % d] == -1) {
      dfs_rev(z, (y + d - 1) % d);
    }
  }
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> d;
  for (int i = 0; i < m; ++i) {
    int from, to;
    cin >> from >> to;
    --from;
    --to;
    adj[from].push_back(to);
    rev_adj[to].push_back(from);
  }
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < d; ++j) {
      open[i][j] = s[j] == '1';
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < d; ++j) {
      if (!visit[i][j]) {
        dfs(i, j);
      }
      scc[i][j] = -1;
    }
    last[i] = -1;
  }
  tt = 0;
  for (int i = n * d - 1; ~i; --i) {
    if (scc[px[i]][py[i]] == -1) {
      dfs_rev(px[i], py[i]);
      ++cc;
    }
  }
  for (int i = n * d - 1; ~i; --i) {
    int x = qx[i], y = qy[i];
    dp[scc[x][y]] = max(dp[scc[x][y]], w[scc[x][y]]);
    for (auto z : adj[x]) {
      if (scc[z][(y + 1) % d] > scc[x][y]) {
        dp[scc[x][y]] = max(dp[scc[x][y]], dp[scc[z][(y + 1) % d]] + w[scc[x][y]]);
      }
    }
  }
  cout << dp[scc[0][0]] << "\n";
  return 0;
}