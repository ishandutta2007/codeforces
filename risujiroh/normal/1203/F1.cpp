#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
 
int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, r; cin >> n >> r;
  V<> a(n), b(n); for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  V<> idx(n);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) {
    if (b[i] >= 0 and b[j] < 0) return true;
    if (b[i] < 0 and b[j] >= 0) return false;
    if (b[i] >= 0 and b[j] >= 0) return a[i] < a[j];
    return max(a[i], a[j] - b[i]) < max(a[j], a[i] - b[j]);
  });
  for (int i : idx) {
    if (r < a[i]) return cout << "NO" << '\n', 0;
    r += b[i];
  }
  if (r < 0) return cout << "NO" << '\n', 0;
  cout << "YES" << '\n';
}