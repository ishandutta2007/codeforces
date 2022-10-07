#include <cstdio>

const int MAXN = 1001000;
int fac[MAXN];
void prec() {
  fac[0]=fac[1] = 1;
  for(int i = 2; i < MAXN; ++i) {
    if (!fac[i]) {
      for(int j = i + i; j < MAXN; j += i) {
        fac[j] = i;
      }
      fac[i] = 1;
    }
  }
}

int main() {
  prec();
  int x2;
  scanf("%d", &x2);

  int maxp = fac[x2];
  int ans = x2;
  // printf("maxp=%d\n", maxp);
  for(int x1 = x2 - maxp + 1; x1 <= x2; ++x1) {
    int p = fac[x1];
    int x0 = x1 - p + 1;
    // printf("%d=>%d\n", x1, p);
    if (x0 < ans)
      ans = x0;
  }
  printf("%d\n", ans);
}