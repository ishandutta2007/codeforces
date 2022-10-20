#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>

long long ni() {
  int c = getchar();
  while (c < '0' || c > '9') c = getchar();
  long long ret = 0;
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return ret;
}

long long gcd(long long a, long long b) {
  while (b > 0) {
    long long t = a % b;
    a = b;
    b = t;
  }
  return a;
}

long long a[1234567];
long long d[123456];
int cc[123456];

int main() {
  srand(time(NULL));
  int n = ni();
  for (int i = 0; i < n; i++) {
    a[i] = ni();
  }
  long long ans = 1;
  for (int it = 0; it < 10; it++) {
    long long x = a[((rand() << 15) ^ rand()) % n];
    int cnd = 0;
    for (long long i = 1; i * i <= x; i++) {
      if (x % i != 0) {
        continue;
      }
      d[cnd++] = i;
      if (i * i != x) d[cnd++] = x / i;
    }
    for (int i = 0; i < cnd; i++) cc[i] = 0;
    std::sort(d, d + cnd);
    for (int i = 0; i < n; i++) {
      long long g = gcd(x, a[i]);
      cc[std::lower_bound(d, d + cnd, g) - d]++;
    }
    for (int i = 0; i < cnd; i++) {
      for (int j = i + 1; j < cnd; j++) {
        if (d[j] % d[i] == 0) {
          cc[i] += cc[j];
        }
      }
      if (2 * cc[i] >= n && d[i] > ans) {
        ans = d[i];
      }
    }
  }
  printf("%I64d\n", ans);
}