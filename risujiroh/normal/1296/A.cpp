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
    int odd = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      odd += a[i] & 1;
    }
    if (odd & 1 or (odd != 0 and odd != n)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}