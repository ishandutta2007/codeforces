#include <cstdio>

int N, p;

long long exp(int a, int b) {
  if (b == 0) return 1;
  long long c = exp(a, b / 2);
  c = (c * c) % N;
  if (b & 1) c = c * a % N;
  return c;
}

long long inv(int x) {
  return exp(x, p - 2);
}

int main() {
  scanf("%d", &N);
  if (N == 1) {
    printf("YES\n");
    printf("1\n");
    return 0;
  }
  if (N == 4) {
    printf("YES\n");
    printf("1\n3\n2\n4");
    return 0;
  }

  p = N;
  for(int i = 2; i * i <= N; ++i) {
    if (N % i == 0) {
      p = i;
      break;
    }
  }

  if (p != N) {
    printf("NO\n");
    return 0;
  }

  printf("YES\n");

  long long cur = 1;
  for(int i = 1; i < N; ++i) {
    int trans = (inv(cur) * i) % N;
    printf("%d\n", trans);
    cur = (cur * trans) % N;
  }

  printf("%d\n", N);
  return 0;
}