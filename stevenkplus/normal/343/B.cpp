#include <cstdio>

const int MAXN = 100100;
char str[MAXN];

int main() {
  scanf("%s", str);
  char prv = -1;
  int len = 0;
  for(int i = 0; str[i]; ++i) {
    int cur = 0;
    if (str[i] == '+') cur = 1;
    if (cur == prv) {
      prv = 1 - cur;
      --len;
    } else {
      prv = cur;
      ++len;
    }
  }

  if (len == 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}