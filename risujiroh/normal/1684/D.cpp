#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] += i;
    }
    nth_element(begin(a), begin(a) + (n - k), end(a));
    auto ans = accumulate(begin(a), begin(a) + (n - k), 0ll);
    for (int i = 1; i < n - k; ++i) {
      ans -= i;
    }
    cout << ans << '\n';
  }
}