#include <cstdio>

const int MAXN = 110;
char grid[MAXN][MAXN];
int N;


int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%s", grid[i]);
  }

  bool good = true;
  for(int i = 0; i < N; ++i) {
    good = false;
    for(int j = 0; j < N; ++j) {
      if (grid[i][j] == '.') {
        good = true;
        break;
      }
    }
    if (!good) break;
  }
  if (good) {
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        if (grid[i][j] == '.') {
          printf("%d %d\n", i + 1, j + 1);
          break;
        }
      }
    }
  } else {
    good = true;
    for(int i = 0; i < N; ++i) {
      good = false;
      for(int j = 0; j < N; ++j) {
        if (grid[j][i] == '.') {
          good = true;
          break;
        }
      }
      if (!good) break;
    }
    if (good) {
      for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
          if (grid[j][i] == '.') {
            printf("%d %d\n", j + 1, i + 1);
            break;
          }
        }
      }
    } else {
      printf("-1\n");
    }
  }
  return 0;
}