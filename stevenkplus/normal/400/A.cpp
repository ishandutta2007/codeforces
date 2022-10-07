#include <cstdio>

const int MAXN = 10010;

int N;
char str[MAXN];

bool works(int a) {
  if (12 % a) return false;
  int b = 12 / a;
  for(int i = 0; i < b; ++i) {
    bool c = true;
    for(int j = 0; j < a; ++j) {
      if ('X' != str[j * b + i]) c = false;
    }
    if (c) return true;
  }
  return false;
}


void go() {
  scanf("%s", str);
  int ans = 0;
  for(int i = 1; i <= 12; ++i) {
    if (works(i)) ++ans;
  }
  printf("%d", ans);
  for(int i = 1; i <= 12; ++i) {
    if (works(i)) {
      int j = 12 / i;
      printf(" %dx%d", i, j);
    }
  }
  printf("\n");
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    go();
  }
  return 0;
}