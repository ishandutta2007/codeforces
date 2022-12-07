#include <bits/stdc++.h>

using namespace std;

const long long bmax = (long long) 3.01e18;
const long long inf  = (long long) 9.01e18;

const int N = 1234567;

long long x[N], y[N], z[N];
long long the_x, the_y, the_z;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%I64d %I64d %I64d", x + i, y + i, z + i);
    }
    the_x = the_y = the_z = -1;
    long long low = 0, high = bmax;
    while (low < high) {
      long long mid = (low + high) >> 1;
      long long a = -inf, b = inf;
      long long c = -inf, d = inf;
      long long e = -inf, f = inf;
      long long g = -inf, h = inf;
      for (int i = 0; i < n; i++) {
        a = max(a, x[i] + y[i] + z[i] - mid);
        b = min(b, x[i] + y[i] + z[i] + mid);
        c = max(c, x[i] + y[i] - z[i] - mid);
        d = min(d, x[i] + y[i] - z[i] + mid);
        e = max(e, x[i] - y[i] + z[i] - mid);
        f = min(f, x[i] - y[i] + z[i] + mid);
        g = max(g, x[i] - y[i] - z[i] - mid);
        h = min(h, x[i] - y[i] - z[i] + mid);
      }
      bool ok = false;
      if (a > b || c > d || e > f || g > h) {
        // do nothing
      } else {
        long long from_x = max(a + g, c + e);
        long long to_x = min(d + f, b + h);
        if (from_x & 1) {
          from_x++;
        }
        if (to_x & 1) {
          to_x--;
        }
        from_x /= 2;
        to_x /= 2;
        if (from_x <= to_x) {
          for (long long x = from_x; x <= to_x; x++) {
            long long from_plus = max(a - x, -h + x);
            long long to_plus = min(b - x, -g + x);
            long long from_minus = max(c - x, -f + x);
            long long to_minus = min(d - x, -e + x);
            if (from_plus <= to_plus && from_minus <= to_minus) {
              if (from_plus < to_plus || from_minus < to_minus || ((from_plus & 1) == (from_minus & 1))) {
                if ((from_plus & 1) != (from_minus & 1)) {
                  if (from_plus < to_plus) {
                    from_plus++;
                  } else {
                    from_minus++;
                  }
                }
                long long ypz = from_plus;
                long long ymz = from_minus;
                the_x = x;
                the_y = (ypz + ymz) / 2;
                the_z = (ypz - ymz) / 2;
                ok = true;
                break;
              }
            }
            if (x == from_x + 2 && x < to_x - 3) {
              x = to_x - 3;
            }
          }
        }
      }
      if (ok) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    printf("%I64d %I64d %I64d\n", the_x, the_y, the_z);
  }
  return 0;
}