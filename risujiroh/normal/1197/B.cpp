#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  int i = max_element(begin(a), end(a)) - begin(a);
  bool ok = true;
  if (!is_sorted(begin(a), begin(a) + i)) ok = false;
  if (!is_sorted(begin(a) + i, end(a), greater<int>())) ok = false;
  cout << (ok ? "YES" : "NO") << '\n';
}