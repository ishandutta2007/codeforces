#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  V<> idx(n);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) { return a[i] > a[j]; });
  lint res = 0;
  for (int k = 0; k < n; ++k) {
    int i = idx[k];
    res += k * a[i] + 1;
  }
  cout << res << '\n';
  for (int i = 0; i < n; ++i) {
    cout << idx[i] + 1 << " \n"[i == n - 1];
  }
}