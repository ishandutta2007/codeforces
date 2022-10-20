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
  V<> c(2e5 + 1);
  for (int i = 0; i < n; ++i) {
    ++c[a[i]];
  }
  for (int i = 0; i < n; ++i) {
    if (c[i] >= 3) {
      return cout << "NO" << '\n', 0;
    }
  }
  cout << "YES" << '\n';
  V<> l, r;
  for (int x = 0; x <= 2e5; ++x) if (c[x]) {
    l.push_back(x);
    if (c[x] == 2) r.push_back(x);
  }
  reverse(begin(r), end(r));
  cout << l.size() << '\n';
  for (int i = 0; i < l.size(); ++i) {
    cout << l[i] << " \n"[i == l.size() - 1];
  }
  cout << r.size() << '\n';
  for (int i = 0; i < r.size(); ++i) {
    cout << r[i] << " \n"[i == r.size() - 1];
  }
}