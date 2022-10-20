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
 * @brief Mo's Algorithm
 * @docs docs/other/Mo.md
 */
struct Mo {
    int sz;
    vector<int> left, right;
    Mo(int n) : sz((int)sqrt(n)) {}
    void insert(int l, int r) {
        left.emplace_back(l);
        right.emplace_back(r);
    }
    template <typename ADDL, typename ADDR, typename DELL, typename DELR, typename REM>
    void build(const ADDL& add_left,
               const ADDR& add_right,
               const DELL& del_left,
               const DELR& del_right,
               const REM& rem) {
        int q = left.size();
        vector<int> ord(q);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(),
             [&](int a, int b) { return (left[a] / sz != left[b] / sz ? left[a] < left[b] : right[a] < right[b]); });
        int l = 0, r = 0;
        for (int idx : ord) {
            while (l > left[idx]) add_left(--l);
            while (r < right[idx]) add_right(r++);
            while (l < left[idx]) del_left(l++);
            while (r > right[idx]) del_right(--r);
            rem(idx);
        }
    }
    template <typename ADD, typename DEL, typename REM> void build(const ADD& add, const DEL& del, const REM& rem) {
        build(add, add, del, del, rem);
    }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX_C = 100010;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int& x : c) cin >> x, x--;
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    vector<int> IN(n), OUT(n), IN_inv(n);
    int time = 0;
    auto dfs = [&](auto self, int v, int p) -> void {
        IN[v] = time++;
        for (int& u : G[v]) {
            if (u == p) continue;
            self(self, u, v);
        }
        OUT[v] = time;
    };
    dfs(dfs, 0, -1);
    for (int i = 0; i < n; i++) IN_inv[IN[i]] = i;

    Mo mo(n);
    vector<int> K(m);
    for (int i = 0; i < m; i++) {
        int v;
        cin >> v >> K[i];
        v--;
        mo.insert(IN[v], OUT[v]);
    }

    vector<int> cnt(MAX_C, 0), kind(MAX_C, 0), ans(m);
    kind[0] = MAX_C;
    auto ADD = [&](int x) {
        int v = IN_inv[x], col = c[v];
        cnt[col]++;
        kind[cnt[col]]++;
    };
    auto DEL = [&](int x) {
        int v = IN_inv[x], col = c[v];
        kind[cnt[col]]--;
        cnt[col]--;
    };
    auto REM = [&](int idx) { ans[idx] = kind[K[idx]]; };

    mo.build(ADD, DEL, REM);
    for (int& x : ans) cout << x << '\n';
    return 0;
}