#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, m, n) for (int i = (m); i < (n); i++)

int egcd(int a, int b, int& x, int& y) {
  x = 1, y = 0;
  int u = 0, v = 1;
  while (b) {
    int q = a / b;
    swap(a -= q * b, b);
    swap(x -= q * u, u);
    swap(y -= q * v, v);
  }
  return a;
}
int main() {
  int a, b, c; scanf("%d%d%d", &a, &b, &c);
  int x, y, g = egcd(a, b, x, y);

  bool ok = c % g == 0;
  x *= c / g, y *= c / g;
  int dx = b / g, dy = a / g;
  ok &= (-x + (-x > 0 ? dx-1 : 0)) / dx <= (y - (y < 0 ? dy-1 : 0)) / dy;
  printf("%s\n", ok ? "Yes" : "No");
}