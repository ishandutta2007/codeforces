#include <cstdio>

const int MAXN = 200100;
const int BLK = 450;
int N;
int ar[MAXN];

int ans[MAXN];
int diffs[MAXN];

void inc(int a, int b) {
  diffs[a] += 1;
  diffs[b + 1] -= 1;
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }


  for(int i = 1; i < N; ++i) {
    int k = 1;
    while (k < N) {
      int p = (i - 1) / k;
      int kend = N - 1;
      if (p > 0) {
        kend = (i - 1) / p;
      }

      if (ar[i] < ar[p]) {
        inc(k, kend);
      }
      k = kend + 1;
    }
  }

  int sm = 0;
  for(int i = 1; i < N; ++i) {
    sm += diffs[i];
    printf("%d ", sm);
  }
  printf("\n");
}