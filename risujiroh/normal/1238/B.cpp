#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int n, r; cin >> n >> r;
    deque<int> x(n); for (auto&& e : x) cin >> e;
    sort(begin(x), end(x));
    x.erase(unique(begin(x), end(x)), end(x));
    int l = 0, res = 0;
    while (not x.empty()) {
      x.pop_back();
      l += r;
      while (not x.empty() and x[0] <= l) {
        x.pop_front();
      }
      ++res;
    }
    cout << res << '\n';
  }
}