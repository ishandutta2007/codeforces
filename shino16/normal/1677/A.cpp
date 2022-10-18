#line 2 "lib/prelude.hpp"
#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define repr2(i, m, n) for (auto i = (n); i-- > (m);)
#define repr(i, n) repr2(i, 0, n)
#define all(x) begin(x), end(x)
#line 3 "lib/algebra.hpp"

#define CONST(val) [] { return val; }
#define WRAP_FN(func) \
  [](auto&&... args) { return func(forward<decltype(args)>(args)...); }

template <class Unit, class Op>
struct monoid : private Unit, private Op {
  using type = decltype(declval<Unit>()());
  monoid(Unit unit, Op op) : Unit(unit), Op(op) {}
  type unit() const { return Unit::operator()(); }
  type op(type a, type b) const { return Op::operator()(a, b); }
};

template <class Unit, class Op, class Inv>
struct group : monoid<Unit, Op>, private Inv {
  using type = typename monoid<Unit, Op>::type;
  group(Unit unit, Op op, Inv inv) : monoid<Unit, Op>(unit, op), Inv(inv) {}
  type inv(type a) const { return Inv::operator()(a); }
};

template <class T>
struct addition {
  using type = T;
  type unit() const { return 0; }
  type op(type a, type b) const { return a + b; }
  type inv(type a) const { return -a; }
};

template <class T>
struct maximum {
  using type = T;
  type unit() const { return numeric_limits<T>::min(); }
  type op(type a, type b) const { return a > b ? a : b; }
};

template <class T>
struct minimum {
  using type = T;
  type unit() const { return numeric_limits<T>::max(); }
  type op(type a, type b) const { return a > b ? b : a; }
};
#line 3 "lib/bit/clz.hpp"

template <class T>
__attribute__ ((target ("lzcnt"))) int clz(T x) {
    if (!x) return sizeof(T) * 8;
    if constexpr (sizeof(T) <= sizeof(int)) {
        return __builtin_clz((int)x);
    } else if constexpr (sizeof(T) <= sizeof(ll)) {
        return __builtin_clzll((ll)x);
    } else if constexpr (sizeof(T) <= sizeof(ll) * 2) {
        int l = clz((ll)(x >> sizeof(ll) * 8));
        return l != sizeof(ll) * 8 ? l : l + clz((ll)x);
    }
}
#line 4 "lib/bit/ilog2.hpp"

template <class T>
int ilog2(T x) { assert(x != 0); return sizeof(T) * 8 - 1 - clz(x); }

template <class T>
int ilog2_ceil(T x) { return x == 0 || x == 1 ? 1 : ilog2(x - 1) + 1; }

template <class T>
T bit_floor(T x) { return T(1) << ilog2(x); }

template <class T>
T bit_ceil(T x) { return T(1) << ilog2_ceil(x); }
#line 4 "lib/ds/fenwick.hpp"

template <class M>
class fenwick_tree {
 public:
  using value_type = typename M::type;
  fenwick_tree(vector<value_type> v, M m = M()) : m(m), data(move(v)) {
    data.insert(data.cbegin(), m.unit());
    for (int i = 1; i < data.size(); i++) {
      if (i + lsb(i) < data.size())
        data[i + lsb(i)] = m.op(data[i + lsb(i)], data[i]);
    }
  }
  template <class Iter>
  fenwick_tree(Iter f, Iter l, M m = M())
      : fenwick_tree(vector<value_type>(f, l), m) {}
  fenwick_tree(int n, M m = M()) : m(m), data(n + 1, m.unit()) {}
  int size() const { return data.size() - 1; }
  void clear() { fill(data.begin(), data.end(), m.unit()); }
  void add(int i, value_type v) {
    for (i++; i < data.size(); i += lsb(i)) data[i] = m.op(data[i], v);
  }
  void sub(int i, value_type v) { add(i, m.inv(v)); }
  void assign(int i, value_type v) { add(i, m.op(v, m.inv(sum(i, i + 1)))); }
  value_type sum(int r) const {
    value_type res = m.unit();
    for (; r; r -= lsb(r)) res = m.op(res, data[r]);
    return res;
  }
  value_type sum(int l, int r) const { return m.op(m.inv(sum(l)), sum(r)); }
  template <class F>
  int partition_point(F pred = F()) const {
    int i = 0;
    value_type s = m.unit();
    if (!pred(s)) return i;
    for (int w = bit_floor(data.size()); w; w >>= 1) {
      if (i + w < data.size()) {
        value_type s2 = m.op(s, data[i + w]);
        if (pred(s2)) i += w, s = s2;
      }
    }
    return i + 1;
  }
  // min i s.t. !comp(sum(i), x)
  template <class Comp = less<value_type>>
  int lower_bound(value_type x, Comp comp = Comp()) const {
    return partition_point([&](value_type s) { return comp(s, x); });
  }

 private:
  M m;
  vector<value_type> data;
  static int lsb(int a) { return a & -a; }
};
#line 3 "main.cpp"

int n, p[5000];

void solve() {
  scanf("%d", &n);
  vector ab(n, vector<int>(n+1));
  fenwick_tree<addition<ll>> abc(n);
  rep(i, n) scanf("%d", &p[i]), p[i]--;
  ll ans = 0;
  rep(i, n) {
    ans += abc.sum(p[i], n);
    rep(b, i) {
      int d = ab[b][p[i]];
      if (d) abc.add(p[b], d);
    }
    rep(a, i) ab[i][p[a]]++;
    partial_sum(all(ab[i]), ab[i].begin());
  }
  printf("%lld\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}