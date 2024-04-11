#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  auto b = a;
  sort(begin(b), end(b));
  V<bool> l(n), r(n);
  l[0] = l[1] = true;
  for (int i = 2; i < n; ++i) {
    if (b[i - 2] + b[i] == 2 * b[i - 1]) l[i] = true;
    else break;
  }
  r[n - 1] = r[n - 2] = true;
  for (int i = n - 3; i >= 0; --i) {
    if (b[i] + b[i + 2] == 2 * b[i + 1]) r[i] = true;
    else break;
  }
  if (r[1]) return cout << min_element(begin(a), end(a)) - begin(a) + 1 << '\n', 0;
  if (l[n - 2]) return cout << max_element(begin(a), end(a)) - begin(a) + 1 << '\n', 0;
  for (int i = 1; i < n - 1; ++i) {
    if (l[i - 1] and r[i + 1] and (i == 1 or b[i - 2] + b[i + 1] == 2 *  b[i - 1]) and (i == n - 2 or b[i - 1] + b[i + 2] == 2 * b[i + 1])) {
      for (int j = 0; j < n; ++j) if (a[j] == b[i]) {
        cout << j + 1 << '\n';
        return 0;
      }
    }
  }
  cout << -1 << '\n';
}