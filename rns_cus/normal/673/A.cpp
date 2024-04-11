#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int lst = 0, x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x > lst + 15) return printf("%d\n", lst + 15), 0;
    lst = x;
  }
  lst = min(lst + 15, 90);
  printf("%d\n", lst);
}