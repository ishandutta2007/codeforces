#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> es(n - 1);
  vector<set<int>> g(n);
  for (int id = 0; id < n - 1; ++id) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    es[id] = u ^ v;
    g[u].insert(id);
    g[v].insert(id);
  }
  queue<int> que;
  for (int v = 0; v < n; ++v) {
    if (g[v].size() == 1) {
      que.push(v);
    }
  }
  vector<int> res(n - 1, -1);
  int nxt = 0;
  while (not que.empty()) {
    int v = que.front();
    que.pop();
    if (g[v].empty()) {
      continue;
    }
    int id = *begin(g[v]);
    res[id] = nxt++;
    int u = es[id] ^ v;
    g[v].erase(id);
    g[u].erase(id);
    if (g[u].size() == 1) {
      que.push(u);
    }
  }
  for (auto e : res) {
    cout << e << '\n';
  }
}