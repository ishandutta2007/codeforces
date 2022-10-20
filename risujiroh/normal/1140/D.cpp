#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  lint res = 0;
  for (int i = 2; i < n; ++i) {
    res += i * (i + 1);
  }
  cout << res << '\n';
}