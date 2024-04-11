#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) {
      cin >> e;
    }
    [&] {
      for (int i = 0; i < n - 1; ++i) {
        if (abs(a[i + 1] - a[i]) >= 2) {
          cout << "YES\n";
          cout << i + 1 << ' ' << i + 2 << '\n';
          return;
        }
      }
      cout << "NO\n";
    }();
  }
}