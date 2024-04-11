#include <cstdio>

const int MAXN = 100100;

int N;

int A[MAXN], B[MAXN];

int main() {
  scanf("%d", &N);

  for(int i = 0; i < N; ++i) {
    scanf("%d %d", A + i, B + i);
  }

  int a = 0, b = 0;
  for(int i = 0; i < N; ++i) {
    if (a < N && A[a] < B[b]) ++a;
    else ++b;
  }

  for(int i = 0; i < N; ++i) {
    if (i < a || i < N / 2) printf("1");
    else printf("0");
  }
  printf("\n");

  for(int i = 0; i < N; ++i) {
    if (i < b || i < N / 2) printf("1");
    else printf("0");
  }
  printf("\n");

  return 0;
}