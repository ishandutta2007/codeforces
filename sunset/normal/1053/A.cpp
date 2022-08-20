#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m, k;
  cin >> n >> m >> k;
  int x = __gcd(n, k);
  n /= x;
  k /= x;
  int y = __gcd(m, k);
  m /= y;
  k /= y;
  if (k > 2) {
    puts("NO");
    return 0;
  }
  puts("YES");
  if (k == 1) {
    if (x != 1) {
      n <<= 1;
    } else {
      m <<= 1;
    }
  }
  puts("0 0");
  printf("%d 0\n", n);
  printf("0 %d\n", m);
  return 0;
}