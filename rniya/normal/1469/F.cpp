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

#include <cassert>
#include <vector>

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

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX = 1 << 18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    for (int& x : l) cin >> x;

    sort(l.rbegin(), l.rend());
    ll sum = 1;
    for (int& x : l) sum += x - 2;
    if (sum < k) {
        cout << -1 << '\n';
        return 0;
    }

    struct node {
        ll sum, cnt;
        node(int sum, int cnt) : sum(sum), cnt(cnt) {}
    };
    auto f = [](node a, node b) { return node(a.sum + b.sum, a.cnt + b.cnt); };
    auto g = [](node a, ll x) { return node(a.sum + x * a.cnt, a.cnt); };
    auto h = [](ll a, ll b) { return a + b; };
    LazySegmentTree<node, ll, decltype(f), decltype(g), decltype(h)> seg(MAX, f, g, h, node(0, 0), 0);
    for (int i = 0; i < MAX; i++) seg.set(i, node((i == 0 ? 1 : 0), 1));
    seg.build();
    int ans = INF, nxt = 0;
    sum = 1;

    for (int& x : l) {
        while (seg[nxt].sum == 0) nxt++;
        seg.update(nxt, nxt + 1, -1);
        int L = (x - 1) / 2, R = x - 1 - L;
        seg.update(nxt + 2, nxt + 2 + L, 1);
        seg.update(nxt + 2, nxt + 2 + R, 1);
        sum += x - 2;
        if (sum < k) continue;
        assert(seg.query(0, nxt).sum == 0);
        int cand = seg.find_first(nxt, [&](node val) { return val.sum >= k; });
        ans = min(ans, cand);
    }

    cout << ans << '\n';
    return 0;
}