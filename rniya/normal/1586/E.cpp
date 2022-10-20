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
#include <utility>
#include <vector>

struct HeavyLightDecomposition {
    std::vector<std::vector<int>> G;  // child of vertex v on heavy edge is G[v].front() if it is not parent of v

    HeavyLightDecomposition(int n)
        : G(n),
          n(n),
          time(0),
          par(n, -1),
          sub(n),
          dep(n, 0),
          head(n),
          tree_id(n, -1),
          vertex_id(n, -1),
          vertex_id_inv(n) {}

    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void build(std::vector<int> roots = {0}) {
        int tree_id_cur = 0;
        for (int& r : roots) {
            assert(0 <= r && r < n);
            dfs_sz(r);
            head[r] = r;
            dfs_hld(r, tree_id_cur++);
        }
        assert(time == n);
        for (int v = 0; v < n; v++) vertex_id_inv[vertex_id[v]] = v;
    }

    int idx(int v) const { return vertex_id[v]; }

    int la(int v, int k) {
        assert(0 <= v && v < n);
        assert(0 <= k && k <= dep[v]);
        while (1) {
            int u = head[v];
            if (vertex_id[v] - k >= vertex_id[u]) return vertex_id_inv[vertex_id[v] - k];
            k -= vertex_id[v] - vertex_id[u] + 1;
            v = par[u];
        }
    }

    int lca(int u, int v) const {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(tree_id[u] == tree_id[v]);
        for (;; v = par[head[v]]) {
            if (vertex_id[u] > vertex_id[v]) std::swap(u, v);
            if (head[u] == head[v]) return u;
        }
    }

    int distance(int u, int v) const {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(tree_id[u] == tree_id[v]);
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    template <typename F> void query_path(int u, int v, const F& f, bool vertex = false) const {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(tree_id[u] == tree_id[v]);
        int p = lca(u, v);
        for (auto& e : ascend(u, p)) f(e.second, e.first + 1);
        if (vertex) f(vertex_id[p], vertex_id[p] + 1);
        for (auto& e : descend(p, v)) f(e.first, e.second + 1);
    }

    template <typename F> void query_path_noncommutative(int u, int v, const F& f, bool vertex = false) const {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(tree_id[u] == tree_id[v]);
        int p = lca(u, v);
        for (auto& e : ascend(u, p)) f(e.first + 1, e.second);
        if (vertex) f(vertex_id[p], vertex_id[p] + 1);
        for (auto& e : descend(p, v)) f(e.first, e.second + 1);
    }

    template <typename F> void query_subtree(int u, const F& f, bool vertex = false) const {
        assert(0 <= u && u < n);
        f(vertex_id[u] + !vertex, vertex_id[u] + sub[u]);
    }

private:
    int n, time;
    std::vector<int> par,  // parent of vertex v
        sub,               // size of subtree whose root is v
        dep,               // distance bitween root and vertex v
        head,              // vertex that is the nearest to root on heavy path of vertex v
        tree_id,           // id of tree vertex v belongs to
        vertex_id,         // id of vertex v (consecutive on heavy paths)
        vertex_id_inv;     // vertex_id_inv[vertex_id[v]] = v

    void dfs_sz(int v) {
        sub[v] = 1;
        if (!G[v].empty() && G[v].front() == par[v]) std::swap(G[v].front(), G[v].back());
        for (int& u : G[v]) {
            if (u == par[v]) continue;
            par[u] = v;
            dep[u] = dep[v] + 1;
            dfs_sz(u);
            sub[v] += sub[u];
            if (sub[u] > sub[G[v].front()]) std::swap(u, G[v].front());
        }
    }

    void dfs_hld(int v, int tree_id_cur) {
        vertex_id[v] = time++;
        tree_id[v] = tree_id_cur;
        for (int& u : G[v]) {
            if (u == par[v]) continue;
            head[u] = (u == G[v][0] ? head[v] : u);
            dfs_hld(u, tree_id_cur);
        }
    }

    std::vector<std::pair<int, int>> ascend(int u, int v) const {  // [u, v), v is ancestor of u
        std::vector<std::pair<int, int>> res;
        while (head[u] != head[v]) {
            res.emplace_back(vertex_id[u], vertex_id[head[u]]);
            u = par[head[u]];
        }
        if (u != v) res.emplace_back(vertex_id[u], vertex_id[v] + 1);
        return res;
    }

    std::vector<std::pair<int, int>> descend(int u, int v) const {  // (u, v], u is ancestor of v
        if (u == v) return {};
        if (head[u] == head[v]) return {{vertex_id[u] + 1, vertex_id[v]}};
        auto res = descend(u, par[head[v]]);
        res.emplace_back(vertex_id[head[v]], vertex_id[v]);
        return res;
    }
};

/**
 * @brief Heavy Light Decomposition
 * @docs docs/tree/HeavyLightDecomposition.md
 */

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
    vector<vector<pair<int, int>>> G(n);
    vector<int> x(m), y(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
        G[x[i]].emplace_back(y[i], i);
        G[y[i]].emplace_back(x[i], i);
    }

    HeavyLightDecomposition HLD(n);
    map<pair<int, int>, int> mp;
    {
        vector<bool> visited(n, false), used(m, false);
        auto dfs = [&](auto self, int v) -> void {
            visited[v] = true;
            for (auto& e : G[v]) {
                int u = e.first;
                if (visited[u]) continue;
                used[e.second] = true;
                self(self, u);
            }
        };
        dfs(dfs, 0);
        vector<int> nx, ny;
        for (int i = 0, j = 0; i < m; i++) {
            if (used[i]) {
                HLD.add_edge(x[i], y[i]);
                mp[{x[i], y[i]}] = mp[{y[i], x[i]}] = j++;
                nx.emplace_back(x[i]);
                ny.emplace_back(y[i]);
            }
        }
        swap(x, nx);
        swap(y, ny);
        HLD.build();
    }

    auto path = [&](int a, int b) {
        int p = HLD.lca(a, b);
        vector<int> u, v;
        while (a != p) {
            u.emplace_back(a);
            a = HLD.la(a, 1);
        }
        while (b != p) {
            v.emplace_back(b);
            b = HLD.la(b, 1);
        }
        u.emplace_back(p);
        while (!v.empty()) {
            u.emplace_back(v.back());
            v.pop_back();
        }
        return u;
    };

    int q;
    cin >> q;
    vector<vector<int>> ans;
    vector<int> cnt(m, 0);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        auto v = path(--a, --b);
        ans.emplace_back(v);
        for (size_t i = 0; i + 1 < v.size(); i++) cnt[mp[{v[i], v[i + 1]}]]++;
    }

    vector<int> deg(n, 0);
    for (int i = 0; i < m; i++) {
        if (cnt[i] & 1) {
            deg[x[i]]++;
            deg[y[i]]++;
        }
    }
    int need = 0;
    for (int i = 0; i < n; i++) need += deg[i] & 1;
    need /= 2;
    if (need > 0) {
        cout << "NO" << '\n';
        cout << need << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    for (int i = 0; i < q; i++) {
        cout << ans[i].size() << '\n';
        for (size_t j = 0; j < ans[i].size(); j++) cout << ans[i][j] + 1 << (j + 1 == ans[i].size() ? '\n' : ' ');
    }
    return 0;
}