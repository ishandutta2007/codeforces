#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;
const int MAXK = 20;
int depths[MAXN];
int par[MAXN][MAXK];
vector<int> ed[MAXN];

int lca(int a, int b) {
  for(int i = MAXK - 1; i >= 0; --i) {
    if (depths[a] - (1 << i) >= depths[b]) {
      a = par[a][i];
    }
    if (depths[b] - (1 << i) >= depths[a]) {
      b = par[b][i];
    }
  }
  if (a == b) return a;
  for (int i = MAXK - 1; i >= 0; --i) {
    if (par[a][i] != par[b][i]) {
      a = par[a][i];
      b = par[b][i];
    }
  }
  return par[a][0];
}

int dist(int a, int b) {
  int c = lca(a, b);
  int ans = depths[a] + depths[b] - 2 * depths[c];
  return ans;
}

void dfs(int cur, int p = 1, int d = 0) {
  depths[cur] = d;
  par[cur][0] = p;
  for(int k: ed[cur]) {
    if (k != p) {
      dfs(k, cur, d + 1);
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }
  dfs(1);
  for (int i = 0; i + 1 < MAXK; ++i) {
    for (int j = 1; j <= n; ++j) {
      par[j][i + 1] = par[par[j][i]][i];
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int x, y, a, b, k;
    cin >> x >> y >> a >> b >> k;
    int d1 = dist(a, b);
    int d2 = dist(a, x) + 1 + dist(y, b);
    int d3 = dist(a, y) + 1 + dist(x, b);
    bool w1 = d1 <= k && d1 % 2 == k % 2;
    bool w2 = d2 <= k && d2 % 2 == k % 2;
    bool w3 = d3 <= k && d3 % 2 == k % 2;
    if (w1 || w2 || w3) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

}