#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  int mn = *min_element(begin(a), end(a));
  int c = count(begin(a), end(a), mn);
  cout << (c <= n / 2 ? "Alice" : "Bob") << '\n';
}