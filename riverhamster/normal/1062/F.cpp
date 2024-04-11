#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cassert>
using namespace std;

const int N = 300005;
vector<int> G[N], R[N];
int f[N];
bool vis[N];
int n, m;

void toposort(vector<int> *G) {
  static int q[N], ind[N];
  int l = 0, r = 0;
  fill(ind + 1, ind + 1 + n, 0);
  for (int i = 1; i <= n; ++i)
    for (int v : G[i]) ++ind[v];
  for (int i = 1; i <= n; ++i)
    if (!ind[i]) q[++r] = i;
  while (l < r) {
    int x = q[++l];
    if (l == r) f[x] += n - l;
    else if (l + 1 == r) {
      int y = q[l + 1];
      bool flagy = true;
      for (int v : G[y])
        if (ind[v] == 1) { flagy = false; break; }
      if (flagy) f[x] += n - l - 1;
      else f[x] = -1000000000;
    }
    for (int v : G[x]) {
      --ind[v];
      if (ind[v] == 0) q[++r] = v;
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v); R[v].push_back(u);
  }
  toposort(G);
  toposort(R);
  int res = 0;
  for (int i = 1; i <= n; ++i)
    res += f[i] >= n - 2;
  cout << res << endl;
  return 0;
}