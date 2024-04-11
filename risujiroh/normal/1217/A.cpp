#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

auto divide(auto a, auto b) -> decltype(a / b) {
  if (a >= 0 and b > 0) return a / b;
  if (a < 0 and b > 0) return -((-a + b - 1) / b);
  if (a >= 0 and b < 0) return -((a - b - 1) / -b);
  if (a < 0 and b < 0) return -a / -b;
  return 0;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    int a, b, c; cin >> a >> b >> c;
    int l = max(divide(b + c - a, 2) + 1, 0);
    int u = c;
    cout << max(u - l + 1, 0) << '\n';
  }
}