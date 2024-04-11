#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n;
vector<int> graph[200000];
map<int, int> mp[200000];
int f[200000];
int ans = INT_MAX;

int dfs(int v, int p) {
  for (auto u : graph[v])
    if (u != p) mp[v][dfs(u, v)]++;
  int x = mp[v].empty() ? 0
        : mp[v].size() == 1 && !mp[v].count(-1) ? mp[v].begin()->first + 1
        : -1;
  return f[v] = x;
}

void dfs2(int v, int p) {
  if (!mp[v].count(-1) && mp[v].size() <= 2) {
    int x = mp[v].size() == 2 ? mp[v].begin()->first + next(mp[v].begin())->first + 2 : mp[v].begin()->first + 1;
    ans = min(ans, x >> __builtin_ctz(x));
  }
  for (auto u : graph[v])
    if (u != p) {
      if (--mp[v][f[u]] == 0) mp[v].erase(f[u]);
      int x = mp[v].empty() ? 0
            : mp[v].size() == 1 && !mp[v].count(-1) ? mp[v].begin()->first + 1
            : -1;
      mp[u][x]++;
      dfs2(u, v);
      mp[v][f[u]]++;
    }
}

int main() {
  scanf("%d", &n);
  rep(_, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  dfs(0, -1);
  dfs2(0, -1);
  printf("%d\n", ans == INT_MAX ? -1 : ans);
}