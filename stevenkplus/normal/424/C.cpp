#include <cstdio>

const int MAXN = 1001000;

int N;

int prf[MAXN];

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    prf[i + 1] = prf[i] ^ (i + 1);
  }

  int ans = 0;
  for(int m = 1; m <= N; ++m) {
//    1 ... 2m ignore.
    int k = N % (2 * m);
    if (k < m) {
      ans ^= prf[k];
    } else {
      ans ^= prf[m - 1] ^ prf[k - m];
    }

  }

  for(int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    ans ^= x;
  }
  printf("%d\n", ans);
}