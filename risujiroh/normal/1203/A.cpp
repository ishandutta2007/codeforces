#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int Q; cin >> Q;
  while (Q--) {
    int n; cin >> n;
    V<> a(n); for (auto&& e : a) cin >> e;
    bool ok = false;
    for (int i = 0; i <= n; ++i) {
      auto v = a;
      rotate(begin(v), begin(v) + i, end(v));
      if (is_sorted(begin(v), end(v))) {
        ok = true;
        break;
      }
      v = a;
      reverse(begin(v), end(v));
      rotate(begin(v), begin(v) + i, end(v));
      if (is_sorted(begin(v), end(v))) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}