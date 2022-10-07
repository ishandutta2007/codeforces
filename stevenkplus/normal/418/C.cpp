#include <cstdio>

const int MAXN = 1000000;
bool issq[MAXN];
int near[MAXN];

void prec() {
  for(int i = 1; i * i < MAXN; ++i) {
    issq[i * i] = true;
  }
}

int main() {
  prec();

  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i < 10000; ++i) {
    if (i % 4 == 2) continue;
    for(int j = 1; i + j * j < MAXN; ++j) {
      if (issq[i + j * j]) {
        near[i] = j;
//        printf("near[%d] = %d\n", i, near[i]);
        break;
      }
    }
    if (!near[i]) {
//      printf("%d is bad!!!\n\n\n", i);
    }
  }

  int a = 1, b = 1;
  while (!near[n - 2 + a * a]) ++a;
  while (!near[m - 2 + b * b]) ++b;
  int x = near[n - 2 + a * a];
  int y = near[m - 2 + b * b];
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      int val = 1;
      if (i == 0) {
        val *= a;
      }
      if (j == 0) {
        val *= b;
      }
      if (i == n - 1) {
        val *= x;
      }
      if (j == m - 1) {
        val *= y;
      }
      printf("%d ", val);
    }
    printf("\n");
  }
}