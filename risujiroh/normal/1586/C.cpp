using namespace std;

#ifndef OJ
#define OJ 1
#define NDEBUG
#endif

#include <bits/stdc++.h>
#include <x86intrin.h>


#include <algorithm>
#include <cassert>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder


#define INC_DEC(op) \
  template <class T> vector<T>& operator op(vector<T>& v) { \
    for (T & e : v) op e; \
    return v; \
  } \
  template <class T> vector<T>&& operator op(vector<T>&& v) { return move(op v); } \
  template <class T> enable_if_t<__is_tuple_like<T>{}, T&&> operator op(T&& t) { \
    apply([](auto&... es) { (..., op es); }, t); \
    return forward<T>(t); \
  }
INC_DEC(++)
INC_DEC(--)
#undef INC_DEC
template <class T> istream& operator>>(istream& i, vector<T>& v) {
  for (T& e : v) i >> e;
  return i;
}
template <class T> enable_if_t<__is_tuple_like<T>{}, istream&> operator>>(istream& i, T& t) {
  apply([&](auto&... es) { (i >> ... >> es); }, t);
  return i;
}
template <class T> ostream& operator<<(ostream& o, const vector<T>& v) {
  string_view s;
  for (const T& e : v) o << exchange(s, " ") << e;
  return o;
}
template <class T> enable_if_t<__is_tuple_like<T>{}, ostream&> operator<<(ostream& o, const T& t) {
  string_view s;
  apply([&](const auto&... es) { (..., (o << exchange(s, " ") << es)); }, t);
  return o;
}
template <class T = int, class... Args> T input(Args&&... args) {
  T r(forward<Args>(args)...);
  cin >> r;
  return r;
}
template <class... Ts> enable_if_t<sizeof...(Ts) >= 2, tuple<Ts...>> input() {
  tuple<Ts...> r;
  apply([](auto&... es) { (cin >> ... >> es); }, r);
  return r;
}

using i64 = long long;

template <class F> struct Fix : F {
  explicit Fix(F f) : F(move(f)) {}
  template <class... Args> decltype(auto) operator()(Args&&... args) const {
    return F::operator()(ref(*this), forward<Args>(args)...);
  }
};

template <class R> int sz(const R& r) { return int(size(r)); }
template <class I> int sz(I b, I e) { return int(distance(b, e)); }
template <class T> T div_floor(T x, T y) { return assert(y), x / y - ((x ^ y) < 0 && x % y); }
template <class T> T div_ceil(T x, T y) { return assert(y), x / y + ((x ^ y) >= 0 && x % y); }
template <class T, class U = T> bool chmin(T& x, U&& y) { return y < x ? x = forward<U>(y), true : false; }
template <class T, class U = T> bool chmax(T& x, U&& y) { return x < y ? x = forward<U>(y), true : false; }

mt19937_64 rng(_rdtsc() * OJ);
template <class T> T rnd(T x, T y) { return uniform_int_distribution(x, y)(rng); }

#define fn(...) [&]([[maybe_unused]] auto&& _) -> decltype(auto) { return (__VA_ARGS__); }
#define dump(...) OJ ? cerr : cerr << __LINE__ << ": [" #__VA_ARGS__ "]: " << __VA_ARGS__ << '\n'

auto op = [](int x, int y) { return max(x, y); };
auto e = [] { return -1; };

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  for (int h, w; cin >> h >> w;) {
    vector s(h + 1, string(w, '.'));
    for (int i : views::iota(1, h + 1)) cin >> s[i];
    vector f(h + 1, vector<int>(w));
    for (int i : views::iota(0, h + 1)) {
      for (int j : views::iota(0, w)) {
        f[i][j] = j;
        if (i && s[i - 1][j] == '.') chmin(f[i][j], f[i - 1][j]);
        if (j && s[i][j - 1] == '.') chmin(f[i][j], f[i][j - 1]);
      }
      dump(pair{i, f[i]});
    }
    atcoder::segtree<int, op, e> seg(w);
    for (int j : views::iota(0, w)) {
      int max = -1;
      for (int i : views::iota(0, h + 1)) chmax(max, f[i][j]);
      seg.set(j, max);
    }
    int q = input();
    vector<int> l(q), r(q);
    for (int i : views::iota(0, q)) cin >> l[i] >> r[i];
    --l;
    for (int i : views::iota(0, q)) {
      cout << (seg.prod(l[i], r[i]) <= l[i] ? "YES\n" : "NO\n");
    }
  }
}