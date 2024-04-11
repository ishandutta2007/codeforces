#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  vector<int> c;
  int cur = 0;
  for (int i = 0; i <= n; ++i) {
    if (i == n or a[i]) {
      c.push_back(cur);
      cur = 0;
    } else {
      ++cur;
    }
  }
  int m = size(c);
  int zeros = accumulate(begin(c), end(c), 0);
  vector<int> d(m);
  int lim{};
  {
    int s{}, t{};
    for (int i = 0; i < m; ++i) {
      d[i] = zeros / m + (i < zeros % m);
      lim += abs(t - s);
      s += c[i], t += d[i];
    }
  }

  vector dp(zeros + 1, vector(lim + 1, 0x3f3f3f3f));
  dp[0][0] = 0;
  int pref{};
  for (int i = 0; i < m; ++i) {
    vector ndp(zeros + 1, vector(lim + 1, 0x3f3f3f3f));
    for (int sum = 0; sum <= zeros; ++sum)
      for (int cost = 0; cost <= lim; ++cost)
        for (int x = 0; sum + x <= zeros; ++x)
          if (cost + abs(sum - pref) <= lim)
            ndp[sum + x][cost + abs(sum - pref)] = min(
                ndp[sum + x][cost + abs(sum - pref)], dp[sum][cost] + x * x);
    swap(dp, ndp);
    pref += c[i];
  }

  for (int k = 0; k <= n * (n - 1) / 2; ++k) {
    if (k) cout << ' ';
    int ans = (zeros * zeros - dp.back()[min(k, lim)]) / 2;
    cout << ans;
  }
  cout << '\n';
}