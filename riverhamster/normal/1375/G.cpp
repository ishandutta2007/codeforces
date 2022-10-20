#include <bits/stdc++.h>
using namespace std;

vector<int> G[200005];
int c[2];

void bicolor(int u, int fa, int col) {
  ++c[col];
  for (int v : G[u])
    if (v != fa) bicolor(v, u, !col);
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v); G[v].push_back(u);
  }
  bicolor(1, 0, 0);
  cout << min(c[0], c[1]) - 1 << endl;
}