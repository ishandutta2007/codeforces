#include <bits/stdc++.h>
using namespace std;
#define N 111

int a[N], b[N], n, m, x, y;
bool vis[N], col[N];
vector <int> v[N];

bool inside(int a, int b, int c) {
  if (a < c && c < b) return 1;
  return 0;
}

bool outside(int a, int b, int c) {
  if (c < a || c > b) return 1;
  return 0;
}

bool common(int i, int j) {
  if (inside(a[i], b[i], a[j]) && outside(a[i], b[i], b[j])) return 1;
  if (inside(a[i], b[i], b[j]) && outside(a[i], b[i], a[j])) return 1;
  return 0;
}

bool bad(int x) {
  vis[x] = 1;
  for (int i = 0; i < v[x].size(); i ++) {
    int y = v[x][i];
    if (vis[y]) {
      if (col[x] == col[y]) return 1;
      continue;
    }
    col[y] = 1 - col[x];
    if (bad(y)) return 1;
  }
  return 0;
}

int main() {
 // freopen("d.in", "r", stdin);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i ++) {
    scanf("%d %d", &x, &y);
    if (x > y) swap(x, y);
    a[i] = x, b[i] = y;
  }
  for (int i = 1; i <= m; i ++) {
    for (int j = i + 1; j <= m; j ++) {
      if (common(i, j)) v[i].push_back(j), v[j].push_back(i);
    }
  }
  for (int i = 1; i <= m; i ++) {
    if (vis[i]) continue;
    col[i] = 0;
    if (bad(i)) {
      puts("Impossible"); return 0;
    }
  }
  for (int i = 1; i <= m; i ++) printf("%c", col[i] ? 'i' : 'o');
  puts("");
  return 0;
}