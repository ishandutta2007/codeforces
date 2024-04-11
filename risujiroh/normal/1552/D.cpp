#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    set<int> se;
    for (int _ = n; _--;) {
      int a;
      cin >> a;
      if (a == 0) continue;
      se.insert(abs(a));
    }
    if (int(size(se)) < n) {
      cout << "YES\n";
      continue;
    }
    vector<int> a(begin(se), end(se));
    vector<int> sum(1 << n);
    for (int mask = 0; mask < 1 << n; ++mask) {
      for (int i = 0; i < n; ++i)
        if (mask >> i & 1) sum[mask] += a[i];
    }
    bool any = false;
    for (int x = 1; x < 1 << n; ++x)
      for (int y = 1; y < 1 << n; ++y) {
        if (x & y) continue;
        any |= sum[x] == sum[y];
      }
    cout << (any ? "YES\n" : "NO\n");
  }
}