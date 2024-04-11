#include <bits/stdc++.h>
using namespace std;

#define ep 1e-8
double pie = 4.0 * atan(1);

int n;
double R, r;

int main() {
//  freopen("a.in", "r", stdin);
  scanf("%d %lf %lf", &n, &R, &r);
  if (n == 1) {
    if (r < R + ep) puts("YES");
    else puts("NO");
    return 0;
  }
  if (n == 2) {
    if (r * 2 < R + ep) puts("YES");
    else puts("NO");
    return 0;
  }
  double a = pie / n;
  double r1 = R * sin(a) / (1.0 + sin(a));
  if (r < r1 + ep) puts("YES");
  else puts("NO");
  return 0;
}