#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int tin[N], tout[N], TIME = 0;
int cnt[N], best[N];
vector <int> g[N];
int ans[N];

void dfs(int v, int pr) {
  tin[v] = ++TIME;
  cnt[v] = 1;
  best[v] = -1;
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (u == pr) {
      continue;
    }
    dfs(u, v);
    if (best[v] == -1) {
      best[v] = u;
    } else {
      if (cnt[u] > cnt[best[v]]) {
        best[v] = u;
      }
    }
    cnt[v] += cnt[u];
  }
  tout[v] = ++TIME;
}

inline bool anc(int x, int y) {
  return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

void solve(int v, int pr, int c) {
  while (true) {
    if (best[c] == -1) {
      break;
    }
    if (2 * cnt[best[c]] > cnt[v]) {
      c = best[c];
    } else {
      break;
    }
  }
  ans[v] = c;
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (u == pr) {
      continue;
    }
    if (anc(u, c)) {
      solve(u, v, c);
    } else {
      solve(u, v, u);
    }
  }
}

int main() {
  int n, tt;
  scanf("%d %d", &n, &tt);
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    p--;
    g[p].push_back(i);
    g[i].push_back(p);
  }
  dfs(0, -1);
  solve(0, -1, 0);
  while (tt--) {
    int v;
    scanf("%d", &v);
    v--;
    printf("%d\n", ans[v] + 1);
  }
  return 0;
}