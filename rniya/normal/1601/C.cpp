#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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

template <int i, typename T> void print_tuple(ostream&, const T&) {}
template <int i, typename T, typename H, class... Args> void print_tuple(ostream& os, const T& t) {
    if (i) os << ',';
    os << get<i>(t);
    print_tuple<i + 1, T, Args...>(os, t);
}
template <typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) {
    os << '{';
    print_tuple<0, tuple<Args...>, Args...>(os, t);
    return os << '}';
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

int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int botbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(long long t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }

template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}
template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
}

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

template <typename Monoid, typename OperatorMonoid, typename F, typename G, typename H> struct LazySegmentTree {
    LazySegmentTree(int n, const F f, const G g, const H h, const Monoid& e, const OperatorMonoid& id)
        : n(n), f(f), g(g), h(h), e(e), id(id) {
        size = 1;
        height = 0;
        while (size < n) size <<= 1, height++;
        data.assign(size << 1, e);
        lazy.assign(size << 1, id);
    }

    void set(int k, Monoid x) {
        assert(0 <= k && k < n);
        data[k + size] = x;
    }

    void build() {
        for (int k = size - 1; k > 0; k--) {
            data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);
        }
    }

    void update(int a, int b, const OperatorMonoid& x) {
        assert(0 <= a && a <= b && b <= n);
        if (a == b) return;
        thrust(a += size);
        thrust(b += size - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = h(lazy[l], x), ++l;
            if (r & 1) --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a);
        recalc(b);
    }

    void set_val(int k, Monoid x) {
        assert(0 <= k && k < n);
        thrust(k += size);
        data[k] = x;
        lazy[k] = id;
        recalc(k);
    }

    Monoid query(int a, int b) {
        assert(0 <= a && a <= b && b <= n);
        if (a == b) return e;
        thrust(a += size);
        thrust(b += size - 1);
        Monoid L = e, R = e;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = f(L, apply(l++));
            if (r & 1) R = f(apply(--r), R);
        }
        return f(L, R);
    }

    Monoid operator[](int k) {
        thrust(k += size);
        return apply(k);
    }

    template <typename C> int find_first(int l, const C& check) {
        assert(0 <= l && l <= n);
        assert(!check(e));
        if (l == n) return n;
        Monoid L = e;
        if (l == 0) {
            if (check(f(L, apply(1)))) return find_subtree(1, check, L, false);
            return n;
        }
        thrust(l + size);
        int r = size;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                Monoid nxt = f(L, apply(l));
                if (check(nxt)) return find_subtree(l, check, L, false);
                L = nxt;
                l++;
            }
        }
        return n;
    }

    template <typename C> int find_last(int r, const C& check) {
        assert(0 <= r && r <= n);
        assert(!check(e));
        if (r == 0) return 0;
        Monoid R = e;
        if (r == n) {
            if (check(f(apply(1), R))) return find_subtree(1, check, R, true);
            return -1;
        }
        thrust(r + size - 1);
        int l = size;
        for (r += size; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                Monoid nxt = f(apply(--r), R);
                if (check(nxt)) return find_subtree(r, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }

private:
    int n, size, height;
    std::vector<Monoid> data;
    std::vector<OperatorMonoid> lazy;
    const F f;
    const G g;
    const H h;
    const Monoid e;
    const OperatorMonoid id;

    inline Monoid apply(int k) { return lazy[k] == id ? data[k] : g(data[k], lazy[k]); }

    inline void propagate(int k) {
        if (lazy[k] == id) return;
        lazy[k << 1 | 0] = h(lazy[k << 1 | 0], lazy[k]);
        lazy[k << 1 | 1] = h(lazy[k << 1 | 1], lazy[k]);
        data[k] = apply(k);
        lazy[k] = id;
    }

    inline void thrust(int k) {
        for (int i = height; i > 0; i--) propagate(k >> i);
    }

    inline void recalc(int k) {
        while (k >>= 1) data[k] = f(apply(k << 1 | 0), apply(k << 1 | 1));
    }

    template <typename C> int find_subtree(int a, const C& check, Monoid& M, bool type) {
        while (a < size) {
            propagate(a);
            Monoid nxt = type ? f(apply(a << 1 | type), M) : f(M, apply(a << 1 | type));
            if (check(nxt))
                a = a << 1 | type;
            else
                M = nxt, a = (a << 1 | 1) - type;
        }
        return a - size;
    }
};

/**
 * @brief Lazy Segment Tree
 * @docs docs/datastructure/LazySegmentTree.md
 */

template <typename T> std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    std::map<T, int> res;
    for (size_t i = 0; i < v.size(); i++) res[v[i]] = i;
    return res;
}

/**
 * @brief compress ()
 */

template <typename T> struct BinaryIndexedTree {
    BinaryIndexedTree(int n) : n(n), data(n) {}

    void add(int k, T x) {
        assert(0 <= k && k < n);
        for (k++; k <= n; k += k & -k) data[k - 1] += x;
    }

    T query(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return sum(r) - sum(l);
    }

    T operator[](int i) const { return query(i, i + 1); }

    int lower_bound(T x) const {
        if (x <= 0) return 0;
        int cur = 0, k = 1;
        while (k < n) k <<= 1;
        for (; k > 0; k >>= 1) {
            if (cur + k <= n && data[cur + k - 1] < x) {
                x -= data[cur + k - 1];
                cur += k;
            }
        }
        return cur;
    }
    int upper_bound(T x) const { return lower_bound(x + 1); }

private:
    int n;
    std::vector<T> data;

    T sum(int r) const {
        T res = 0;
        for (; r > 0; r -= r & -r) res += data[r - 1];
        return res;
    }
};

/**
 * @brief Binary Indexd Tree (Fenwick Tree)
 * @docs docs/datastructure/BinaryIndexedTree.md
 */

const int INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    cin >> a >> b;

    vector<int> c;
    for (int& x : a) c.emplace_back(x);
    for (int& x : b) c.emplace_back(x);
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for (int& x : a) x = lower_bound(c.begin(), c.end(), x) - c.begin();
    for (int& x : b) x = lower_bound(c.begin(), c.end(), x) - c.begin();
    int sz = c.size();
    vector<int> cnt(sz, 0);
    for (int& x : b) cnt[x]++;
    // if (n == 1000000 and a[0] > 100000) return;
    vector<vector<int>> pos(sz);
    for (int i = 0; i < n; i++) pos[a[i]].emplace_back(i);
    auto f = [](int a, int b) { return min(a, b); };
    auto g = [](int a, int b) { return a + b; };
    LazySegmentTree<int, int, decltype(f), decltype(g), decltype(g)> seg(n + 1, f, g, g, INF, 0);
    for (int i = 0; i <= n; i++) seg.set(i, i);
    seg.build();

    ll ans = 0;
    int cur = 0;
    BinaryIndexedTree<int> BIT(sz);
    for (int i = 0; i < n; i++) {
        ans += BIT.query(a[i] + 1, sz);
        BIT.add(a[i], 1);
    }

    for (int i = 0; i < sz; i++) {
        for (int& v : pos[i]) seg.update(v + 1, n + 1, -1);
        if (cnt[i] > 0) ans += ll(seg.query(0, n + 1)) * cnt[i];
        for (int& v : pos[i]) seg.update(0, v + 1, 1);
        cur++;
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (; t--;) solve();
    return 0;
}