#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;
char s[1001000];

bool can(int x, int y) {
  s[x + y] = 0;
  if ((0LL + b + c) != (1LL * x * y)) return 0;
  int yy = 0;
  for(int i = 0; i < x + y; i++) {
    if (b >= y - yy) {
      s[i] = '0';
      b -= y - yy;
    } else {
      s[i] = '1';
      yy ++;
    }
  }
  return 1;
}

bool run() {
  int i;
  for(i = 1; i * (i - 1) < a * 2; i++);
  if (i * (i - 1) != 2 * a) return 0;
  int j = i;
  for(i = 1; i * (i - 1) < d * 2; i++);
  if (i * (i - 1) != 2 * d) return 0;
  swap(i, j);
  if (can(i, j)) return 1;
  if (i == 1 && can(0, j)) return 1;
  if (j == 1 && can(i, 0)) return 1;
  return 0;
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if (!run()) puts("Impossible");
  else puts(s);
  return 0;
}