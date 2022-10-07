#include <cstdio>

const int MAXN = 222;
char str[MAXN];
int N;

int main() {
  scanf("%d", &N);
  scanf("%s", str);
  int ans = 0;
  for(int i = 0; i < N; ++i) {
    for(int j = i + 1; j <= N; ++j) {
      int a = 0, b = 0;
      for(int k = i; k < j; ++k) {
        if (str[k] == 'U') ++a;
        else if (str[k] == 'D') --a;
        else if (str[k] == 'R') ++b;
        else if (str[k] == 'L') --b;
      }
      if (a == 0 && b == 0) {
        ++ans;
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}