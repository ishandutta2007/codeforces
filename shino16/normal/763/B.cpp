#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, m, n) for (int i = (m); i < (n); i++)


int main() {
  int n, x1, y1, x2, y2;
  scanf("%d", &n);
  printf("YES\n");
  while (n--) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int c = (x1 & 1) * 2 + (y1 & 1);
    printf("%d\n", c + 1);
  }
}