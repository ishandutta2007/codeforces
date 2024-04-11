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
  int n; cin >> n;
  int t = 0;
  while (n--) {
    int a; cin >> a;
    int b = divide(a, 2);
    if (a & 1) {
      b += t & 1;
      ++t;
    }
    cout << b << '\n';
  }
}