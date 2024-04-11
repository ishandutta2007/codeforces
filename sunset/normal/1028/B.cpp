#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  for (int i = 0; i < 500; ++i) {
    putchar('5');
  }
  putchar(10);
  for (int i = 0; i < 500; ++i) {
    putchar(i == 499 ? '5' : '4');
  }
  putchar(10);
  return 0;
}