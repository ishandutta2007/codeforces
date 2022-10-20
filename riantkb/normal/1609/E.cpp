#pragma GCC optimize("O3")
#include<bits/stdc++.h>

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

using namespace std;
using P = pair<int, int>;

const int M = 1000000007;


struct node {
    int ll, lm, lr, mm, mr, rr;
    node() {
        ll = lm = lr = mm = mr = rr = 0;
    }
    node(int x) {
        ll = x == 2;
        lm = M;
        lr = x == 1;
        mm = M;
        mr = M;
        rr = x == 0;
    }
    int getmin() {
        return min({ ll, lm, lr, mm, mr, rr });
    }
};

node op(node a, node b) {
    node res;
    res.ll = a.ll + b.ll;
    res.lm = min({ a.lm + b.ll, a.lr + b.ll, a.lr + b.lm });
    res.lr = a.lr + b.lr;
    res.mm = min({ a.mm + b.ll, a.mr + b.ll, a.mr + b.lm, a.rr + b.ll, a.rr + b.lm, a.rr + b.mm });
    res.mr = min({ a.mr + b.lr, a.rr + b.lr, a.rr + b.mr });
    res.rr = a.rr + b.rr;
    return res;
}

node e() {
    return node();
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<node> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = node(s[i] - 'a');
    }

    atcoder::segtree<node, op, e> sg(v);

    for (int _ = 0; _ < q; ++_) {
        int i;
        char c;
        cin >> i >> c;
        --i;
        int x = c - 'a';
        sg.set(i, node(x));
        node res = sg.all_prod();

        cout << res.getmin() << '\n';
    }
    return 0;
}