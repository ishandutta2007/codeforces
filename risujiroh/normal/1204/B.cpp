#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, l, r; cin >> n >> l >> r;
  {
    int res = (1 << l) - 1 + (n - l);
    cout << res << ' ';
  }
  {
    int res = (1 << r) - 1 + (n - r) * (1 << r - 1);
    cout << res << '\n';
  }
}