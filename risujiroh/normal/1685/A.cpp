#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    sort(begin(a), end(a));
    if (n & 1) {
      cout << "NO\n";
      continue;
    }
    vector<int> b;
    b.reserve(n);
    for (int i = 0; i < n / 2; ++i) {
      b.push_back(a[i]);
      b.push_back(a[i + n / 2]);
    }
    if (adjacent_find(begin(b), end(b)) == end(b)) {
      cout << "YES\n";
      for (int i = 0; i < n; ++i) {
        cout << b[i] << " \n"[i + 1 == n];
      }
    } else {
      cout << "NO\n";
    }
  }
}