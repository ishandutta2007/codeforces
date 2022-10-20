#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n);
  int o = 0;
  for (auto&& e : a) {
    cin >> e;
    o += e & 1;
  }
  if (0 < o and o < n) {
    sort(begin(a), end(a));
  }
  for (int i = 0; i < n; ++i) cout << a[i] << " \n"[!(n + ~i)];
}