#include <bits/stdc++.h>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
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

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int op(int x, int y) { return std::max(x, y); }
int e() { return -1; }

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> p(n);
  for (int& e : p) {
    cin >> e;
    --e;
  }

  vector<int> min_j(n, n);

  auto go = [&] {
    vector<int> nxt(n, n);
    {
      vector<int> s;
      for (int i = n; i--;) {
        while (!empty(s) && p[i] < p[s.back()]) {
          s.pop_back();
        }
        if (!empty(s)) {
          nxt[i] = s.back();
        }
        s.push_back(i);
      }
    }

    vector<int> prv(n, -1);
    {
      vector<int> s;
      for (int i = 0; i < n; ++i) {
        while (!empty(s) && p[s.back()] < p[i]) {
          s.pop_back();
        }
        if (!empty(s)) {
          prv[i] = s.back();
        }
        s.push_back(i);
      }
    }

    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
      order[n - p[i] - 1] = i;
    }

    atcoder::segtree<int, op, e> seg(n);

    for (int i : order) {
      int j = seg.max_right(0, [&](int x) { return x <= nxt[i]; });
      min_j[i] = min(min_j[i], j);
      seg.set(i, prv[i]);
    }
  };

  go();
  for (int& e : p) {
    e = n - e - 1;
  }
  go();

  using i64 = long long;

  i64 ans = 0;

  for (int i = n; i--;) {
    if (i + 1 < n) {
      min_j[i] = min(min_j[i], min_j[i + 1]);
    }
    ans += min_j[i] - i;
  }

  cout << ans << '\n';
}