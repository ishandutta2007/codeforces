#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) void(0)
#endif

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int64_t> a(n);
  for (auto&& e : a) cin >> e;
  if (n == 1) {
    cout << "1 1\n";
    cout << -a[0] << '\n';
    for (int _ = 2; _--;) {
      cout << "1 1\n";
      cout << "0\n";
    }
    exit(0);
  }
  {
    cout << "1 1\n";
    cout << -a[0] << '\n';
    a[0] = 0;
  }
  {
    cout << "2 " << n << '\n';
    for (int i = 1; i < n; ++i) {
      auto r = a[i] % n;
      if (r < 0) r += n;
      cout << r * (n - 1) << " \n"[i == n - 1];
      a[i] += r * (n - 1);
    }
  }
  {
    cout << "1 " << n << '\n';
    for (int i = 0; i < n; ++i) cout << -a[i] << " \n"[i == n - 1];
  }
}