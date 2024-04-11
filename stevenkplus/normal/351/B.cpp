#include <cstdio>

const int MAXN = 100100;

int N;
int ar[MAXN];

int main() {
  scanf("%d", &N);
  int inv = 0;
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
    for(int j = 0; j < i; ++j) {
      if (ar[i] < ar[j]) {
        ++inv;
      }
    }
  }

  int a = inv;
  int b = inv;
  if (a % 2 == 1) --b;
  printf("%d\n", a + b);

  return 0;
}