#include <cstdio>

const int MAXN = 30100;

int ar[MAXN];
int N, T;

int main() {
  scanf("%d %d", &N, &T);
  for(int i = 1; i < N; ++i) {
    scanf("%d", ar + i);
  }

  int cur = 1;
  while (cur < T) {
    cur += ar[cur];
  }

  if (cur == T) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;


}