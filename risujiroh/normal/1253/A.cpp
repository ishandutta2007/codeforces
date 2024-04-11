#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    V<> a(n); for (auto&& e : a) cin >> e;
    deque<int> b(n); for (auto&& e : b) cin >> e;
    for (int i = 0; i < n; ++i) {
      b[i] -= a[i];
    }
    while (not b.empty() and b[0] == 0) {
      b.pop_front();
    }
    while (not b.empty() and b.back() == 0) {
      b.pop_back();
    }
    if (b.empty() or all_of(begin(b), end(b), [&](int x) { return x > 0 and x == b[0]; })) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}