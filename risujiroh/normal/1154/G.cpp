#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class Z> Z lcm(Z a, Z b) { return a / __gcd(a, b) * b; }

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  auto _a = a;
  sort(begin(a), end(a));
  lint x = 1e18, y = 1;
  for (int i = 0; i < n - 1; ++i) if (a[i] == a[i + 1]) {
    x = y = a[i];
    break;
  }
  a.erase(unique(begin(a), end(a)), end(a));
  n = a.size();
  bitset<10000001> bs;
  for (int i = 0; i < n; ++i) bs[a[i]] = true;
  for (int d = 1; d <= 1e7; ++d) {
    int s = 0;
    lint nx = -1;
    for (int i = d; i <= 1e7; i += d) if (bs[i]) {
      ++s;
      if (s == 1) {
        nx = i;
      } else if (s == 2) {
        if (lcm<lint>(nx, i) < lcm(x, y)) {
          x = nx, y = i;
        }
        break;
      }
    }
  }
  int i = find(begin(_a), end(_a), x) - begin(_a);
  int j = find(begin(_a), end(_a), y) - begin(_a);
  if (x == y) j = find(begin(_a) + i + 1, end(_a), y) - begin(_a);
  if (i > j) swap(i, j);
  cout << i + 1 << ' ' << j + 1 << '\n';
}