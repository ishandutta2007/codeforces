#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    bool ok = false;
    for (int i = 1; i < n; ++i)
      if (a[i - 1] <= a[i]) {
        ok = true;
        break;
      }
    cout << (ok ? "YES\n" : "NO\n");
  }
}