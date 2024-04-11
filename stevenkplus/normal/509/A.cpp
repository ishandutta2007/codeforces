#include <cstdio>

int ans[] = {0,
1,
2,
6,
20,
70,
252,
924,
3432,
12870,
48620};

int N;
int main() {
  scanf("%d", &N);
  printf("%d\n", ans[N]);

}