#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename Monoid, typename OperatorMonoid> struct LazySegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, OperatorMonoid)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

    int sz, height;
    vector<Monoid> data;
    vector<OperatorMonoid> lazy;
    const F f;
    const G g;
    const H h;
    const Monoid M0;
    const OperatorMonoid O0;

    constexpr LazySegmentTree(const F &f, const G &g, const H &h,
                              const Monoid &M0, const OperatorMonoid &O0)
        : f(f), g(g), h(h), M0(M0), O0(O0) {}

    constexpr void init(const int &n) {
        sz = 1;
        height = 0;
        while(sz < n)
            sz <<= 1, height++;
        data.assign(sz << 1, M0);
        lazy.assign(sz << 1, O0);
    }

    constexpr void build(const vector<Monoid> &v) {
        int n = v.size();
        init(n);
        for(int i = 0; i < n; i++)
            data[sz + i] = v[i];
        for(int i = sz - 1; i; i--)
            data[i] = f(data[i << 1], data[i << 1 | 1]);
    }

    constexpr Monoid reflect(const int &k) const {
        return lazy[k] == O0 ? data[k] : g(data[k], lazy[k]);
    }

    constexpr void propagate(const int &k) {
        if(lazy[k] == O0) return;
        lazy[k << 1] = h(lazy[k << 1], lazy[k]);
        lazy[k << 1 | 1] = h(lazy[k << 1 | 1], lazy[k]);
        data[k] = reflect(k);
        lazy[k] = O0;
    }

    constexpr void thrust(const int &k) {
        for(int i = height; i; i--)
            propagate(k >> i);
    }

    constexpr void thrust(const int &l, const int &r) {
        if(l == r) {
            thrust(l);
            return;
        }
        int Xor = l ^ r, i = height;
        for(; !(Xor >> i); i--)
            propagate(l >> i);
        for(; i; i--) {
            propagate(l >> i);
            propagate(r >> i);
        }
    }

    constexpr void recalc(int k) {
        while(k >>= 1)
            data[k] = f(reflect(k << 1), reflect(k << 1 | 1));
    }

    constexpr void recalc(int l, int r) {
        int Xor = l ^ r;
        while(Xor >>= 1) {
            l >>= 1;
            r >>= 1;
            data[l] = f(reflect(l << 1), reflect(l << 1 | 1));
            data[r] = f(reflect(r << 1), reflect(r << 1 | 1));
        }
        while(l >>= 1)
            data[l] = f(reflect(l << 1), reflect(l << 1 | 1));
    }

    constexpr void update(int a, int b, const OperatorMonoid &x) {
        if(a >= b) return;
        thrust(a += sz, b += sz - 1);
        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) lazy[l] = h(lazy[l], x), l++;
            if(r & 1) --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a, b);
    }

    constexpr void set_val(int a, const Monoid &x) {
        thrust(a += sz);
        data[a] = x;
        lazy[a] = O0;
        recalc(a);
    }

    constexpr Monoid query(int a, int b) {
        if(a >= b) return M0;
        thrust(a += sz, b += sz - 1);
        Monoid vl = M0, vr = M0;
        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) vl = f(vl, reflect(l++));
            if(r & 1) vr = f(reflect(--r), vr);
        }
        return f(vl, vr);
    }

    template <typename C>
    constexpr int find(const int &st, const C &check, Monoid &acc, const int &k,
                       const int &l, const int &r) {
        if(l + 1 == r) {
            acc = f(acc, reflect(k));
            return check(acc) ? k - sz : -1;
        }
        propagate(k);
        int m = (l + r) >> 1;
        if(m <= st) return find(st, check, acc, k << 1 | 1, m, r);
        if(st <= l && !check(f(acc, data[k]))) {
            acc = f(acc, data[k]);
            return -1;
        }
        int vl = find(st, check, acc, k << 1, l, m);
        if(~vl) return vl;
        return find(st, check, acc, k << 1 | 1, m, r);
    }

    template <typename C> constexpr int find(const int &st, const C &check) {
        Monoid acc = M0;
        return find(st, check, acc, 1, 0, sz);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> as(n), bs(m);
    for(int i = 0; i < n; i++)
        cin >> as[i];
    for(int i = 0; i < m; i++)
        cin >> bs[i];

    auto f = [](int a, int b) { return max(a, b); };
    auto g = [](int a, int b) { return a + b; };
    LazySegmentTree<int, int> seg(f, g, g, 0, 0);

    const int sz = 1 << 20;
    vector<int> x(sz, 0);
    for(int i = 0; i < n; i++)
        x[sz - as[i]]++;
    for(int i = 0; i < m; i++)
        x[sz - bs[i]]--;
    for(int i = 1; i < sz; i++)
        x[i] += x[i - 1];

    seg.build(x);

    int q;
    cin >> q;
    auto check = [](int d) { return d > 0; };
    for(int i = 0; i < q; i++) {
        int t, k, v;
        cin >> t >> k >> v;
        k--;
        if(t == 1) {
            seg.update(sz - as[k], sz, -1);
            as[k] = v;
            seg.update(sz - as[k], sz, 1);
        }
        if(t == 2) {
            seg.update(sz - bs[k], sz, 1);
            bs[k] = v;
            seg.update(sz - bs[k], sz, -1);
        }
        int pos = seg.find(0, check);
        cout << (pos < 0 ? pos : sz - pos) << "\n";
    }
    cout << flush;
    return 0;
}