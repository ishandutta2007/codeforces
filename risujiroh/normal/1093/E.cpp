#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


template<class Int> struct FenwickTree {
  const int n;

  FenwickTree(int n) : n(n), t(n + 1) {}

  void add(int x, Int a) {
    assert(0 <= x and x < n);
    for (int i = x + 1; i <= n; i += i & -i) t[i] += a;
  }

  Int sum(int x) {
    x = min(x, n);
    Int res = 0;
    for (int i = x; i > 0; i -= i & -i) res += t[i];
    return res;
  }

  Int sum(int l, int r) {
    l = max(0, l), r = min(r, n);
    if (l >= r) return 0;
    return sum(r) - sum(l);
  }

private:
  V<Int> t;
};

using FT = FenwickTree<int>;

struct SegmentTree {
  const int n;
  V< unique_ptr<FT> > t;
  VV<> ys;

  template<class Itr> SegmentTree(Itr first, Itr last) :
    n(distance(first, last)), t(2 * n), ys(2 * n) {
    copy(first, last, next(begin(ys), n));
    for (int i = 2 * n - 1; i > 0; --i) {
      if (i < n) merge(begin(ys[2 * i]), end(ys[2 * i]), begin(ys[2 * i + 1]), end(ys[2 * i + 1]), back_inserter(ys[i]));
      t[i] = make_unique<FT>(ys[i].size());
    }
  }

  int sum(int x, int yl, int yr) const {
    yl = distance(begin(ys[x]), lower_bound(begin(ys[x]), end(ys[x]), yl));
    yr = distance(begin(ys[x]), lower_bound(begin(ys[x]), end(ys[x]), yr));
    return t[x]->sum(yl, yr);
  }
  int sum(int xl, int xr, int yl, int yr) const {
    int sl = 0, sr = 0;
    for (xl += n, xr += n; xl < xr; xl >>= 1, xr >>= 1) {
      if (xl & 1) sl += sum(xl++, yl, yr);
      if (xr & 1) sr += sum(--xr, yl, yr);
    }
    return sl + sr;
  }

  void _add(int x, int y, int v) {
    y = distance(begin(ys[x]), lower_bound(begin(ys[x]), end(ys[x]), y));
    t[x]->add(y, v);
  }
  void add(int x, int y, int v) {
    for (x += n; x > 0; x >>= 1) {
      _add(x, y, v);
    }
  }
};

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
  V<> b(n); for (int i = 0; i < n; ++i) cin >> b[i], --b[i];
  V<> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    x[a[i]] = i;
    y[b[i]] = i;
  }
  VV<> ys(n);
  for (int i = 0; i < n; ++i) {
    ys[i].push_back(y[a[i]]);
  }
  VV<> query(q);
  for (int i = 0; i < q; ++i) {
    int type; cin >> type;
    if (type == 1) {
      int xl, xr, yl, yr; cin >> xl >> xr >> yl >> yr, --xl, --yl;
      query[i] = {xl, xr, yl, yr};
    } else {
      int il, ir; cin >> il >> ir, --il, --ir;
      query[i] = {il, ir};
      swap(y[b[il]], y[b[ir]]);
      swap(b[il], b[ir]);
      ys[x[b[il]]].push_back(il);
      ys[x[b[ir]]].push_back(ir);
    }
  }
  for (int i = q - 1; i >= 0; --i) if (query[i].size() == 2) {
    int il = query[i][0], ir = query[i][1];
    swap(y[b[il]], y[b[ir]]);
    swap(b[il], b[ir]);
  }
  for (auto&& v : ys) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
  }
  SegmentTree st(begin(ys), end(ys));
  for (int i = 0; i < n; ++i) {
    st.add(x[i], y[i], 1);
  }
  for (int i = 0; i < q; ++i) {
    if (query[i].size() == 4) {
      int xl = query[i][0], xr = query[i][1], yl = query[i][2], yr = query[i][3];
      cout << st.sum(xl, xr, yl, yr) << '\n';
    } else {
      int il = query[i][0], ir = query[i][1];
      st.add(x[b[il]], y[b[il]], -1);
      st.add(x[b[ir]], y[b[ir]], -1);
      swap(y[b[il]], y[b[ir]]);
      swap(b[il], b[ir]);
      st.add(x[b[il]], y[b[il]], 1);
      st.add(x[b[ir]], y[b[ir]], 1);
    }
  }
}