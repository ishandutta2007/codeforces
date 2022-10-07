#include <cstdio>

const int MAXN = 1010;

int sieve[MAXN];
int ans[MAXN];

int N;

int main() {
  scanf("%d", &N);
  int cnt = 0;
  for(int i = 2; i <= N; ++i) {
    if (!sieve[i]) {
      int cur = i;
      while (cur <= N) {
        ans[cnt] = cur;
        cur *= i;
        ++cnt;
      }

      for(int j = i * i; j <= N; j += i) {
        sieve[j] = 1;
      }
    }
  }

  printf("%d\n", cnt);
  for(int i = 0; i < cnt; ++i) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}