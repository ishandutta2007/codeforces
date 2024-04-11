#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  array<int64_t, 4> cnt{};
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    ++cnt[(x & 2) | (y >> 1 & 1)];
  }
  int64_t ans = 0;
  for (auto&& e : cnt) {
    ans += e * (e - 1) * (e - 2) / 6;
    ans += e * (e - 1) / 2 * (n - e);
  }
  cout << ans << '\n';
}