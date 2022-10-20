#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<> a(n); for (auto&& e : a) cin >> e;
  V<lint> c(n + 1);
  for (int i = 0; i < n; ++i) c[i + 1] = c[i] + a[i];
  V<lint> v;
  for (int i = 1; i < n; ++i) v.push_back(c[n] - c[i]);
  sort(rbegin(v), rend(v));
  lint res = c[n];
  for (int i = 0; i < k - 1; ++i) res += v[i];
  cout << res << '\n';
}