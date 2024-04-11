#include <cstdio>

int N;
char ar[10];

int main() {
  scanf("%d", &N);
  char prv = 0;
  int cnt = 0;
  for(int i = 0; i < N; ++i) {
    scanf("%s", ar);
    if (ar[0] != prv) ++cnt;
    prv = ar[0];
  }
  printf("%d\n", cnt);
  return 0;
}