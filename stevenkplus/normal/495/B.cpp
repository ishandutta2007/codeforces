#include <cstdio>

int a, b;
int ans = 0;

void check(int x) {
  if (x > b) {
    ++ans;
  }
}

int main() {
  scanf("%d %d", &a, &b);
  a -= b;
  if (a == 0) {
    printf("infinity\n");
  } else {
    for(int i = 1; i * i <= a; ++i) {
      if (a % i == 0) {
        check(i);
        if (i != a / i) {
          check(a / i);
        }
      }
    }
    printf("%d\n", ans);
  }
}