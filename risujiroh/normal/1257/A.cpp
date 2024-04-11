#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n, x, a, b; cin >> n >> x >> a >> b;
    if (a > b) swap(a, b);
    cout << min(b - a + x, n - 1) << '\n';
  }
}