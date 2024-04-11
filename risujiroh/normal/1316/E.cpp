#include <bits/stdc++.h>
using namespace std;

auto chmax = [](auto&& l, auto r) { return l < r ? l = r, 1 : 0; };

constexpr long long inf = 0x3f3f3f3fLL << 32;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, p, k;
  cin >> n >> p >> k;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  vector<vector<int>> s(n, vector<int>(p));
  for (auto&& v : s) {
    for (auto&& e : v) {
      cin >> e;
    }
  }
  vector<int> idx(n);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) {
    return a[i] > a[j];
  });
  vector<long long> dp(1 << p, -inf);
  dp[0] = 0;
  for (int t = 0; t < n; ++t) {
    int i = idx[t];
    vector<long long> ndp(1 << p, -inf);
    for (int bt = 0; bt < 1 << p; ++bt) {
      int c = __builtin_popcount(bt);
      if (t - c < k) {
        chmax(ndp[bt], dp[bt] + a[i]);
      } else {
        chmax(ndp[bt], dp[bt]);
      }
      for (int j = 0; j < p; ++j) {
        if ((bt >> j & 1) == 0) {
          chmax(ndp[bt | 1 << j], dp[bt] + s[i][j]);
        }
      }
    }
    swap(dp, ndp);
  }
  cout << dp.back() << '\n';
}