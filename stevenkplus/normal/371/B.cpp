#include <cstdio>

int A, B;
int go(int k) {
  int ret = 0;
  while(k % 2 == 0){
    k /= 2;
    ++ret;
  }
  while(k % 3 == 0) {
    k /= 3;
    ++ret;
  }
  while(k % 5 == 0) {
    k /= 5;
    ++ret;
  }
  if (k == 1) return ret;
  else return -1;
}

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int main() {
  scanf("%d %d", &A, &B);
  int c = gcd(A, B);
  A /= c;
  B /= c;
  int k = go(A);
  if (k == -1) {
    printf("-1\n");
    return 0;
  }
  int j = go(B);
  if (j == -1) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", k + j);
  return 0;
}