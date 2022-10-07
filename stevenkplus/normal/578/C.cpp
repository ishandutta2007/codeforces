#include <cstdio>
#include <cmath>

typedef long double ld;

const int MAXN = 200100;
const ld eps = 1E-10;

int ar[MAXN];

int N;
ld pos(ld x) {
  ld cur = 0;
  ld ans = 0;
  for(int i = 0; i < N; ++i) {
    cur += ar[i] - x;
    if (cur > ans) ans = cur;
    if (cur < 0) cur = 0;
  }
  return ans;
}

ld neg(ld x) {
  ld cur = 0;
  ld ans = 0;
  for(int i = 0; i < N; ++i) {
    cur += ar[i] - x;
    if (cur < ans) ans = cur;
    if (cur > 0) cur = 0;
  }
  return -ans;
}


int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  ld lo = -10000;
  ld add = 10000;
  for(int i = 0; i < 100; ++i) {
    ld mid = lo + add;
    add /= 2;
    if (pos(mid) > neg(mid)) {
      lo = mid;
    }
  }

  double ans = pos(lo);
  printf("%.10lf\n", ans);
}