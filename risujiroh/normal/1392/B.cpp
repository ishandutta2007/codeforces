#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int64_t k;
    cin >> k;
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    auto op = [&] {
      auto mx = *max_element(begin(a), end(a));
      for (auto&& e : a) e = mx - e;
    };
    op();
    --k;
    if (k & 1) op();
    for (int i = 0; i < n; ++i) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
}