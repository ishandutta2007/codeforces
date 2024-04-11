#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<array<int, 4>> a(n);
    for (auto&& arr : a)
      for (auto&& e : arr) cin >> e;
    if (m & 1) {
      cout << "NO\n";
      continue;
    }
    bool ok = false;
    for (auto&& arr : a)
      if (arr[1] == arr[2]) {
        ok = true;
        break;
      }
    cout << (ok ? "YES\n" : "NO\n");
  }
}