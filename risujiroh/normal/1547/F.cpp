#include <bits/stdc++.h>

namespace linear_sieve {

std::vector<int> primes, lpf;
void init(int n) {
  if (n < int(std::size(lpf))) return;
  if (n < 2 * int(std::size(lpf))) n = 2 * std::size(lpf);
  lpf.resize(n + 1, -1);
  for (int d = 2; d <= n; ++d) {
    if (lpf[d] == -1) lpf[d] = d, primes.push_back(d);
    for (int p : primes) {
      if (p * d > n or p > lpf[d]) break;
      lpf[p * d] = p;
    }
  }
}
std::vector<int> factor(int n) {
  __glibcxx_assert(n >= 1);
  std::vector<int> res;
  for (init(n); n > 1; n /= res.back()) res.push_back(lpf[n]);
  return res;
}

}  // namespace linear_sieve

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  linear_sieve::init(1e6);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    {
      int g = accumulate(begin(a), end(a), 0, [](int x, int y) { return gcd(x, y); });
      for (auto&& e : a) e /= g;
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
      auto f = linear_sieve::factor(a[i]);
      for (int l = 0; l < int(size(f));) {
        int r = l;
        while (r < int(size(f)) && f[r] == f[l]) ++r;
        mp[f[l]].emplace_back(i);
        l = r;
      }
    }
    int ans = 0;
    for (auto&& [p, v] : mp) {
      int cur = 0;
      for (int _ = 2; _--;)
        for (int i = 0; i < int(size(v)); ++i) {
          if ((i && v[i - 1] + 1 == v[i]) || (v[i] == 0 && v.back() + 1 == n))
            ++cur;
          else
            cur = 1;
          ans = max(ans, cur);
        }
    }
    cout << ans << '\n';
  }
}