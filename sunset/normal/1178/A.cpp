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
  int foo = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    foo += a[i];
  }
  int bar = a[0];
  int take = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] * 2 <= a[0]) {
      bar += a[i];
      ++take;
    }
  }
  if (bar * 2 > foo) {
    cout << take << "\n";
    cout << 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] * 2 <= a[0]) {
        cout << " " << i + 1;
      }
    }
    cout << "\n";
  } else {
    cout << 0 << "\n";
  }
  return 0;
}