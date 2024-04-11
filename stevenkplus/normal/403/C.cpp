#include <cstdio>

const int MAXN = 2010;
int adj[MAXN][MAXN];

bool vis[MAXN];
int N;

void dfs(int cur, int dir) {
  if (vis[cur]) return;
  vis[cur] = true;
  for(int i = 0; i < N; ++i) {
    if (dir == 0) {
      if (adj[cur][i]) {
        dfs(i, dir);
      }
    } else {
      if (adj[i][cur]) {
        dfs(i, dir);
      }
    }
  }
}

bool go(int dir) {
  for(int i = 0; i < N; ++i) {
    vis[i] = false;
  }
  dfs(0, dir);
  for(int i = 0; i < N; ++i) {
    if (!vis[i]) return false;
  }
  return true;
}


int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      scanf("%d", adj[i] + j);
    }
  }
  if (go(0) && go(1)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}