#include <bits/extc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, d, m;
  cin >> n >> d >> m;
  using ll = long long;
  vector<ll> large, small;
  for (int _ = n; _--; ) {
    int a;
    cin >> a;
    if (a > m) {
      large.push_back(a);
    } else {
      small.push_back(a);
    }
  }
  sort(begin(large), end(large), greater<>());
  sort(begin(small), end(small), greater<>());
  partial_sum(begin(large), end(large), begin(large));
  partial_sum(begin(small), end(small), begin(small));
  large.insert(begin(large), 0);
  small.insert(begin(small), 0);
  large.resize(n + 1, large.back());
  small.resize(n + 1, small.back());
  ll res = 0;
  for (int x = 0; x <= (n + d) / (d + 1); ++x) {
    int y = x ? n - x - d * (x - 1) : n;
    ll cur = large[x] + small[y];
    res = max(res, cur);
  }
  cout << res << '\n';
}