#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, c;
  cin >> n >> c;
  vector<int> p(n), s(n);
  for (auto&& e : p) cin >> e;
  for (auto&& e : s) cin >> e;
  vector<int64_t> f{0};
  for (int i = 0; i < n; ++i) {
    vector nf(i + 2, numeric_limits<int64_t>::max());
    for (int j = 0; j <= i; ++j) {
      nf[j] = min(nf[j], f[j] + p[i] + int64_t(c) * j);
      nf[j + 1] = min(nf[j + 1], f[j] + s[i]);
    }
    f = move(nf);
  }
  cout << *min_element(begin(f), end(f)) << '\n';
}