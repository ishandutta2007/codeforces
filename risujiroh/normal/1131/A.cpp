#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int w0, h0, w1, h1; cin >> w0 >> h0 >> w1 >> h1;
  int res = w0 + 2 * (h0 + 1);
  res += w1 + 2 * (h1 + 1);
  res += w0 - w1;
  cout << res << '\n';
}