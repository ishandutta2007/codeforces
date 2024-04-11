#include <cstdio>
#include <algorithm>

struct q {
  int a;
  int b;
};

int const N = 1234567;

q f[N];

int main() {
  int n, p;
  scanf("%d%d", &n, &p);
  long long a = 0;
  long long b = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    f[i] = {x, y};
    a += x;
    b += y;
  }
  if (p >= a) {
    puts("-1");
    return 0;
  }
  double l = 0;
  double r = 1. * b / (a - p) + 1;
  for (int it = 0; it < 100; it++) {
    double mid = (l + r) * .5;
    std::sort(f, f + n, [&](q const &p, q const &q) {
      return p.b - p.a * mid < q.b - q.a * mid;
    });
    long long ca = 0;
    long long cb = 0;
    bool bad = false;
    for (int i = 0; i < n; i++) {
      ca += f[i].a;
      cb += f[i].b;
      if (cb - ca * mid + p * mid < 0) {
        bad = true;
        break;
      }
    }
    if (bad) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.10f\n", (l + r) * .5);
}