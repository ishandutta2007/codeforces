#line 1 "main.cpp"
#define _GLIBCXX_DEBUG
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
template <class T>
auto ndvec(size_t n, T&& x) { return vector(n, forward<T>(x)); }
template <class... Ts>
auto ndvec(size_t n, Ts&&... xs) { return vector(n, forward<Ts>(xs)...); }
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
#line 3 "lib/ds/sparse_table.hpp"

template <class M>
class sparse_table {
 public:
  using value_type = typename M::type;
  sparse_table() = default;
  sparse_table(vector<value_type> v, M m = M()) : m(m), data({move(v)}) {
    int n = data[0].size();
    lg.resize(n + 1);
    rep2(i, 2, n + 1) lg[i] = lg[i / 2] + 1;
    data.resize(lg[n] + 1);
    rep(t, lg[n]) {
      int w = 1 << t;
      data[t + 1].resize(n - w * 2 + 1);
      rep(i, n - w * 2 + 1) data[t + 1][i] = m.op(data[t][i], data[t][i + w]);
    }
  }
  template <class It>
  sparse_table(It first, It last, M m = M()) : sparse_table({first, last}, m) {}

  value_type prod(int l, int r) {
    if (l == r) return m.unit();
    int t = lg[r - l];
    return m.op(data[t][l], data[t][r - (1 << t)]);
  }
  value_type disjoint_prod(int l, int r) {
    value_type res = m.unit();
    while (l != r) {
      int t = lg[r - l];
      res = m.op(res, data[t][l]);
      l += 1 << t;
    }
    return res;
  }

 private:
  M m;
  vector<vector<value_type>> data;
  vector<int> lg;
};
#line 4 "main.cpp"

int h, w, n;
char S[2000001];
bool found[1000000];
int ans[2000001];

void solve() {
  scanf("%d%d", &h, &w);
  n = h * w;
  fill(S, S+n, '0');
  scanf("%s", S+n);
  fill(found, found+w, false);
  ans[0] = 0;
  rep(i, n) {
    ans[i+1] = ans[i];
    if (S[n+i] == '1') {
      ans[i+1] += !found[i % w];
      found[i % w] = true;
    }
  }
  sparse_table st(S, S+n*2, monoid(CONST(char(0)), bit_or<>{}));
  rep(z, w) {
    int now = 0;
    rep(i, h-1) now += st.prod(z+i*w, z+i*w+w) & 1;
    for (int l = z, r = z + n; r <= n * 2; l += w, r += w) {
      now += st.prod(r-w, r) & 1;
      ans[l] += now;
      now -= st.prod(l, l+w) & 1;
    }
  }
  rep(i, n) printf("%d%c", ans[i+1], " \n"[i==n-1]);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}