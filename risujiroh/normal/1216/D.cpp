#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  int mx = *max_element(begin(a), end(a));
  for (auto&& e : a) {
    e = mx - e;
  }

  int d = accumulate(begin(a), end(a), 0, [](int l, int r) { return __gcd(l, r); });
  lint y = 0;
  for (int e : a) {
    y += e / d;
  }
  cout << y << ' ' << d << '\n';
}