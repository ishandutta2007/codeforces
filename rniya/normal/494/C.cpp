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
        if (a == b) return 0;
        int d = lookup[b - a];
        return f(dat[d][a], dat[d][b - (1 << d)]);
    }
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
    cout << fixed << setprecision(10);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;

    SparseTable<int> ST([](int a, int b) { return max(a, b); });
    ST.build(a);
    int Max = ST.query(0, n);

    struct seg {
        int l, r;
        double p;
        seg(int l, int r, double p) : l(l), r(r), p(p) {}
        bool operator<(const seg& rhs) const {
            if (r - l != rhs.r - rhs.l) return r - l > rhs.r - rhs.l;
            return p < rhs.p;
        }
    };
    auto inside = [](seg a, seg b) { return a.l <= b.l && b.r <= a.r; };

    vector<seg> S;
    for (int i = 0; i < q; i++) {
        int l, r;
        double p;
        cin >> l >> r >> p;
        S.emplace_back(--l, r, p);
    }

    S.emplace_back(0, n, -1);
    q++;
    sort(ALL(S));

    vector<vector<int>> G(q);
    vector<bool> included(q, false);
    for (int i = q - 1; i >= 0; i--) {
        for (int j = i + 1; j < q; j++) {
            if (included[j]) continue;
            if (inside(S[i], S[j])) {
                G[i].emplace_back(j);
                included[j] = true;
            }
        }
    }

    vector<vector<double>> dp(q, vector<double>(2 * q + 1, 1));
    auto dfs = [&](auto self, int v) -> void {
        sort(ALL(G[v]), [&](int a, int b) { return S[a].l < S[b].l; });
        int out_max = 0, L = S[v].l;
        for (int& u : G[v]) {
            chmax(out_max, ST.query(L, S[u].l));
            L = S[u].r;
            self(self, u);
            for (int i = 0; i <= 2 * q; i++) dp[v][i] *= dp[u][i];
        }
        chmax(out_max, ST.query(L, S[v].r));
        int res = Max + q - out_max;
        for (int i = res + 1; i <= 2 * q; i++) dp[v][i] = 0;
        double p = S[v].p;
        if (p < 0) return;
        for (int i = 0; i <= 2 * q; i++) dp[v][i] = dp[v][i] - (dp[v][i] - (i + 1 <= 2 * q ? dp[v][i + 1] : 0)) * p;
    };

    dfs(dfs, 0);
    double ans = 0;
    for (int j = 0; j <= q; j++) ans += (dp[0][j] - dp[0][j + 1]) * (Max + q - j);
    cout << ans << '\n';
    return 0;
}