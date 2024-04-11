#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<int64_t> lcms{1};
  for (int i = 2;; ++i) {
    lcms.push_back(lcm(lcms.back(), i));
    if (lcms.back() > int64_t(1e16)) {
      lcms.pop_back();
      break;
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t n;
    cin >> n;
    constexpr int64_t mod = int(1e9) + 7;
    int64_t ans = n;
    for (auto&& e : lcms) {
      ans += n / e;
      ans %= mod;
    }
    cout << ans << '\n';
  }
}