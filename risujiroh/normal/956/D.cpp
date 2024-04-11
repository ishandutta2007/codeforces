#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, w;
  cin >> n >> w;
  vector<pair<double, double>> a(n);
  for (int i = 0; i < n; ++i) {
    int x, v;
    cin >> x >> v;
    a[i] = {x / double(v + w), x / double(w - v)};
  }
  sort(begin(a), end(a));
  constexpr double Eps = 1e-11;
  vector<double> v(n);
  for (int i = 0; i < n; ++i) v[i] = a[i].second;
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v), [](double x, double y) { return abs(y - x) < Eps; }), end(v));
  auto rank = [&](double x) -> int { return lower_bound(begin(v), end(v), x - Eps) - begin(v); };
  int64_t ans = 0;
  vector<int> f(n);
  for (auto&& e : a) {
    int i = rank(e.second);
    for (int j = i + 1; j; j &= j - 1) ans += f[j - 1];
    for (int j = i; j < n; j |= j + 1) ++f[j];
  }
  cout << ans << '\n';
}