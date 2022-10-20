#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  bitset<1 << 19> bs;
  while (n--) {
    int a;
    cin >> a;
    bs[a] = 1;
  }
  n = 1 << k;
  constexpr int Inf = 1e9;
  struct Node {
    int len = 0;
    int min_diff = +Inf;
    int mn = +Inf, mx = -Inf;
    Node* l = nullptr;
    Node* r = nullptr;
  };
  auto upd = [&](Node& e) {
    e.len = e.l->len + e.r->len;
    e.min_diff = min(e.l->min_diff, e.r->min_diff);
    if (0 <= e.l->mx && e.l->mx < e.l->len && 0 <= e.r->mn && e.r->mn < e.r->len)
      e.min_diff = min(e.min_diff, (e.l->len + e.r->mn) - e.l->mx);
    e.mn = 0 <= e.l->mn && e.l->mn < e.l->len   ? e.l->mn
           : 0 <= e.r->mn && e.r->mn < e.r->len ? e.l->len + e.r->mn
                                                : +Inf;
    e.mx = 0 <= e.r->mx && e.r->mx < e.r->len   ? e.l->len + e.r->mx
           : 0 <= e.l->mx && e.l->mx < e.l->len ? e.l->mx
                                                : -Inf;
  };
  vector<Node> t(2 * n);
  for (int i = 0; i < n; ++i) {
    t[n + i].len = 1;
    if (bs[i]) t[n + i].mn = t[n + i].mx = 0;
  }
  for (int i = n; i-- > 1;) {
    t[i].l = &t[2 * i];
    t[i].r = &t[2 * i + 1];
    upd(t[i]);
  }
  vector<int> ans(n, -1);
  vector<int> order{0};
  for (int step = n; step /= 2;) {
    int sz = size(order);
    for (int i = 0; i < sz; ++i) order.push_back(order[i] + step);
  }
  auto go = [&](int j) {
    for (int i = 1 << (k - j - 1); i < 2 << (k - j - 1); ++i) {
      swap(t[i].l, t[i].r);
    }
    for (int i = 2 << (k - j - 1); i-- > 1;) {
      upd(t[i]);
    }
  };
  int cur = 0;
  for (int i : order) {
    for (int j = 0; j < k; ++j)
      if ((cur ^ i) >> j & 1) {
        go(j);
        cur ^= 1 << j;
      }
    ans[i] = t[1].min_diff;
    assert(cur == i);
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}