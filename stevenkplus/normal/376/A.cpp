#include <cstdio>

const int MAXN = 1001000;
char str[MAXN];

int main() {
  scanf("%s", str);
  int x = 0;
  long long tor = 0;
  int mass = 0;
  int com = 0;
  for(int i = 0; str[i]; ++i) {
    if (str[i] == '^') {
      com = i;
    } else if (str[i] == '=') continue;
    else {
      int m = str[i] - '0';
      mass += m;
      tor += m * i;
    }
  }

  if ((long long)(com) * mass == tor) {
    printf("balance\n");
  } else if ((long long)(com) * mass > tor) {
    printf("left\n");
  } else printf("right\n");
  return 0;
}