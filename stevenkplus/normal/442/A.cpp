#include <cstdio>
#include <cstring>

int N;

bool vis[5][5];

int pop(int x) {
  int ret = 0;
  while (x) {
    ++ret;
    x &= x - 1;
  }
  return ret;
}


int mp(char c) {
  if (c == 'R') return 0;
  else if (c == 'G') return 1;
  else if (c == 'B') return 2;
  else if (c == 'Y') return 3;
  else return 4;
}

int match[5][5];

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    char c;
    int d;
    scanf(" %c%d", &c, &d);

    vis[mp(c)][d - 1] = true;
  }

  int best = 10;
  for(int i = 0; i < (1 << 10); ++i) {
    memset(match, 0, sizeof(match));
    for(int j = 0; j < 5; ++j) {
      if ((i >> j) & 1) {
        for(int k = 0; k < 5; ++k) {
          if (vis[j][k]) {
            match[j][k]++;
          }
        }
      }
    }
    for(int j = 0; j < 5; ++j) {
      if ((i >> (j + 5)) & 1) {
        for(int k = 0; k < 5; ++k) {
          if (vis[k][j]) {
            match[k][j] += 2;
          }
        }
      }
    }

    bool good = true;
    int zeros = 0;
    for(int i = 0; i < 5; ++i) {
      for(int j = 0; j < 5; ++j) {
        if (!vis[i][j]) continue;
        if (match[i][j] == 3) continue;
        if (match[i][j] == 0) ++zeros;
        for(int k = 0; k < 5; ++k) {
          if (match[i][j] == 1) {
            if (j != k && match[i][k] == 1) {
              good = false;
            }
          } else {
            if (i != k && match[k][j] == 2) {
              good = false;
            }
          }
        }
      }
    }

    if (zeros > 1) good = false;
    if (good) {
      int cnt = pop(i);
      if (cnt < best) best = cnt;
    }
  }

  printf("%d\n", best);
  return 0;
}