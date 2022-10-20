#include <bits/stdc++.h>
using namespace std;

/**
 * @brief modint
 * @docs docs/modulo/modint.md
 */
template <uint32_t mod> class modint {
    using i64 = int64_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

public:
    u32 v;
    constexpr modint(const i64 x = 0) noexcept : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}
    constexpr u32& value() noexcept { return v; }
    constexpr const u32& value() const noexcept { return v; }
    constexpr modint operator+(const modint& rhs) const noexcept { return modint(*this) += rhs; }
    constexpr modint operator-(const modint& rhs) const noexcept { return modint(*this) -= rhs; }
    constexpr modint operator*(const modint& rhs) const noexcept { return modint(*this) *= rhs; }
    constexpr modint operator/(const modint& rhs) const noexcept { return modint(*this) /= rhs; }
    constexpr modint& operator+=(const modint& rhs) noexcept {
        v += rhs.v;
        if (v >= mod) v -= mod;
        return *this;
    }
    constexpr modint& operator-=(const modint& rhs) noexcept {
        if (v < rhs.v) v += mod;
        v -= rhs.v;
        return *this;
    }
    constexpr modint& operator*=(const modint& rhs) noexcept {
        v = (u64)v * rhs.v % mod;
        return *this;
    }
    constexpr modint& operator/=(const modint& rhs) noexcept { return *this *= rhs.pow(mod - 2); }
    constexpr modint pow(u64 exp) const noexcept {
        modint self(*this), res(1);
        while (exp > 0) {
            if (exp & 1) res *= self;
            self *= self;
            exp >>= 1;
        }
        return res;
    }
    constexpr modint& operator++() noexcept {
        if (++v == mod) v = 0;
        return *this;
    }
    constexpr modint& operator--() noexcept {
        if (v == 0) v = mod;
        return --v, *this;
    }
    constexpr modint operator++(int) noexcept {
        modint t = *this;
        return ++*this, t;
    }
    constexpr modint operator--(int) noexcept {
        modint t = *this;
        return --*this, t;
    }
    constexpr modint operator-() const noexcept { return modint(mod - v); }
    template <class T> friend constexpr modint operator+(T x, modint y) noexcept { return modint(x) + y; }
    template <class T> friend constexpr modint operator-(T x, modint y) noexcept { return modint(x) - y; }
    template <class T> friend constexpr modint operator*(T x, modint y) noexcept { return modint(x) * y; }
    template <class T> friend constexpr modint operator/(T x, modint y) noexcept { return modint(x) / y; }
    constexpr bool operator==(const modint& rhs) const noexcept { return v == rhs.v; }
    constexpr bool operator!=(const modint& rhs) const noexcept { return v != rhs.v; }
    constexpr bool operator!() const noexcept { return !v; }
    friend istream& operator>>(istream& s, modint& rhs) noexcept {
        i64 v;
        rhs = modint{(s >> v, v)};
        return s;
    }
    friend ostream& operator<<(ostream& s, const modint& rhs) noexcept { return s << rhs.v; }
};

/**
 * @brief Segment Tree
 * @docs docs/datastructure/SegmentTree.md
 */
