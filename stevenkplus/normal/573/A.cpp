#include <cstdio>

bool _main() {
  int N;
  scanf("%d", &N);
  int prv = 0;
  for(int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    while (x % 2 == 0) {
      x /= 2;
    }
    while (x % 3 == 0) {
      x /= 3;
    }
    if (prv == 0) {
      prv = x;
    }
    if (x != prv) {
      return false;
    }
  }

  return true;
}

int main() {
  if (_main()) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}