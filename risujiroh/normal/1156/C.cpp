#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, z; cin >> n >> z;
  V<> x(n); for (auto&& e : x) cin >> e;
  sort(begin(x), end(x));
  auto chk = [&](int k) -> bool {
    for (int i = 0; i < k; ++i) if (x[n - k + i] - x[i] < z) return false;
    return true;
  };
  int ok = 0, ng = n / 2 + 1;
  while (ng - ok > 1) {
    int m = ok + ng >> 1;
    (chk(m) ? ok : ng) = m;
  }
  cout << ok << '\n';
}