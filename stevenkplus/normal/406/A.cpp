#include <cstdio>

const int MAXN = 1010;

int ar[MAXN];

int N, Q;

int main() {
  scanf("%d", &N);

  int cur = 0;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      int x;
      scanf("%d", &x);
      if (i == j) {
        ar[j] = x;
        if (ar[j] == 1) ++cur;
      }
    }
  }

  scanf("%d", &Q);

  for(int q = 0; q < Q; ++q) {
    int qtype;
    scanf("%d", &qtype);
    if (qtype == 1 || qtype == 2) {
      int x;
      scanf("%d", &x);
      if (ar[x] == 1) --cur;
      else ++cur;
      ar[x] = 1 - ar[x];
    } else {
      printf("%d", cur % 2);
    }
  }
  printf("\n");
  return 0;
}