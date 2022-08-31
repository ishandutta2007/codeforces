#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    if (*max_element(a.begin(), a.end()) == *min_element(a.begin(), a.end())) {
      cout << n << "\n";
    } else {
      cout << 1 << "\n";
    }
  }
  return 0;
}