#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d %*d", &n);
  int last = 0, current = 0, answer = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (x == last) {
      current = 1;
    } else {
      ++current;
    }
    answer = max(answer, current);
    last = x;
  }
  printf("%d\n", answer);
  return 0;
}