#include <cstdio>

char str[3];

int prec[] = {
  2, // 0, 8
  7, // 0, 1, 3, 4, 7, 8, 9 *
  2, // 2, 8    *
  3, // 3, 8, 9
  3, // 4, 8, 9 *
  4, // 5, 6, 8, 9*
  2, // 6, 8    *
  5, // 0, 3, 7, 8, 9
  1, // 8
  2 // 8, 9
};

int go(char c) {
  return prec[c - '0'];
}


int main() {
  scanf("%s", str);

  int ans = go(str[0]) * go(str[1]);
  printf("%d\n", ans);
  return 0;
}