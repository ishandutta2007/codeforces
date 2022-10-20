#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> a;
  a.emplace_back(n);
  for (auto&& e : a[0]) cin >> e;

  int64_t mn{};
  int xr{};
  for (int s = 30; s--;) {
    vector<vector<int>> na;
    vector<int64_t> sum(2);
    for (auto&& v : a) {
      vector cnt(2, 0);
      vector<vector<int>> temp(2);
      for (int e : v) {
        int x = e >> s & 1;
        sum[x] += cnt[x ^ 1];
        ++cnt[x];
        temp[x].push_back(e);
      }
      for (auto&& e : temp)
        if (not empty(e)) na.push_back(e);
    }
    if (sum[0] > sum[1]) {
      xr |= 1 << s;
    }
    mn += min(sum[0], sum[1]);
    swap(a, na);
  }
  cout << mn << ' ' << xr << '\n';
}