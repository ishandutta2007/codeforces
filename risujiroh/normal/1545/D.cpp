#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int m, k;
  cin >> m >> k;
  vector a(k, vector<int>(m));
  for (auto&& v : a)
    for (auto&& e : v) cin >> e;
  vector<int64_t> sum(k);
  for (int t = 0; t < k; ++t) sum[t] = accumulate(begin(a[t]), end(a[t]), int64_t(0));
  int y = -1;
  int64_t delta;
  auto go = [&](int i, int j) {
    if ((sum[j] - sum[i]) % (j - i)) return;
    auto la = (sum[j] - sum[i]) / (j - i);
    auto lb = sum[i] - la * i;
    vector<int> v;
    for (int t = 0; t < k; ++t)
      if (sum[t] != la * t + lb) v.push_back(t);
    if (size(v) == 1) {
      y = v[0];
      delta = sum[y] - (la * y + lb);
    }
  };
  go(0, 1);
  go(0, 2);
  go(1, 2);
  vector<int64_t> sum2(k);
  for (int t = 0; t < k; ++t)
    for (int64_t e : a[t]) sum2[t] += e * e;
  int64_t delta2;
  if (y == 1)
    delta2 = sum2[y] - (sum2[y - 1] + 3 * sum2[y + 1] - sum2[y + 2]) / 3;
  else
    delta2 = sum2[y] - (sum2[y - 2] - 3 * sum2[y - 1] - sum2[y + 1]) / -3;
  auto ans = (delta2 - delta * delta) / (2 * delta);
  cout << y << ' ' << ans << endl;
}