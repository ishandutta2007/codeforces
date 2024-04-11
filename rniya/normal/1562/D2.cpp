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

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

int ctoi(char c) { return c == '+' ? 1 : -1; }

void solve() {
    int n, q;
    cin >> n >> q;
    string S;
    cin >> S;

    vector<int> A(n), sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        A[i] = ctoi(S[i]) * (i & 1 ? -1 : 1);
        sum[i + 1] = sum[i] + A[i];
    }
    SegmentTree<int> seg1(
        n, [](int a, int b) { return max(a, b); }, -INF),
        seg2(
            n, [](int a, int b) { return min(a, b); }, INF);
    for (int i = 0; i < n; i++) {
        if (A[i] == 1)
            seg1.update(i, sum[i + 1]);
        else
            seg2.update(i, sum[i + 1]);
    }

    auto query = [&](int l, int r) -> vector<int> {
        int diff = sum[r] - sum[l];
        if (diff == 0) return {};
        vector<int> ans;
        if (!(diff & 1)) {
            if (diff > 0) {
                int val = sum[r];
                diff--;
                int pos = seg1.find_first(l, [&](int x) { return x >= val; });
                ans.emplace_back(pos + 1);
            } else {
                int val = sum[r];
                diff++;
                int pos = seg2.find_first(l, [&](int x) { return x <= val; });
                ans.emplace_back(pos + 1);
            }
        }
        if (diff > 0) {
            int val = sum[l] + (diff + 1) / 2;
            int pos = seg1.find_first(l, [&](int x) { return x >= val; });
            ans.emplace_back(pos + 1);
        } else {
            int val = sum[l] - (-diff + 1) / 2;
            int pos = seg2.find_first(l, [&](int x) { return x <= val; });
            ans.emplace_back(pos + 1);
        }
        return ans;
    };

    for (; q--;) {
        int l, r;
        cin >> l >> r;
        auto ans = query(--l, r);
        int sz = ans.size();
        cout << sz << '\n';
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (; t--;) solve();
    return 0;
}