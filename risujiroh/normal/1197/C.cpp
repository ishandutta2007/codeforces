#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<> a(n); for (auto&& e : a) cin >> e;
  int res = a.back() - a[0];
  V<> d;
  for (int i = 1; i < n; ++i) d.push_back(a[i] - a[i - 1]);
  sort(rbegin(d), rend(d));
  res -= accumulate(begin(d), begin(d) + (k - 1), 0);
  cout << res << '\n';
}