#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> a(n); for (auto&& e : a) cin >> e;
  auto chk = [&](int x) -> bool {
    auto b = a;
    for (int i = 0; i < n; ++i) {
      int prv = i ? b[i - 1] : 0;
      if (b[i] <= prv) {
        if (b[i] + x < prv) return false;
        b[i] = prv;
      } else {
        if (b[i] + x >= m + prv) b[i] = prv;
      }
    }
    return true;
  };
  int ng = -1, ok = m;
  while (ok - ng > 1) {
    int mid = ng + ok >> 1;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}