#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;
int v[N];
bool vis[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  for (scanf("%d", &T); T; --T) {
    int n, m;
    scanf("%d%d", &n, &m);
    fill(v + 1, v + 1 + n, 0);
    fill(vis + 1, vis + 1 + n, false);
    for (int i = 1; i <= m; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      v[x] = y;
    }
    int res = m;
    for (int i = 1; i <= n; ++i) {
      if (vis[i]) continue;
      if (v[i] == i) { --res; continue; }
      int x = i; vis[x] = true;
      x = v[x]; vis[x] = true;
      while (x != i && x) {
        x = v[x];
        if (vis[x]) break;
        vis[x] = true;
      }
      if (x == i) ++res;
    }
    printf("%d\n", res);
  }
  return 0;
}