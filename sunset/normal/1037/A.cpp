#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  int answer = 0, value = 1;
  while (n) {
    ++answer;
    n -= min(value, n);
    value <<= 1;
  }
  printf("%d\n", answer);
  return 0;
}