#include <bits/stdc++.h>
using namespace std;

const long long inf = (long long) 1e18;
const int N = 1234567;

long long a[N], b[N];

int main() {
  int n, k;
  //freopen("a.in", "r", stdin);
  //freopen("a.out", "w", stdout);
 while( scanf("%d %d", &n, &k)>0){
  n++;
  for (int i = 0; i < n; i++) {
    int foo;
    scanf("%d", &foo);
    a[i] = foo;
  }
  long long z = 0;
  int up = 0;
  for (int i = 0; i < n; i++) {
    z += a[i];
    b[i] = z;
    if (z % 2 != 0) {
      break;
    }
    up++;
    z /= 2;
  }
  long long value = 0;
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (i <= up) {
      long long tmp = value * 2 + b[i];
      long long z = a[i] - tmp;
      if (-k <= z && z <= k && (i != n - 1 || z != 0)) {
        ans++;
      }
    }
    value = value * 2 + a[i];
    if (value < -inf || value > inf) {
      break;
    }
  }
  printf("%d\n", ans);
}
  return 0;
}