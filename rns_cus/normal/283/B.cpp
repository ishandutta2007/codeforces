#include <bits/stdc++.h>

using namespace std;

#define N 200200

typedef long long LL;

int n;
int a[N];
int vis[2][N], flag[2][N], o[2][N];
LL val[2][N];

bool isrange(int x) { return 1<=x && x<=n; }

bool dfs(int i, int j) {
  vis[i][j] = 1;
  int de = a[j];
  int x = 1 - i, y;
  if(!i) y = j + de; else y = j - de;
  if(!isrange(y)) {
    val[i][j] = de;
    return 1;
  }
  if(y == 1 && x == 0) { flag[i][j] = 1; return 0; }
  if(y == 1 && x == 1) { o[i][j] = 1; val[i][j] = de; return 1; }
  if(vis[x][y]) {
    if(!val[x][y]) {
      flag[i][j] = 1; return 0;
    }
    val[i][j] = val[x][y] + de;
    if(o[x][y]) o[i][j] = 1;
    return 1;
  }
  dfs(x, y);
  if(flag[x][y]) { flag[i][j] = 1; return 0; }
  val[i][j] = val[x][y] + de;
  if(o[x][y]) o[i][j] = 1;
  return 1;
}

void init() {
  for(int i = 2; i <= n; i ++) {
    for(int j = 0; j < 2; j ++) if(!vis[j][i]) {
      dfs(j, i);
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 2 ;i <= n; i ++) scanf("%d", a + i);
  init();
  for(int i = 1; i < n; i ++) {
    if(flag[1][i+1]) puts("-1");
    else {
      LL tp = val[1][i + 1] + i;
      if(o[1][i+1]) tp += i;
      printf("%I64d\n", tp);
    }
  }
  return 0;
}