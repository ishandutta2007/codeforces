#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

#define fmin FMIN
#define fmax FMAX

long double fmax[N], fmin[N], a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    double foo;
    scanf("%lf", &foo);
    fmax[i] = foo;
  }
  for (int i = 0; i < n; i++) {
    double foo;
    scanf("%lf", &foo);
    fmin[i] = foo;
  }
  long double sa = 0, sb = 0;
  for (int i = 0; i < n; i++) {
    long double s = fmax[i] + fmin[i];
    long double A = -1;
    long double B = sb - sa + s;
    long double C = s * sa - fmax[i];
    long double D = B * B - 4 * A * C;
    if (D < 0) {
      D = 0;
    } else {
      D = sqrtl(D);
    }
    long double z1 = (-B - D) / (2 * A);
    long double z2 = (-B + D) / (2 * A);
    long double d1 = fabsl(z1 - s / 2);
    long double d2 = fabsl(z2 - s / 2);
    if (d1 < d2) {
      a[i] = z1;
    } else {
      a[i] = z2;
    }
    b[i] = s - a[i];
    if (a[i] < 0) a[i] = 0;
    if (b[i] < 0) b[i] = 0;
    if (a[i] > 1 - sa) a[i] = 1 - sa;
    if (b[i] > 1 - sb) b[i] = 1 - sb;
    sa += a[i];
    sb += b[i];
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      putchar(' ');
    }
    double x = a[i];
    if (x < 0) x = 0;
    printf("%.15f", x);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      putchar(' ');
    }
    double x = b[i];
    if (x < 0) x = 0;
    printf("%.15f", x);
  }
  printf("\n");
  return 0;
}