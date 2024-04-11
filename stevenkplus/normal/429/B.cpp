#include <cstdio>

const int MAXN = 1010;

int grid[MAXN][MAXN];
int lft[MAXN][MAXN]; // dist to [N][1]
int rgt[MAXN][MAXN]; // dist to [N][M]
int uft[MAXN][MAXN]; // dist to [1][1]
int rft[MAXN][MAXN]; // dist to [1][M]
int addL[MAXN][MAXN];
int addR[MAXN][MAXN];
int addU[MAXN][MAXN];
int addF[MAXN][MAXN];

int N, M;

void check(int &x, int y) {
  if (y > x) x = y;
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 1; i <= N; ++i) {
    for(int j = 1; j <= M; ++j) {
      scanf("%d", grid[i] + j);
    }
  }

  for(int i = N; i > 0; --i) {
    for(int j = 1; j <= M; ++j) {
      lft[i][j] = grid[i][j] + addL[i][j];
      int val = lft[i][j];
      check(addL[i - 1][j], val);
      check(addL[i][j + 1], val);
    }
    for(int j = M; j > 0; --j) {
      rgt[i][j] = grid[i][j] + addR[i][j];
      int val = rgt[i][j];
      check(addR[i - 1][j], val);
      check(addR[i][j - 1], val);
    }
  }

  for(int i = 1; i <= N; ++i) {
    for(int j = 1; j <= M; ++j) {
      uft[i][j] = grid[i][j] + addU[i][j];
      int val = uft[i][j];
      check(addU[i][j + 1], val);
      check(addU[i + 1][j], val);
    }
    for(int j = M; j >= 1; --j) {
      rft[i][j] = grid[i][j] + addF[i][j];
      int val = rft[i][j];
      check(addF[i][j - 1], val);
      check(addF[i + 1][j], val);
    }
  }

  int ans = 0;
  for(int i = 2; i < N; ++i) {
    for(int j = 2; j < M; ++j) {
      int choice1 = uft[i][j - 1] + rgt[i][j + 1] + rft[i - 1][j] + lft[i + 1][j];
      int choice2 = uft[i - 1][j] + rgt[i + 1][j] + rft[i][j + 1] + lft[i][j - 1];
      if (choice1 > ans) ans = choice1;
      if (choice2 > ans) ans = choice2;
    }
  }

  printf("%d\n", ans);
  return 0;
}