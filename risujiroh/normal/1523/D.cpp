#ifdef ONLINE_JUDGE
#pragma GCC target("popcnt,bmi2")
#endif
#include <bits/stdc++.h>
#include <x86intrin.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, p;
  cin >> n >> m >> p;
  vector<uint64_t> a(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    a[i] = stoull(s, nullptr, 2);
  }

  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uint64_t ans = 0;

  for (int _ = 42; _--;) {
    int fixed = uniform_int_distribution(0, n - 1)(rng);
    p = _popcnt64(a[fixed]);

    vector<int> cnt(1 << p);
    for (int i = 0; i < n; ++i) ++cnt[_pext_u64(a[i], a[fixed])];

    for (int step = 1; step < 1 << p; step *= 2)
      for (int offset = 0; offset < 1 << p; offset += 2 * step)
        for (int i = offset, j = i + step; i < offset + step; ++i, ++j) cnt[i] += cnt[j];

    for (int mask = 0; mask < 1 << p; ++mask)
      if (cnt[mask] >= (n + 1) / 2 and _popcnt64(mask) > _popcnt64(ans)) ans = _pdep_u64(mask, a[fixed]);
  }

  for (int i = m; i--;) cout << (ans >> i & 1);
  cout << '\n';
}