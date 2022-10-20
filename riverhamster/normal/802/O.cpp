#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 500005;
int a[N], b[N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) scanf("%d", b + i);
  int l = 0, r = 2000000000, K;
  long long res = 1e18;
  while (l <= r) {
    K = ((unsigned)l + (unsigned)r) >> 1;
    priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> q;
    long long now = 0;
    for (int i = 1; i <= n; ++i) {
      q.emplace(a[i], false);
      int aug = b[i] - K + q.top().first;
      if (aug < 0) {
        q.pop();
        now += aug;
        q.emplace(K - b[i], true);
      }
    }
    int cnt = 0;
    while (!q.empty())
      cnt += q.top().second, q.pop();
    if (cnt >= k) {
      res = now + 1LL * k * K;
      r = K - 1;
    }
    else l = K + 1;
  }
  printf("%lld\n", res);
  return 0;
}