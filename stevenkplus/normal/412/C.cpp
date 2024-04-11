#include <cstdio>

const int MAXN = 100100;

char ans[MAXN];
char str[MAXN];

int N;

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%s", str);
    for(int j = 0; str[j]; ++j) {
      if (str[j] == '?') continue;
      if (!ans[j]) ans[j] = str[j];
      else if (ans[j] != str[j]) {
        ans[j] = '?';
      }
    }
  }
  for(int i = 0; str[i]; ++i) {
    if (!ans[i]) ans[i] = 'a';
  }
  printf("%s\n", ans);
  return 0;
}