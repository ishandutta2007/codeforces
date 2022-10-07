#include <cstdio>
const int MAXN = 111;

char grid[MAXN][MAXN];

bool good(int i, int j) {
  return grid[i][j] == '.';
}

int k;
int count(int i, int j, int di, int dj) {
  int val = 0;
  while (good(i, j)) {
    ++val;
    i += di;
    j += dj;
  }
  if (val > k) return k;
  return val;
}

int main() {
  int r;
  scanf("%d %d", &r, &k);
  int ansr = 1, ansc = 1, ansv = 0;
  for (int i = 1; i <= r; ++i) {
    scanf("%s", grid[i] + 1);
  }

  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= r; ++j) {
      int a = count(i, j, -1, 0);
      int b = count(i, j, 1, 0);
      int c = count(i, j, 0, -1);
      int d = count(i, j, 0, 1);

      int v = 0;
      if (a + b - k > 0) {
        v += a + b - k;
      }
      if (c + d - k > 0) {
        v += c + d - k;
      }
      if (v > ansv) {
        ansr = i;
        ansc = j;
        ansv = v;
      }
    }
  }

  printf("%d %d\n", ansr, ansc);
}