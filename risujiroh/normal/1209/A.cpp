#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  int res = 0;
  sort(begin(a), end(a));
  V<bool> b(n);
  for (int i = 0; i < n; ++i) if (!b[i]) {
    for (int j = i; j < n; ++j) if (a[j] % a[i] == 0) {
      b[j] = true;
    }
    ++res;
  }
  cout << res << '\n';
}