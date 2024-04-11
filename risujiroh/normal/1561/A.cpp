#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) {
      cin >> e;
    }

    int ans = 0;
    while (!is_sorted(begin(a), end(a))) {
      for (int i = ans & 1; i + 1 < n; i += 2) {
        if (a[i] > a[i + 1]) {
          swap(a[i], a[i + 1]);
        }
      }
      ++ans;
    }
    cout << ans << '\n';
  }
}