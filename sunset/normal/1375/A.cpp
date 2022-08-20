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
      if (a[i] < 0) {
        a[i] *= -1;
      }
    }
    for (int i = 1; i < n; i += 2) {
      if (a[i - 1] < a[i] && a[i] < a[i + 1]) {
        if (a[i - 1] < -a[i]) {
          a[i] *= -1;
          a[i + 1] *= -1;
        } else {
          a[i] *= -1;
        }
      } else if (a[i - 1] > a[i] && a[i] > a[i + 1]) {
        a[i] *= -1;
        a[i + 1] *= -1;
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