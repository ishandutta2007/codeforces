#include <bits/stdc++.h>

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
    cout << 3 * n << '\n';
    for (int i = 1; i <= n; i += 2) {
      int j = i + 1;
      cout << "2 " << i << ' ' << j << '\n';
      cout << "1 " << i << ' ' << j << '\n';
      cout << "1 " << i << ' ' << j << '\n';
      cout << "2 " << i << ' ' << j << '\n';
      cout << "1 " << i << ' ' << j << '\n';
      cout << "1 " << i << ' ' << j << '\n';
    }
  }
}