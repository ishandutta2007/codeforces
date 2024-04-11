#include <bits/stdc++.h>
using namespace std;
#define M 1000010
int n, m, a, b, c, d;

int vis[M], cnt, v[M];

int main() {
  //freopen("B.in", "r", stdin);
  scanf("%d %d", &n, &m);
  scanf("%d %d %d %d", &a, &b, &c, &d);
  vis[a] = vis[b] = vis[c] = vis[d] = 1;
  if (n == 4 || m < n + 1) return puts("-1"), 0;
  printf("%d %d ", a, c);
  v[cnt++] = a, v[cnt++] = c;
  int cur = 1;
  for (int i = 0; i < n - 4; i++) {
    while (vis[cur]) cur++;
    vis[cur] = 1; printf("%d ", cur);
    v[cnt++] = cur;
  }
  printf("%d %d\n", d, b);
  v[cnt++] = d; v[cnt++] = b;

  swap(v[0], v[1]); swap(v[cnt - 2], v[cnt - 1]);
  for (int i = 0; i < cnt; i++) printf("%d ", v[i]); puts("");
  return 0;
}