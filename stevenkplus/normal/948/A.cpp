#include <cstdio>

const int MAXN = 555;
char grid[MAXN][MAXN];

int r,c;
bool get(int i, int j) {
  if (i < 0 || j < 0) return false;
  return grid[i][j] == 'S';
}

bool _main() {
  scanf("%d %d", &r, &c);
  for(int i = 0; i < r; ++i) {
    scanf("%s", grid[i]);
  }
  for(int i = 0; i < r; ++i) {
    for(int j = 0; j < c; ++j) {
      if (grid[i][j] == '.') {
        grid[i][j] = 'D';
      }
      if (grid[i][j] == 'W') {
        if (get(i + 1, j)) return false;
        if (get(i, j + 1)) return false;
        if (get(i, j - 1)) return false;
        if (get(i - 1, j)) return false;
      }
    }
  }
  return true;
}

int main() {
  if (_main()) {
    printf("Yes\n");
    for(int i = 0; i < r; ++i) {
      printf("%s\n", grid[i]);
    }
  } else {
    printf("No\n");
  }

}