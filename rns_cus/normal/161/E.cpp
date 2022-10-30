#include <bits/stdc++.h>
using namespace std;
#define M 100010
int p[M], flag[M], cnt, able[M][10], n, ans, V[20];
int a[20][20];
int sz[M];

void init() {
  flag[1] = flag[0] = 1;
  for (int i = 2; i < 100000; i++) {
    if (!flag[i]) {
      p[cnt++] = i;
      for (int j = 2 * i; j < 100000; j += i) flag[j] = 1;
    }
  }
  for (int i = 0; i < cnt; i++) {
    int x = p[i], m = 0;
    while (x) {able[x][m++] = 1; x /= 10;}
  }
  for (int i = 1; i <= 5; i++) able[0][i] = 1;
  for (int i = 0; i < 100000; i += 10) {
    for (int j = 1; j < 10; j++) sz[i] += !flag[i + j];
  }
}

void dfs(int x, int y, int v) {
  if (y == n) {
    x++; dfs(x, x, V[x]);
    return;
  }
  if (x == n - 1 && y == n - 1) {
    ans += sz[10 * v];
    //for (int i = 1; i <= 9; i += 2) if (!flag[10 * v + i]) ans++;
    return;
  }
  int Y = V[y];
  for (int i = 0; i <= 9; i++) {
    int t = 10 * v + i;
    if (able[t][n-1-y]) {V[y] = Y * 10 + i; dfs(x, y + 1, t);}
  }
  V[y] = Y;
}

int main() {
  //freopen("in.txt", "r", stdin);
  int T; char s[20];
  init();
  for (scanf("%d", &T); T--; ) {
    scanf("%s", s);
    n = strlen(s); ans = 0;
    if (n == 1) {
      puts("1"); continue;
    }
    for (int i = 0; i < n; i++) a[0][i] = s[i] - '0', V[i] = s[i] - '0';
    for (int i = 0; i < n; i++) a[i][0] = s[i] - '0';
    dfs(1, 1, a[1][0]);
    printf("%d\n", ans);
  }
}