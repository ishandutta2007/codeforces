#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  long long a, r, m;
  cin >> a >> r >> m;
  vector<int> h(n);
  for (auto&& e : h) cin >> e;
  sort(begin(h), end(h));
  auto sum = accumulate(begin(h), end(h), 0LL);
  vector<long long> cum(n + 1);
  for (int i = n; i--; ) {
    cum[i] = h[i] + cum[i + 1];
  }
  auto f = [&](long long x) {
    auto res = 0LL;
    if (sum < x * n) {
      res += a * (x * n - sum);
      int j = upper_bound(begin(h), end(h), x) - begin(h);
      res += min(m, a + r) * (cum[j] - (n - j) * x);
    } else {
      res += r * (sum - x * n);
      int j = lower_bound(begin(h), end(h), x) - begin(h);
      res += min(m, a + r) * (j * x - (cum[0] - cum[j]));
    }
    return res;
  };
  int ng = h[0] - 1, ok = h.back();
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    (f(mid) <= f(mid + 1) ? ok : ng) = mid;
  }
  cout << f(ok) << '\n';
}