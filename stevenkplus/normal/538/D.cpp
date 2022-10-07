#include <cstdio>

const int MAXN = 55;
int N;

bool miss[MAXN*2][MAXN*2];
bool hit[MAXN*2][MAXN*2];
char grid[MAXN][MAXN];

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%s", grid[i]);
  }

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      for(int a = 0; a < N; ++a) {
        for(int b = 0; b < N; ++b) {
          if (grid[i][j] == 'o' && grid[a][b] == '.') {
            miss[a - i+MAXN][b - j+MAXN] = true;
          }
        }
      }
    }
  }


  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      for(int a = -i; a + i < N; ++a) {
        for(int b = -j; b + j < N; ++b) {
          if (grid[i][j] == 'o') {
            if (!miss[a+MAXN][b+MAXN]) {
              hit[i+a][j+b] = true;
            }
          }
        }
      }
    }
  }

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if (grid[i][j] == 'x' && !hit[i][j]) {
        printf("NO\n");
        return 0;
      }
    }
  }

  printf("YES\n");
  for(int i = -N + 1; i < N; ++i) {
    for(int j = -N + 1; j < N; ++j) {
      if (i == 0 && j == 0) {
        printf("o");
      } else {
        if (miss[i+MAXN][j+MAXN]) {
          printf(".");
        } else {
          printf("x");
        }
      }
    }
    printf("\n");
  }
}