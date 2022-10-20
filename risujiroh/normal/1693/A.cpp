#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;

    while (!empty(a) && a.back() == 0) {
      --n;
      a.pop_back();
    }

    using i64 = long long;

    vector<i64> s(n + 1);
    for (int i = 0; i < n; ++i) {
      s[i + 1] = s[i] + a[i];
    }

    if (s[n]) {
      cout << "NO\n";
      continue;
    }

    bool ok = true;
    for (int i = 1; i < n; ++i) {
      if (s[i] <= 0) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}