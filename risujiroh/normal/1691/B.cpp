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

    bool bad = false;
    vector<int> ans(n);
    for (int l = 0, r = 0; l < n; l = r) {
      while (r < n && a[l] == a[r]) {
        ++r;
      }

      if (r - l == 1) {
        bad = true;
        break;
      }

      for (int i = l; i < r; ++i) {
        ans[i] = i + 1;
      }
      ans[r - 1] = l;
    }

    if (bad) {
      cout << "-1\n";
    } else {
      for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " \n"[i + 1 == n];
      }
    }
  }
}