#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int n, k; cin >> n >> k;
    V<> a(n); for (auto&& e : a) cin >> e;
    int c = count_if(begin(a), end(a), [](int x) { return x & 1; });
    if (c < k or (c & 1) != (k & 1)) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; ++i) if (a[i] & 1) {
      if (!--k) break;
      cout << i + 1 << ' ';
    }
    cout << n << '\n';
  }
}