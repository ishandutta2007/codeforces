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
    for (int& e : a) {
      cin >> e;
    }
    int ans = 0;
    for (int i = 0; i < n;) {
      if (a[i] == 0) {
        ++i;
        continue;
      }
      int j = i;
      while (j < n && a[j]) {
        ++j;
      }
      ++ans;
      i = j;
    }
    cout << min(ans, 2) << '\n';
  }
}