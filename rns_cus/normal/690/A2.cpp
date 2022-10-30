#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  if (n & 1) {
    printf("%d\n", (n - 1) / 2);
  }
  else {
    int x = 1;
    while (2 * x <= n) x *= 2;
    printf("%d\n", (n - x) / 2);
  }
}