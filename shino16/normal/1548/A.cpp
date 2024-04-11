#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n, m, q;
set<int> graph[200000];
int gt[200000];
int x;

int main() {
  scanf("%d%d", &n, &m);
  rep(_, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    graph[u].insert(v);
    graph[v].insert(u);
    (u < v ? gt[u] : gt[v])++;
  }
  rep(v, n) x += gt[v] == 0;
  scanf("%d", &q);
  while (q--) {
    int c; scanf("%d", &c);
    if (c == 1) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      graph[u].insert(v);
      graph[v].insert(u);
      if ((u < v ? gt[u] : gt[v])++ == 0) x--;
    } else if (c == 2) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      graph[u].erase(v);
      graph[v].erase(u);
      if (--(u < v ? gt[u] : gt[v]) == 0) x++;
    } else {
      printf("%d\n", x);
    }
  }
}