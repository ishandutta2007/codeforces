#include <cstdio>

const int MAXN = 2010;
int N, M, K;

const int mx[] = {0, 0, -1, 1};
const int my[] = {-1, 1, 0, 0};

char grid[MAXN][MAXN];

int ask(int x, int y, int dir) {
  if (x < 0 || y < 0 || x >= N || y >= M) return 0;
  char c = grid[x][y];
  if (dir == 0 && c == 'L') return 1;
  if (dir == 1 && c == 'R') return 1;
  if (dir == 2 && c == 'U') return 1;
  if (dir == 3 && c == 'D') return 1;
  return 0;
}

int get(int s) {
  int ans = 0;
  for(int i = 0; i < 4; ++i) {
    for(int j = 1; j <= N; ++j) { // at (j, s)
      int x = j - mx[i] * j;
      int y = s - my[i] * j;
      ans += ask(x, y, i);
    }
  }
  return ans;
}


int main() {
  scanf("%d %d %d", &N, &M, &K);
  for(int i = 0; i < N; ++i) {
    scanf("%s", grid[i]);
  }
  for(int i = 0; i < M; ++i) {
    int ans = get(i);
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}