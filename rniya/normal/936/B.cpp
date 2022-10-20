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
 * @brief Strongly Connected Components
 * @docs docs/graph/StronglyConnectedComponents.md
 */
struct StronglyConnectedComponents {
    vector<vector<int>> G, rG, C, T;
    vector<int> vs, cmp, used;
    StronglyConnectedComponents(int n) : G(n), rG(n), cmp(n), used(n) {}
    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }
    void dfs(int v) {
        used[v] = 1;
        for (int u : G[v])
            if (!used[u]) dfs(u);
        vs.emplace_back(v);
    }
    void rdfs(int v, int k) {
        used[v] = 1;
        cmp[v] = k;
        C[k].emplace_back(v);
        for (int u : rG[v])
            if (!used[u]) rdfs(u, k);
    }
    int build() {
        int n = G.size();
        for (int i = 0; i < n; i++)
            if (!used[i]) dfs(i);
        fill(used.begin(), used.end(), 0);
        int k = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (!used[vs[i]]) {
                C.emplace_back(), T.emplace_back();
                rdfs(vs[i], k++);
            }
        }
        for (int v = 0; v < n; v++) {
            for (int u : G[v]) {
                if (cmp[v] != cmp[u]) {
                    T[cmp[v]].emplace_back(cmp[u]);
                }
            }
        }
        for (int i = 0; i < k; i++) {
            sort(T[i].begin(), T[i].end());
            T[i].erase(unique(T[i].begin(), T[i].end()), T[i].end());
        }
        return k;
    }
    int operator[](int i) const { return cmp[i]; }
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
    int n, m;
    cin >> n >> m;
    StronglyConnectedComponents SCC(n);
    vector<vector<int>> rG(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        for (; c--;) {
            int a;
            cin >> a;
            SCC.add_edge(i, --a);
            rG[a].emplace_back(i);
        }
    }
    int s;
    cin >> s;
    s--;

    auto& G = SCC.G;
    int k = SCC.build();
    vector<vector<int>> dp(n, vector<int>(2, -2));
    queue<pair<int, int>> que;
    for (int i = 0; i < n; i++) {
        if (G[i].size() == 0) {
            dp[i][0] = -1;
            que.emplace(i, 0);
        }
    }

    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        int v = p.first, x = p.second;
        for (int& u : rG[v]) {
            if (dp[u][x ^ 1] != -2) continue;
            dp[u][x ^ 1] = v;
            que.emplace(u, x ^ 1);
        }
    }

    if (dp[s][1] != -2) {
        vector<int> ans;
        for (int cur = 1; s != -1; s = dp[s][cur], cur ^= 1) {
            ans.emplace_back(s + 1);
        }
        cout << "Win" << '\n';
        cout << ans << '\n';
        return 0;
    }

    vector<bool> reach(k, false);
    reach[SCC[s]] = true;
    auto& T = SCC.T;
    for (int i = 0; i < k; i++) {
        if (!reach[i]) continue;
        if (SCC.C[i].size() > 1) {
            cout << "Draw" << '\n';
            return 0;
        }
        for (int& u : T[i]) reach[u] = true;
    }

    cout << "Lose" << '\n';
    return 0;
}