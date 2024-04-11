#define LOCAL
#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
typedef long long ll;
typedef __int128_t i128;
typedef unsigned int uint;
typedef unsigned long long ull;
#define ALL(x) (x).begin(), (x).end()

template <typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (T& x : v) is >> x;
    return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <typename T, typename U, typename V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t) {
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';
    return os;
}
template <typename T, typename U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U, V, W>& t) {
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) << ')';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const unordered_set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const deque<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}

void debug_out() { cerr << '\n'; }
template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {
    cerr << head;
    if (sizeof...(Tail) > 0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...)                                                                   \
    cerr << " ";                                                                     \
    cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n'; \
    cerr << " ";                                                                     \
    debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }
template <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }

template <class T1, class T2> inline bool chmin(T1& a, T2 b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2> inline bool chmax(T1& a, T2 b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion

/**
 * @brief Sparse table
 * @docs docs/datastructure/SparseTable.md
 */
template <typename T> struct SparseTable {
    typedef function<T(T, T)> F;
    vector<vector<T>> dat;
    vector<int> lookup;
    const F f;
    SparseTable(F f) : f(f) {}
    void build(const vector<T>& v) {
        int n = v.size(), h = 1;
        while ((1 << h) <= n) h++;
        dat.assign(h, vector<T>(n));
        lookup.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) lookup[i] = lookup[i >> 1] + 1;
        for (int j = 0; j < n; j++) dat[0][j] = v[j];
        for (int i = 1, mask = 1; i < h; i++, mask <<= 1) {
            for (int j = 0; j < n; j++) {
                dat[i][j] = f(dat[i - 1][j], dat[i - 1][min(j + mask, n - 1)]);
            }
        }
    }
    T query(int a, int b) {
        int d = lookup[b - a];
        return f(dat[d][a], dat[d][b - (1 << d)]);
    }
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
const long long MOD = 1000000007;
// const long long MOD = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, s, l;
    cin >> n >> s >> l;
    vector<int> a(n);
    cin >> a;

    SparseTable<int> ST1([](int a, int b) { return max(a, b); }), ST2([](int a, int b) { return min(a, b); });
    ST1.build(a);
    ST2.build(a);

    auto f = [](int a, int b) { return min(a, b); };
    LazySegmentTree<int, int> seg(n + 1, f, f, f, INF, INF);
    seg.set_val(0, 0);
    for (int i = 0; i < n; i++) {
        int lb = i + l - 1, ub = n + 1;
        while (ub - lb > 1) {
            int mid = (ub + lb) >> 1;
            int M = ST1.query(i, mid), m = ST2.query(i, mid);
            (M - m > s ? ub : lb) = mid;
        }
        seg.update(i + l, ub, seg[i] + 1);
    }
    // for (int j = 0; j <= n; j++) cerr << seg[j] << (j == n ? '\n' : ' ');

    int ans = seg[n];
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}