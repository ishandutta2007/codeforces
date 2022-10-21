#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int lim = n * m;
  using num = double;
  vector<num> f(lim);
  f[0] = 1;
  int sum = 0;
  while (n--) {
    int a;
    cin >> a;
    --a;
    sum += a;
    auto nf = f;
    auto go = [&](int offset, int coeff) -> void {
      for (int i = 0; offset + i < lim; ++i) nf[offset + i] += coeff * f[i];
    };
    go(m, -1);
    go(a, -1);
    go(a + 1, 1);
    swap(f, nf);
    for (int i = 1; i < lim; ++i) f[i] += f[i - 1];
    for (auto&& e : f) e /= m - 1;
  }
  num ans = 1 + accumulate(begin(f), begin(f) + sum, num{}) * (m - 1);
  cout << fixed << setprecision(10) << ans << '\n';
}