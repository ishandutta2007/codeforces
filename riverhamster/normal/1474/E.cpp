#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;

const int N = 100005;
int a[N];
pair<int, int> res[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    iota(a + 1, a + 1 + n, 1);
    int cnt = 0;
    long long sum = 0;
    auto op = [&](int x, int y) {
      swap(a[x], a[y]);
      sum += (long long)(x - y) * (x - y);
      res[++cnt] = {x, y};
    };
    for (int i = 1; i < n; ++i)
      op(i, abs(i - 1) > abs(i - n) ? 1 : n);
    printf("%lld\n", sum);
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
    putchar('\n');
    printf("%d\n", cnt);
    for (int i = cnt; i >= 1; --i) printf("%d %d\n", res[i].first, res[i].second);
  }
  return 0;
}