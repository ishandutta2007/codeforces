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
    int mx = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i] < i) {
        break;
      }
      mx = i;
    }
    int mn = n;
    for (int i = 0; i < n; ++i) {
      if (a[n - i - 1] < i) {
        break;
      }
      mn = n - i - 1;
    }
    if (mn <= mx) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}