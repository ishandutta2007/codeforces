#include <bits/stdc++.h>
using namespace std;

constexpr long long inf = 0x3f3f3f3fLL << 32;

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
    multiset<long long> ms;
    long long s = 0, mx = -inf;
    for (int i = 0; i < n; ++i) {
      ms.insert(s);
      s += a[i];
      if (i == n - 1) {
        ms.erase(ms.find(0));
      }
      mx = max(mx, s - *begin(ms));
    }
    if (s > mx) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}