#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint a, b, c; cin >> a >> b >> c;
  cout << 2 * min(a, b) + (a != b) + 2 * c << '\n';
}