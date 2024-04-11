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
    int pos = 0;
    int neg = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] > 0) {
        pos += a[i];
      } else if (a[i] < 0) {
        neg -= a[i];
      }
    }
    if (pos == neg) {
      cout << "NO" << "\n";
    } else if (pos > neg) {
      sort(a.begin(), a.end(), greater<int>());
      cout << "YES" << "\n";
      for (int i = 0; i < n; ++i) {
        if (i) {
          cout << " ";
        }
        cout << a[i];
      }
      cout << "\n";
    } else {
      sort(a.begin(), a.end());
      cout << "YES" << "\n";
      for (int i = 0; i < n; ++i) {
        if (i) {
          cout << " ";
        }
        cout << a[i];
      }
      cout << "\n";
    }
  }
  return 0;
}