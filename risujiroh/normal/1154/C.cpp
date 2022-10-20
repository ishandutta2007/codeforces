#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  V<> a(3); for (auto&& e : a) cin >> e;
  V<> idx{0, 1, 2, 0, 2, 1, 0};
  int res = min({a[0] / 3, a[1] / 2, a[2] / 2});
  a[0] -= 3 * res;
  a[1] -= 2 * res;
  a[2] -= 2 * res;
  res *= 7;
  auto b = res;
  for (int s = 0; s < 7; ++s) {
    auto _a = a;
    int curr = b;
    for (int i = s; ; ++i) {
      if (!_a[idx[i % 7]]) break;
      --_a[idx[i % 7]];
      ++curr;
    }
    res = max(res, curr);
  }
  cout << res << '\n';
}