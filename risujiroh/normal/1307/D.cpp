#include <bits/stdc++.h>
using namespace std;

template <class T, class Op> struct segtree {
  const Op op;
  const T e;
  const int n;
  vector<T> t;
  segtree(int _n, Op _op, T _e) : op(_op), e(_e), n(_n), t(2 * n, e) {}
  T& operator[](int i) { return t[n + i]; }
  void build() { for (int i = n; i-- > 1; ) t[i] = op(t[2 * i], t[2 * i + 1]); }
  T fold(int l, int r) const {
    T a = e, b = e;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = op(a, t[l++]);
      if (r & 1) b = op(t[--r], b);
    }
    return op(a, b);
  }
  void set(int i, T a) {
    t[i += n] = a;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
};
template <class T, class Op> auto make_segtree(int n, Op op, T e) {
  return segtree<T, Op>(n, op, e);
}
auto maximum = [](auto l, auto r) { return l < r ? r : l; };

auto chmin = [](auto&& l, auto r) { return r < l ? l = r, 1 : 0; };

constexpr int inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(k);
  for (auto&& e : a) {
    cin >> e;
    --e;
  }
  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  auto bfs = [&](int s) {
    vector<int> d(n, inf);
    queue<int> que;
    d[s] = 0;
    que.push(s);
    while (not que.empty()) {
      int v = que.front();
      que.pop();
      for (int u : g[v]) {
        if (chmin(d[u], d[v] + 1)) {
          que.push(u);
        }
      }
    }
    return d;
  };
  auto ds = bfs(0), dt = bfs(n - 1);
  auto chk = [&](int mid) {
    auto st = make_segtree(n, maximum, -inf);
    for (int x : a) {
      if (st.fold(max(mid - dt[x] - 1, 0), n) >= mid - ds[x] - 1) {
        return true;
      }
      int d = ds[x];
      st.set(d, max(st[d], dt[x]));
    }
    return false;
  };
  int ok = 1, ng = ds.back() + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}