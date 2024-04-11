#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  int m = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    m += x & 1;
  }
  cout << min(m, n - m) << '\n';
}