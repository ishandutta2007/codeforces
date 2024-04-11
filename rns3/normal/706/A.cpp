#include <bits/stdc++.h>
using namespace std;

int main() {
  double ans = 0;
  int a, b;
  scanf("%d %d", &a, &b);
  int n;
  scanf("%d", &n);
  ans = 1e18;
  for(int i = 0; i < n; i ++) {
    int x, y, v;
    scanf("%d %d %d", &x, &y, &v);
    ans = min(ans, 1. * sqrt(pow(x - a, 2) + pow(y - b, 2)) / v);
  }
  printf("%.20lf\n", ans);
}