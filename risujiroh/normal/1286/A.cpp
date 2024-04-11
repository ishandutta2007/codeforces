#include <bits/stdc++.h>
using namespace std;

auto chmin = [](auto&& l, auto r) { return r < exchange(l, r < l ? r : l); };

constexpr int inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
    --e;
  }
  vector<vector<int>> dp(2, vector<int>(n + 1, inf));
  dp[0][0] = dp[1][0] = 0;
  for (int i = 0; i < n; ++i) {
    vector<vector<int>> ndp(2, vector<int>(n + 1, inf));
    for (int p : {0, 1}) {
      for (int x = 0; x <= i; ++x) {
        for (int np : {0, 1}) {
          if (a[i] == -1 or (a[i] & 1) == np) {
            int nx = x + (~np & 1);
            chmin(ndp[np][nx], dp[p][x] + (p != np));
          }
        }
      }
    }
    swap(dp, ndp);
  }
  cout << min(dp[0][(n + 1) / 2], dp[1][(n + 1) / 2]) << '\n';
}