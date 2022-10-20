#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1000005, M = 1000000007;
const int INF = 1000000000;

int p[N], pw3[N / 2];
bool vis[N];
int cnt[10];
int opt;

int check() {
  int c1 = cnt[1] + cnt[4], c2 = cnt[2] + cnt[5];
  return cnt[4] + cnt[5] + cnt[6] + (c1 < c2 ? c2 : c2 + (c1 - c2) / 3 * 2);
}
template<class ...Args>
int check(int x, Args... args) {
  int res = INF;
  for (int i = x; i <= 6; ++i) {
    if (cnt[i] == 0) continue;
    --cnt[i]; ++cnt[i - x];
    res = min(res, check(args...) + (i > x));
    ++cnt[i]; --cnt[i - x];
  }
  return res;
}

int main() {
  pw3[0] = 1;
  for (int i = 1; i <= 500000; ++i) pw3[i] = (pw3[i - 1] * 3LL) % M;
  int T;
  for (scanf("%d", &T); T; --T) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", p + i);
    int c3 = n % 3 == 1 ? n / 3 - 1 : n / 3;
    printf("%lld ", (1LL * pw3[c3] * (n % 3 == 0 ? 1 : n - 3 * c3) % M));

    fill(vis + 1, vis + 1 + n, false);
    fill(cnt, cnt + 7, 0);
    int res = 0, opt = INF;
    for (int i = 1; i <= n; ++i) {
      if (vis[i]) continue;
      int sz = 1, x = i;
      vis[i] = true;
      while (!vis[p[x]]) x = p[x], vis[x] = true, ++sz;
      while (sz >= 7) sz -= 3, ++res;
      ++cnt[sz];
    }

    if (n % 3 == 0)
      opt = check();
    else if (n % 3 == 1) {
      opt = min(opt, check(1, 1, 1, 1) + 2);
      opt = min(opt, check(1, 1, 2) + 1);
      opt = min(opt, check(2, 2));
      opt = min(opt, check(1, 3) + 1);
      opt = min(opt, check(4));
    }
    else {
      opt = min(opt, check(1, 1) + 1);
      opt = min(opt, check(2));
    }

    printf("%d\n", res + opt);
  }
  return 0;
}