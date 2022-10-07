#include <cstdio>

const int MAXN = 55;

int N;
char str[MAXN];

int main() {
  scanf("%d", &N);
  scanf("%s", str);

  int ans = 0;
  char prv = 0;
  for (int i = 0; i < N; ++i) {
    if (str[i] == prv) {
       ++ans;
    }
    prv = str[i];
  }

  printf("%d\n", ans);
  return 0;
}