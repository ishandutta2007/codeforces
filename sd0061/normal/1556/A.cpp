#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

void work() {
  int a, b;
  scanf("%d%d", &a, &b);
  if ((a + b) % 2 == 1) {
    puts("-1");
  } else if (a + b == 0) {
    puts("0");
  } else if (a == b) {
    puts("1");
  } else {
    puts("2");
  }
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}