template <typename Monoid> struct SegmentTree {
    typedef function<Monoid(Monoid, Monoid)> F;
    int n;
    F f;
    Monoid id;
    vector<Monoid> dat;
    SegmentTree(int n_, F f, Monoid id) : f(f), id(id) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n <<= 1;
        dat.assign(n << 1, id);
    }
    void build(const vector<Monoid>& v) {
        for (int i = 0; i < (int)v.size(); i++) dat[i + n] = v[i];
        for (int i = n - 1; i; i--) dat[i] = f(dat[i << 1 | 0], dat[i << 1 | 1]);
    }
    void update(int k, Monoid x) {
        dat[k += n] = x;
        while (k >>= 1) dat[k] = f(dat[k << 1 | 0], dat[k << 1 | 1]);
    }
    Monoid query(int a, int b) {
        if (a >= b) return id;
        Monoid vl = id, vr = id;
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, dat[l++]);
            if (r & 1) vr = f(dat[--r], vr);
        }
        return f(vl, vr);
    }
    template <typename C> int find_subtree(int k, const C& check, Monoid& M, bool type) {
        while (k < n) {
            Monoid nxt = type ? f(dat[k << 1 | type], M) : f(M, dat[k << 1 | type]);
            if (check(nxt))
                k = k << 1 | type;
            else
                M = nxt, k = k << 1 | (type ^ 1);
        }
        return k - n;
    }
    // min i s.t. f(seg[a],seg[a+1],...,seg[i]) satisfy "check"
    template <typename C> int find_first(int a, const C& check) {
        Monoid L = id;
        if (a <= 0) {
            if (check(f(L, dat[1]))) return find_subtree(1, check, L, false);
            return -1;
        }
        int b = n;
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                Monoid nxt = f(L, dat[l]);
                if (check(nxt)) return find_subtree(l, check, L, false);
                L = nxt;
                l++;
            }
        }
        return -1;
    }
    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1]) satisfy "check"
    template <typename C> int find_last(int b, const C& check) {
        Monoid R = id;
        if (b >= n) {
            if (check(f(dat[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int a = n;
        for (int l = a, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                Monoid nxt = f(dat[--r], R);
                if (check(nxt)) return find_subtree(r, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
    Monoid operator[](int i) { return dat[i + n]; }
};

/**
 * @brief Lazy Segment Tree
 * @docs docs/datastructure/LazySegmentTree.md
 */
template <typename Monoid, typename OperatorMonoid> struct LazySegmentTree {
    typedef function<Monoid(Monoid, Monoid)> F;
    typedef function<Monoid(Monoid, OperatorMonoid)> G;
    typedef function<OperatorMonoid(OperatorMonoid, OperatorMonoid)> H;
    int n, hi;
    F f;
    G g;
    H h;
    Monoid id0;
    OperatorMonoid id1;
    vector<Monoid> dat;
    vector<OperatorMonoid> laz;
    LazySegmentTree(int n_, F f, G g, H h, Monoid id0, OperatorMonoid id1) : f(f), g(g), h(h), id0(id0), id1(id1) {
        init(n_);
    }
    void init(int n_) {
        n = 1, hi = 0;
        while (n < n_) n <<= 1, hi++;
        dat.assign(n << 1, id0);
        laz.assign(n << 1, id1);
    }
    void build(const vector<Monoid>& v) {
        for (int i = 0; i < (int)v.size(); i++) dat[i + n] = v[i];
        for (int i = n - 1; i; --i) dat[i] = f(dat[i << 1 | 0], dat[i << 1 | 1]);
    }
    inline Monoid reflect(int k) { return laz[k] == id1 ? dat[k] : g(dat[k], laz[k]); }
    inline void propagate(int k) {
        if (laz[k] == id1) return;
        laz[k << 1 | 0] = h(laz[k << 1 | 0], laz[k]);
        laz[k << 1 | 1] = h(laz[k << 1 | 1], laz[k]);
        dat[k] = reflect(k);
        laz[k] = id1;
    }
    inline void thrust(int k) {
        for (int i = hi; i; i--) propagate(k >> i);
    }
    inline void recalc(int k) {
        while (k >>= 1) dat[k] = f(reflect(k << 1 | 0), reflect(k << 1 | 1));
    }
    void update(int a, int b, OperatorMonoid x) {
        if (a >= b) return;
        thrust(a += n);
        thrust(b += n - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) laz[l] = h(laz[l], x), ++l;
            if (r & 1) --r, laz[r] = h(laz[r], x);
        }
        recalc(a);
        recalc(b);
    }
    void set_val(int k, Monoid x) {
        thrust(k += n);
        dat[k] = x, laz[k] = id1;
        recalc(k);
    }
    Monoid query(int a, int b) {
        if (a >= b) return id0;
        thrust(a += n);
        thrust(b += n - 1);
        Monoid vl = id0, vr = id0;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, reflect(l++));
            if (r & 1) vr = f(reflect(--r), vr);
        }
        return f(vl, vr);
    }
    template <typename C> int find_subtree(int k, const C& check, Monoid& M, bool type) {
        while (k < n) {
            propagate(k);
            Monoid nxt = type ? f(reflect(k << 1 | type), M) : f(M, reflect(k << 1 | type));
            if (check(nxt))
                k = k << 1 | type;
            else
                M = nxt, k = k << 1 | (type ^ 1);
        }
        return k - n;
    }
    // min i s.t. f(seg[a],seg[a+1],...,seg[i]) satisfy "check"
    template <typename C> int find_first(int a, const C& check) {
        Monoid L = id0;
        if (a <= 0) {
            if (check(f(L, reflect(1)))) return find_subtree(1, check, L, false);
            return -1;
        }
        thrust(a + n);
        int b = n;
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                Monoid nxt = f(L, reflect(l));
                if (check(nxt)) return find_subtree(l, check, L, false);
                L = nxt;
                l++;
            }
        }
        return -1;
    }
    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1]) satisfy "check"
    template <typename C> int find_last(int b, const C& check) {
        Monoid R = id0;
        if (b >= n) {
            if (check(f(reflect(1), R))) return find_subtree(1, check, R, true);
            return -1;
        }
        thrust(b + n - 1);
        int a = n;
        for (int l = a, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                Monoid nxt = f(reflect(--r), R);
                if (check(nxt)) return find_subtree(r, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
    Monoid operator[](int i) { return query(i, i + 1); }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
// const long long MOD = 1000000007;
const long long MOD = 998244353;

using mint = modint<MOD>;
struct node {
    mint a, b, c, d;  // a:b:c:d:
    node(mint a, mint b, mint c, mint d) : a(a), b(b), c(c), d(d) {}
};
struct ope {
    mint a, b;  // a:b:
    ope(mint a, mint b) : a(a), b(b) {}
    bool operator==(const ope& rhs) const { return a == rhs.a && b == rhs.b; }
};
using SEG = LazySegmentTree<node, ope>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    auto f = [](node a, node b) { return node(a.a + b.a, a.b + b.b, a.c + b.c, a.d + b.d); };
    auto g = [](node a, ope x) { return node(a.a + x.a * a.c, a.b + x.b * a.d, a.c, a.d); };
    auto h = [](ope a, ope b) { return ope(a.a + b.a, a.b + b.b); };
    vector<SEG> seg(2, SEG(N + 1, f, g, h, node(0, 0, 0, 0),
                           ope(0, 0)));  // ij
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            seg[j].set_val(i, node(0, 0, !(i & 1), i & 1));
        }
    }
    seg[0].set_val(0, node(1, 0, 1, 0));

    SegmentTree<int> nseg(
        N, [](int a, int b) { return min(a, b); }, INF);
    nseg.build(A);

    for (int i = 0; i < N; i++) {
        int l = nseg.find_last(i, [&](int x) { return x <= A[i]; }),
            r = nseg.find_first(i, [&](int x) { return x < A[i]; });
        if (r < 0) r = N;
        auto p = seg[0].query(l + 1, i + 1), q = seg[1].query(l + 1, i + 1);
        seg[0].update(i + 1, r + 1, ope(p.b * A[i], p.a * A[i]));
        seg[1].update(i + 1, r + 1, ope(q.b * A[i], q.a * A[i]));
        seg[0].update(i + 1, r + 1, ope(q.a * A[i], q.b * A[i]));
        seg[1].update(i + 1, r + 1, ope(p.a * A[i], p.b * A[i]));
    }

    auto even = seg[0][N], odd = seg[1][N];
    mint ans = even.a + even.b - odd.a - odd.b;
    cout << ans << '\n';
    return 0;
}