#include <cstdio>
#include <algorithm>
using namespace std;

int solve(int a, int n, int p) {
  if (1LL * a * n <= p) return max(a, p - n * a);
  int fi = 0;
  if (a * 2 <= p) fi = p - p % a - a;
  return solve(min(p % a, a - p % a), (1LL * a * n - fi) / p, a);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, n, p, h;
    scanf("%d%d%d%d", &a, &n, &p, &h);
    a %= p;
    int res;
    if (1LL * a * n <= p) res = a;
    else res = solve(a, n, p);
    printf("%s\n", res <= h ? "YES" : "NO");
  }
  return 0;
}