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

template <typename Monoid, typename F> struct SegmentTree {
    SegmentTree(int n, const F f, const Monoid& e) : n(n), f(f), e(e) {
        size = 1;
        while (size < n) size <<= 1;
        data.assign(size << 1, e);
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

    void update(int k, Monoid x) {
        assert(0 <= k && k < n);
        k += size;
        data[k] = x;
        while (k >>= 1) data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);
    }

    void add(int k, Monoid x) {
        assert(0 <= k && k < n);
        k += size;
        data[k] += x;
        while (k >>= 1) data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);
    }

    Monoid query(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        Monoid L = e, R = e;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = f(L, data[l++]);
            if (r & 1) R = f(data[--r], R);
        }
        return f(L, R);
    }

    Monoid all_prod() const { return data[1]; }

    Monoid operator[](const int& k) const { return data[k + size]; }

    template <typename C> int find_first(int l, const C& check) {
        assert(0 <= l && l <= n);
        assert(!check(e));
        if (l == n) return n;
        Monoid L = e;
        if (l == 0) {
            if (check(f(L, data[1]))) return find_subtree(1, check, L, false);
            return n;
        }
        int r = size;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                Monoid nxt = f(L, data[l]);
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
            if (check(f(data[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int l = size;
        for (r += size; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                Monoid nxt = f(data[--r], R);
                if (check(nxt)) return find_subtree(r, check, R, false);
                R = nxt;
            }
        }
        return -1;
    }

private:
    int n, size;
    std::vector<Monoid> data;
    const F f;
    const Monoid e;

    template <typename C> int find_subtree(int a, const C& check, Monoid& M, bool type) {
        while (a < size) {
            Monoid nxt = type ? f(data[a << 1 | type], M) : f(M, data[a << 1 | type]);
            if (check(nxt))
                a = a << 1 | type;
            else
                M = nxt, a = (a << 1 | 1) - type;
        }
        return a - size;
    }
};

/**
 * @brief Segment Tree
 * @docs docs/datastructure/SegmentTree.md
 */

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX_S = 500010;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    vector<int> c(n);
    cin >> c;

    bitset<MAX_S> dp, ndp;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        ndp |= dp;
        ndp |= dp << c[i];
        swap(dp, ndp);
        ndp.reset();
    }

    auto f = [](int a, int b) { return min(a, b); };
    SegmentTree<int, decltype(f)> seg(MAX_S, f, INF);
    seg.update(0, 0);

    int a = 0, b = 0;
    for (int i = 1; i < MAX_S; i++) {
        if (!dp[i]) continue;
        int nxt = seg.query(max(0, i - d), i) + 1;
        if (nxt < seg[i]) {
            seg.update(i, nxt);
            a = i, b = nxt;
        }
    }

    cout << a << ' ' << b << '\n';
    return 0;
}