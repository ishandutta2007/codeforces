#include <cstdio>

const int MAXN = 1100;
const int MAXC = 30;

int conv(char c) {
  return c - 'a';
}

int cnts[MAXC];
char str[MAXN];

int N;

int main() {
  scanf("%s", str);
  scanf("%d", &N);
  int len;
  for(int i = 0; str[i]; ++i) {
    ++cnts[conv(str[i])];
    len = i + 1;
  }

  int lo = 1;
  int hi = len + 1;

  while (lo < hi) {
    int mid = (lo + hi) / 2;
    int lft = N;
    for(int i = 0; i < MAXC; ++i) {
      int need = cnts[i];
      need = (need + mid - 1) / mid;
      lft -= need;
    }
    if (lft >= 0) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  if (lo > len) {
    printf("-1\n");
    return 0;
  } 

  printf("%d\n", lo);
  int lft = N;
  for(int i = 0; i < MAXC; ++i) {
    int need = cnts[i];
    need = (need + lo - 1) / lo;
    lft -= need;
    for(int j = 0; j < need; ++j) {
      printf("%c", char('a' + i));
    }
  }
  for(int i = 0; i < lft; ++i) {
    printf("a");
  }
  printf("\n");
  return 0;
}