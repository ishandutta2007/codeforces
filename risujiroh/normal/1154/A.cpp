#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  V<> a(4); for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  for (int i = 0; i < 3; ++i) {
    cout << a[3] - a[i] << " \n"[i == 2];
  }
}