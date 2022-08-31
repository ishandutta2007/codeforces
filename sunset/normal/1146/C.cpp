#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; 1 << i < n; ++i) {
      vector<int> a, b;
      for (int j = 0; j < n; ++j) {
        if (j >> i & 1) {
          a.push_back(j);
        } else {
          b.push_back(j);
        }
      }
      cout << a.size() << " " << b.size();
      for (auto x : a) {
        cout << " " << x + 1;
      }
      for (auto x : b) {
        cout << " " << x + 1;
      }
      cout << endl;
      int verdict;
      cin >> verdict;
      ans = max(ans, verdict);
    }
    cout << -1 << " " << ans << endl;
  }
  return 0;
}