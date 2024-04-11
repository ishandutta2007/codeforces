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
 * @brief 
 * @docs docs/graph/EulerianTrail.md
 */
template <bool directed> class EulerianTrail {
    void dfs(int v, int& s, int& t, int& check) {
        visited[v] = 1;
        if (directed) {
            if (abs(deg[v]) > 1)
                check = 0;
            else if (deg[v] == 1) {
                if (~s)
                    check = 0;
                else
                    s = v;
            }
        } else {
            if (deg[v] & 1) {
                if (s < 0)
                    s = v;
                else if (t < 0)
                    t = v;
                else
                    check = 0;
            }
        }
        for (int u : BG[v]) {
            if (visited[u]) continue;
            dfs(u, s, t, check);
        }
    }
    vector<int> go(int s) {
        stack<pair<int, int>> st;
        vector<int> ord;
        st.emplace(s, -1);
        while (!st.empty()) {
            int v = st.top().first;
            visited[v] = 1;
            if (G[v].empty()) {
                ord.emplace_back(st.top().second);
                st.pop();
            } else {
                auto e = G[v].back();
                G[v].pop_back();
                if (used[e.second]) continue;
                used[e.second] = 1;
                st.emplace(e);
            }
        }
        ord.pop_back();
        reverse(ord.begin(), ord.end());
        return ord;
    }

public:
    vector<vector<pair<int, int>>> G;
    vector<vector<int>> BG;
    vector<pair<int, int>> es;
    vector<int> used, visited, deg;
    EulerianTrail(int n) : G(n), BG(n), visited(n, 0), deg(n, 0) {}
    void add_edge(int u, int v) {
        int m = es.size();
        es.emplace_back(u, v);
        used.emplace_back(0);
        BG[u].emplace_back(v);
        BG[v].emplace_back(u);
        G[u].emplace_back(v, m);
        deg[u]++;
        if (directed)
            --deg[v];
        else
            G[v].emplace_back(u, m), deg[v]++;
    }
    vector<vector<int>> build() {
        for (int i = 0; i < (int)G.size(); i++) {
            if (directed && deg[i] != 0) return {};
            if (!directed && (deg[i] & 1)) return {};
        }
        vector<vector<int>> res;
        for (int i = 0; i < (int)G.size(); i++) {
            if (G[i].empty() || visited[i]) continue;
            res.emplace_back(go(i));
        }
        return res;
    }
    vector<vector<int>> build_semi() {
        vector<vector<int>> res;
        for (int i = 0; i < (int)G.size(); i++) {
            if (visited[i]) continue;
            int s = -1, t = -1, check = 1;
            dfs(i, s, t, check);
            if (!check) return {};
            res.emplace_back(go(~s ? s : i));
            if (res.back().empty()) res.pop_back();
        }
        return res;
    }
    pair<int, int> operator[](int i) { return es[i]; }
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
    int n, k;
    cin >> n >> k;

    if (k == 1) {
        for (int i = 0; i < n; i++) cout << 'a';
        cout << '\n';
        return 0;
    }

    EulerianTrail<true> ET(k);
    vector<int> to;
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int nj = (j + i) % k;
            ET.add_edge(j, nj);
            to.emplace_back(nj);
        }
    }

    auto V = ET.build();
    auto res = V[0];
    vector<int> path;
    assert(V.size() == 1);
    path.emplace_back(0);
    path.emplace_back(0);
    vector<bool> check(26, false);
    check[0] = true;
    for (int& e : res) {
        path.emplace_back(to[e]);
        if (!check[path.back()]) {
            path.emplace_back(path.back());
            check[path.back()] = true;
        }
    }
    path.pop_back();

    string ans = "";
    while (ans.size() < n) {
        for (int& x : path) {
            ans += char('a' + x);
        }
    }
    while (ans.size() > n) ans.pop_back();

    cout << ans << '\n';
    return 0;
}