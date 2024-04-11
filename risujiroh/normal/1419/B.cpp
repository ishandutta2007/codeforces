#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int64_t n = 1;
  vector<int64_t> v;
  while (n < int(2e9)) {
    v.push_back(n * (n + 1) / 2);
    n *= 2;
    n += 1;
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t x;
    cin >> x;
    int res{};
    auto it = begin(v);
    while (it != end(v) and *it <= x) {
      x -= *it;
      ++it;
      ++res;
    }
    cout << res << '\n';
  }
}