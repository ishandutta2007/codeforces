#include <bits/stdc++.h>
using namespace std;

template <class T> struct range_add {
  static constexpr T inf = numeric_limits<T>::max() / 2;
  struct node { T delta = 0, min = inf; };
  static node op(const node& l, const node& r) {
    return {l.delta + r.delta, std::min(l.min, l.delta + r.min)};
  }
  static node make_node(T a) { return {a, a}; }
  const int n;
  vector<node> t;
  range_add(const vector<T>& v) : n(v.size() + 1), t(2 * n) {
    for (int i = n - 1; i--; ) t[n + i] = make_node(v[i] - (i ? v[i - 1] : 0));
    for (int i = n; i-- > 1; ) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
  node fold(int l, int r) const {
    node a, b;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = op(a, t[l++]);
      if (r & 1) b = op(t[--r], b);
    }
    return op(a, b);
  }
  T get(int i) const { return fold(0, i + 1).delta; }
  T min(int l, int r) const { return get(l - 1) + fold(l, r).min; }
  void set(int i, const node& a) {
    t[i += n] = a;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
  void add(int l, int r, T a) {
    set(l, make_node(t[n + l].delta + a));
    set(r, make_node(t[n + r].delta - a));
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    a[p] = i;
  }
  vector<int> q(n);
  for (auto&& e : q) {
    cin >> e;
    --e;
  }
  q.pop_back();
  range_add<int> ra(vector<int>(n, 0));
  cout << n;
  int x = n - 1;
  for (int i : q) {
    ra.add(0, i + 1, 1);
    while (ra.min(0, n) >= 0) {
      ra.add(0, a[x] + 1, -1);
      --x;
    }
    cout << ' ' << x + 2;
  }
  cout << '\n';
}