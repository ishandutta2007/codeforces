#include <cstdio>

const int MAXN = 1001000;

char prec[10][10] = {"1869", "6189", "1689", "6198", "1698", "8916", "1896"};
char str[MAXN];
char ans[MAXN];

int cnt[10];

int main() {
  scanf("%s", str);
  ++cnt[1];
  ++cnt[6];
  ++cnt[8];
  ++cnt[9];

  int pos = 0;
  int num = 0;
  int zeros = 0;
  for(int i = 0; str[i]; ++i) {
    int dig = str[i] - '0';
    if (dig == 0) {
      ++zeros;
    } else if (cnt[dig] == 1) {
      --cnt[dig];
    } else {
      num = num * 10 + dig;
      num %= 7;
      ans[pos] = dig + '0';
      ++pos;
    }
  }
  num = num * 10000 % 7;

  int need = (7 - num) % 7;

  printf("%s", ans);
  printf("%s", prec[need]);
  for(int i = 0; i < zeros; ++i) {
    printf("0");
  }
  printf("\n");
  return 0;
}