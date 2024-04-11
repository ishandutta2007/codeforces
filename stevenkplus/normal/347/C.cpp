#include <cstdio>

const int MAXN = 100100;

int N;
int ar[MAXN];

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int main() {
  scanf("%d", &N);
  int big = 0;
  int g = 0;
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
    if (ar[i] > big) big = ar[i];
    g = gcd(g, ar[i]);
  }

  int num = big / g;
  num -= N;
  if (num % 2 == 0) {
    printf("Bob\n");
  } else {
    printf("Alice\n");
  }
  return 0;
}