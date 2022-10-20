#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int a, b; cin >> a >> b;
    if (__gcd(a, b) == 1) {
      cout << "Finite" << '\n';
    } else {
      cout << "Infinite" << '\n';
    }
  }
}