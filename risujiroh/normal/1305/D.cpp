#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<int> deg(n);
  for (int _ = n - 1; _--; ) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    ++deg[u], ++deg[v];
  }
  queue<int> que;
  for (int v = 0; v < n; ++v) {
    if (deg[v] == 1) {
      que.push(v);
    }
  }
  while (not que.empty()) {
    if (que.size() == 1) {
      cout << "! " << que.front() + 1 << endl;
      exit(0);
    }
    int u = que.front();
    que.pop();
    int v = que.front();
    que.pop();
    cout << "? " << u + 1 << ' ' << v + 1 << endl;
    int w;
    cin >> w;
    --w;
    if (w == u or w == v) {
      cout << "! " << w + 1 << endl;
      exit(0);
    }
    for (int to : g[u]) {
      if (--deg[to] == 1) {
        que.push(to);
      }
    }
    for (int to : g[v]) {
      if (--deg[to] == 1) {
        que.push(to);
      }
    }
  }
}