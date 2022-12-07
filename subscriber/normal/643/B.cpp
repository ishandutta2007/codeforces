#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  int a, b, c, d;
  scanf("%d %d", &n, &k);
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if (n == 4 || k <= n) {
    printf("%d\n", -1);
    return 0;
  }
  
  vector <int> z;
  for (int i = 1; i <= n; i++) {
    if (i != a && i != b && i != c && i != d) {
      z.push_back(i);
    }
  }

  int x = z.back();
  z.pop_back();

  printf("%d", a);
  for (int i = 0; i < (int) z.size(); i++) {
    printf(" %d", z[i]);
  }
  printf(" %d %d %d %d\n", c, x, d, b);

  printf("%d", c);
  for (int i = (int) z.size() - 1; i >= 0; i--) {
    printf(" %d", z[i]);
  }
  printf(" %d %d %d %d\n", a, x, b, d);

  return 0;
}