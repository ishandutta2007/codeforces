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
 * @brief Dual Segment Tree
 * @docs docs/datastructure/DualSegmentTree.md
 */
template <typename OperatorMonoid> struct DualSegmentTree {
    typedef function<OperatorMonoid(OperatorMonoid, OperatorMonoid)> H;
    int n, hi;
    H h;
    OperatorMonoid id1;
    vector<OperatorMonoid> laz;
    DualSegmentTree(int n_, H h, OperatorMonoid id1) : h(h), id1(id1) { init(n_); }
    void init(int n_) {
        n = 1, hi = 0;
        while (n < n_) n <<= 1, hi++;
        laz.assign(n << 1, id1);
    }
    inline void propagate(int k) {
        if (laz[k] == id1) return;
        laz[k << 1 | 0] = h(laz[k << 1 | 0], laz[k]);
        laz[k << 1 | 1] = h(laz[k << 1 | 1], laz[k]);
        laz[k] = id1;
    }
    inline void thrust(int k) {
        for (int i = hi; i; i--) propagate(k >> i);
    }
    void update(int a, int b, OperatorMonoid x) {
        if (a >= b) return;
        thrust(a += n);
        thrust(b += n - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) laz[l] = h(laz[l], x), ++l;
            if (r & 1) --r, laz[r] = h(laz[r], x);
        }
    }
    void set_val(int k, OperatorMonoid x) {
        thrust(k += n);
        laz[k] = x;
    }
    OperatorMonoid operator[](int k) {
        thrust(k += n);
        return laz[k];
    }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> G(n), H(n);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        G[--a].emplace_back(i);
    }
    for (int i = 1; i < n; i++) {
        int b;
        cin >> b;
        H[--b].emplace_back(i);
    }

    vector<int> IN(n), OUT(n);
    {
        int cur = 0;
        auto dfs = [&](auto self, int v) -> void {
            IN[v] = cur++;
            for (int& u : H[v]) self(self, u);
            OUT[v] = cur;
        };
        dfs(dfs, 0);
    }

    int ans = 0;
    {
        auto h = [](int a, int b) { return b != -2 ? b : a; };
        DualSegmentTree<int> seg(n, h, -2);
        set<int> s;

        auto dfs = [&](auto self, int v) -> void {
            auto itr = s.upper_bound(IN[v]);
            int par = -1;
            if (itr == s.end() || *itr >= OUT[v]) {
                par = seg[IN[v]];
                if (par >= 0) {
                    s.erase(s.find(IN[par]));
                    seg.update(IN[par], OUT[par], -1);
                }
                s.emplace(IN[v]);
                seg.update(IN[v], OUT[v], v);
            }
            ans = max(ans, int(s.size()));

            for (int& u : G[v]) self(self, u);
            if (s.count(IN[v])) {
                s.erase(s.find(IN[v]));
                seg.update(IN[v], OUT[v], -1);
            }
            if (par >= 0) {
                s.emplace(IN[par]);
                seg.update(IN[par], OUT[par], par);
            }
        };
        dfs(dfs, 0);
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