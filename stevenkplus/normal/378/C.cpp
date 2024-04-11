#include <cstdio>

const int MAXN = 510;

int N, M, X;
char grid[MAXN][MAXN];
char ans[MAXN][MAXN];
bool vis[MAXN][MAXN];

int cnt = 0;
void dfs(int x, int y) {
  if (x < 0 || y < 0 || x >= N || y >= M) return;
  if (cnt >= X) return;
  if (!vis[x][y] && grid[x][y] == '.') {
    vis[x][y] = true;
    ++cnt;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
  }
}


void go() {
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      dfs(i, j);
    }
  }
}

int main() {
  scanf("%d %d %d", &N, &M, &X);
  int tot = 0;
  for(int i = 0; i < N; ++i) {
    scanf("%s", grid[i]);
    for(int j = 0; j < M; ++j) {
      if (grid[i][j] == '.') ++tot;
    }
  }
  X = tot - X;

  go();
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      if (grid[i][j] == '#') ans[i][j] = '#';
      else if (vis[i][j]) ans[i][j] = '.';
      else ans[i][j] = 'X';
    }
  }

  for(int i = 0; i < N; ++i) {
    printf("%s\n", ans[i]);
  }



  return 0;
}