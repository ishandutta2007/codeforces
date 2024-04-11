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
 * @brief UnionFind
 * @docs docs/datastructure/UnionFind.md
 */
struct UnionFind {
    int num;
    vector<int> par, rank, dp1, dp2;
    UnionFind(int n) : num(n), par(n), rank(n, 1), dp1(n), dp2(n) { iota(par.begin(), par.end(), 0); }
    int root(int x) { return (par[x] == x ? x : par[x] = root(par[x])); }
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        par[y] = x;
        rank[x] += rank[y];
        dp1[x] = max(dp1[x], max(dp1[y], dp2[x] + dp2[y] + 1));
        dp2[x] = max(dp1[x] / 2, dp1[x] - dp1[x] / 2);
        num--;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return rank[root(x)]; }
    int count() { return num; }
    int operator[](int x) { return root(x); }
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> G(n);
    UnionFind UF(n);
    for (; m--;) {
        int a, b;
        cin >> a >> b;
        UF.merge(--a, --b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    {
        vector<int> dp(n, INF);
        auto dfs = [&](auto self, int v, int p, int d, vector<int>& comp) -> void {
            dp[v] = d;
            comp.emplace_back(v);
            for (int& u : G[v]) {
                if (u == p) continue;
                self(self, u, v, d + 1, comp);
            }
        };
        auto calc = [&](int v) {
            vector<int> comp;
            dfs(dfs, v, -1, 0, comp);
            int nxt = v;
            for (int& u : comp) {
                if (dp[nxt] < dp[u]) {
                    nxt = u;
                }
            }
            comp.clear();
            dfs(dfs, nxt, -1, 0, comp);
            int diam = 0;
            for (int& u : comp) diam = max(diam, dp[u]);
            for (int& u : comp) {
                UF.dp1[u] = diam;
                UF.dp2[u] = max(diam / 2, diam - diam / 2);
            }
        };

        for (int i = 0; i < n; i++) {
            if (dp[i] < INF) continue;
            calc(i);
        }
    }

    for (; q--;) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            cout << UF.dp1[UF[--x]] << '\n';
        } else {
            int x, y;
            cin >> x >> y;
            UF.merge(--x, --y);
        }
    }
    return 0;
}