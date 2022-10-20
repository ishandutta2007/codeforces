#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> p(n); for (auto&& e : p) cin >> e, --e;
  V<> q(n);
  for (int i = 0; i < n; ++i) q[p[i]] = i;
  V< pair<int, int> > res;
  auto fn = [&](int i, int j) -> void {
    if (i == j) return;
    if (i > j) swap(i, j);
    swap(q[p[i]], q[p[j]]);
    swap(p[i], p[j]);
    if (2 * (j - i) >= n) {
      res.emplace_back(i, j);
      return;
    }
    if (i < n / 2 and j >= n / 2) {
      res.emplace_back(i, n - 1);
      res.emplace_back(0, j);
      res.emplace_back(0, n - 1);
      res.emplace_back(i, n - 1);
      res.emplace_back(0, j);
      return;
    }
    if (i >= n / 2) {
      res.emplace_back(0, i);
      res.emplace_back(0, j);
      res.emplace_back(0, i);
      return;
    }
    if (j < n / 2) {
      res.emplace_back(i, n - 1);
      res.emplace_back(j, n - 1);
      res.emplace_back(i, n - 1);
      return;
    }
    assert(false);
  };
  for (int i = 0; i < n; ++i) {
    fn(q[i], i);
  }
  int m = res.size();
  cout << m << '\n';
  for (const auto& e : res) cout << e.first + 1 << ' ' << e.second + 1 << '\n';
}