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
 * @brief Cycle Detection
 * @docs docs/graph/CycleDetection.md
 */
template <bool directed> struct CycleDetection {
    vector<vector<int>> G;
    vector<int> seen, finished;
    stack<int> hist;
    int pos;
    CycleDetection(int n) : G(n), seen(n, 0), finished(n, 0), pos(-1) {}
    void add_edge(int u, int v) { G[u].emplace_back(v); }
    void dfs(int v, int p) {
        seen[v] = 1;
        hist.emplace(v);
        for (int u : G[v]) {
            if (!directed && u == p) continue;
            if (finished[u]) continue;
            if (seen[u] && !finished[u]) {
                pos = u;
                return;
            }
            dfs(u, v);
            if (~pos) return;
        }
        finished[v] = 1;
        hist.pop();
    }
    vector<int> build() {
        for (int v = 0; v < (int)G.size(); v++) {
            if (!seen[v]) dfs(v, -1);
            if (~pos) break;
        }
        vector<int> res;
        while (!hist.empty()) {
            int t = hist.top();
            hist.pop();
            res.emplace_back(t);
            if (t == pos) break;
        }
        return res;
    }
};

/**
 * @brief Topological Sort
 * @docs docs/graph/TopologicalSort.md
 */
struct TopologicalSort {
    vector<vector<int>> G;
    vector<int> seen, order;
    TopologicalSort(int n) : G(n), seen(n) {}
    void add_edge(int u, int v) { G[u].emplace_back(v); }
    void dfs(int v) {
        seen[v] = 1;
        for (int u : G[v]) {
            if (!seen[u]) dfs(u);
        }
        order.emplace_back(v);
    }
    vector<int> build() {
        for (int i = 0; i < (int)G.size(); i++) {
            if (!seen[i]) dfs(i);
        }
        reverse(order.begin(), order.end());
        return order;
    }
    int operator[](int i) { return order[i]; }
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> P(n), S(m);
    vector<int> mt(m);
    for (int i = 0; i < n; i++) cin >> P[i];
    for (int i = 0; i < m; i++) cin >> S[i] >> mt[i], mt[i]--;

    auto ctoi = [](char c) {
        if (c == '_') return 26;
        return c - 'a';
    };
    auto hash = [&](string s) {
        int res = 0;
        for (int i = 0; i < k; i++) (res *= 27) += ctoi(s[i]);
        return res;
    };

    vector<int> pattern(1000010, -1);
    for (int i = 0; i < n; i++) pattern[hash(P[i])] = i;
    CycleDetection<true> CD(n);
    TopologicalSort TS(n);
    for (int i = 0; i < m; i++) {
        bool sat = false;
        vector<int> other;
        for (int mask = 0; mask < (1 << k); mask++) {
            string t = S[i];
            for (int j = 0; j < k; j++) {
                if (mask >> j & 1) {
                    t[j] = '_';
                }
            }
            int find = pattern[hash(t)];
            if (find < 0) continue;
            if (find == mt[i])
                sat = true;
            else
                other.emplace_back(find);
        }
        if (!sat) {
            cout << "NO" << '\n';
            return 0;
        }
        for (int v : other) {
            CD.add_edge(mt[i], v);
            TS.add_edge(mt[i], v);
        }
    }

    if (!CD.build().empty()) {
        cout << "NO" << '\n';
        return 0;
    }

    TS.build();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[i] = TS[i] + 1;

    cout << "YES" << '\n';
    cout << ans << '\n';
    return 0;
}