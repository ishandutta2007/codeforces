#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto&& e : a) cin >> e, e |= 1 << 30;

  constexpr int sz = 512;
  int m = (n + sz - 1) / sz;

  struct block {
    int lazy;
    vector<int> base;
  };
  vector<block> b(m);

  auto add = [&](auto&& v, int x) -> void {
    for (int e : v) x = min(x, x ^ e);
    if (x) v.push_back(x);
  };

  auto push = [&](int k) -> void {
    for (int i = k * sz; i < min((k + 1) * sz, n); ++i) a[i] ^= b[k].lazy;
  };
  auto build = [&](int k) -> void {
    b[k].lazy = 0;
    b[k].base.clear();
    for (int i = k * sz; i < min((k + 1) * sz, n); ++i) add(b[k].base, a[i]);
  };
  for (int k = 0; k < m; ++k) build(k);

  auto run = [&](int l, int r, auto fa, auto fb) -> void {
    if (l % sz) {
      push(l / sz);
      while (l < r and l % sz) fa(l++);
      build((l - 1) / sz);
    }
    if (r % sz) {
      push(r / sz);
      while (l < r and r % sz) fa(--r);
      build(r / sz);
    }
    for (; l < r; l += sz) fb(l / sz);
  };

  while (q--) {
    int type, l, r;
    cin >> type >> l >> r;
    --l;
    if (type == 1) {
      int x;
      cin >> x;
      run(
          l, r, [&](int i) { a[i] ^= x; }, [&](int k) { b[k].lazy ^= x; });
    } else if (type == 2) {
      vector<int> v;
      run(
          l, r, [&](int i) { add(v, a[i] & ~(1 << 30)); },
          [&](int k) {
            for (int e : b[k].base) {
              if (e >> 30 & 1) {
                e &= ~(1 << 30);
                e ^= b[k].lazy;
              }
              add(v, e);
            }
          });
      cout << (1 << size(v)) << '\n';
    } else
      assert(false);
  }
}