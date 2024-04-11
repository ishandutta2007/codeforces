#include <bits/stdc++.h>

using namespace std;

#define N 200200

typedef long long LL;

int add[N], a[N], n;
LL sum;

int main() {
  n = 1;
  int q;
  for(scanf("%d", &q); q --; ) {
    int type, x, y, z;
    scanf("%d", &type);
    if(type == 1) {
      scanf("%d%d", &x, &y);
      sum += 1LL * x * y;
      add[x] += y;
    } else if(type == 2) {
      scanf("%d", &x);
      a[++ n] = x;
      sum += x;
      add[n] = 0;
    } else {
      sum -= a[n] + add[n];
      add[n - 1] += add[n];
      n --;
    }
    printf("%.6lf\n", 1. * sum / n);
  }
  return 0;
}