#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto&& e : a) {
      cin >> e;
    }
    long long sum = accumulate(begin(a), end(a), 0LL);
    if (sum <= s) {
      cout << 0 << '\n';
    } else {
      sum = 0;
      for (int i = 0; i < n; ++i) {
        if (sum + a[i] > s) {
          int res = max_element(begin(a), begin(a) + i + 1) - begin(a);
          cout << res + 1 << '\n';
          break;
        }
        sum += a[i];
      }
    }
  }
}