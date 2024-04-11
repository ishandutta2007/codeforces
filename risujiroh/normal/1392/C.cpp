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
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    auto res = 0LL;
    for (int i = 0; i < n - 1; ++i) {
      res += max(a[i] - a[i + 1], 0);
    }
    cout << res << '\n';
  }
}