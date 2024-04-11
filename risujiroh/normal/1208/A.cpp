#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    int a, b, n; cin >> a >> b >> n;
    if (n % 3 == 0) {
      cout << a << '\n';
    } else if (n % 3 == 1) {
      cout << b << '\n';
    } else {
      cout << (a ^ b) << '\n';
    }
  }
}