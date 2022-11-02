#include <cstdio>
#include <algorithm>

#define N 5555

int x[N], y[N];

int dist2(int x1, int y1, int x2, int y2) {
  x1 -= x2;
  y1 -= y2;
  return x1 * x1 + y1 * y1;
}

double height(int i, int j, int k) {
  double a = y[k] - y[i];
  double b = x[i] - x[k];
  double c = -x[i] * a - y[i] * b;
  double dist = (a * x[j] + b * y[j] + c) / sqrt(a * a + b * b);
  if (dist < 0) dist = -dist;
  return dist;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", x + i, y + i);
  double ans = 1e100;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    int k = (i + 2) % n;
    ans = std::min(ans, height(i, j, k));
    ans = std::min(ans, height(j, k, i));
    ans = std::min(ans, height(k, i, j));
  }
  printf("%.10f\n", ans * .5);
}