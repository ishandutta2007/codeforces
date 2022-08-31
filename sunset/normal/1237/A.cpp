#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] % 2) {
      a[i] = (a[i] - 1) / 2;
      b[i] = 1;
    } else {
      a[i] = a[i] / 2;
    }
  }
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
  }
  for (int i = 0; i < n; ++i) {
    if (b[i]) {
      if (sum < 0) {
        cout << a[i] + 1 << "\n";
        ++sum;
      } else {
        cout << a[i] << "\n";
      }
    } else {
      cout << a[i] << "\n";
    }
  }
  return 0;
}