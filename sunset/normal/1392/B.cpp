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
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int d = *max_element(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
      a[i] = d - a[i];
    }
    if (k % 2 == 0) {
      int d = *max_element(a.begin(), a.end());
      for (int i = 0; i < n; ++i) {
        a[i] = d - a[i];
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i) {
        cout << " ";
      }
      cout << a[i];
    }
    cout << "\n";
  }
  return 0;
}