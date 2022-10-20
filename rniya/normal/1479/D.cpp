#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
 * @brief Zobrist Hash
 */
vector<uint64_t> ZobristHash(int n) {
    random_device seed_gen;
    mt19937_64 engine(seed_gen());
    vector<uint64_t> base(n);
    for (int i = 0; i < n; i++) base[i] = engine();
    return base;
}

/**
 * @brief Lowest Common Ancestor
 * @docs docs/tree/LowestCommonAncestor.md
 */
struct LowestCommonAncestor {
    int n, h;
    vector<vector<int>> G, par;
    vector<int> dep;
    LowestCommonAncestor(int n) : n(n), G(n), dep(n) {
        h = 1;
        while ((1 << h) <= n) h++;
        par.assign(h, vector<int>(n, -1));
    }
    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void dfs(int v, int p, int d) {
        par[0][v] = p;
        dep[v] = d;
        for (int u : G[v]) {
            if (u != p) dfs(u, v, d + 1);
        }
    }
    void build(int r = 0) {
        dfs(r, -1, 0);
        for (int k = 0; k < h - 1; k++) {
            for (int v = 0; v < n; v++) {
                if (par[k][v] >= 0) {
                    par[k + 1][v] = par[k][par[k][v]];
                }
            }
        }
    }
    int lca(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        for (int k = 0; k < h; k++) {
            if ((dep[v] - dep[u]) & 1 << k) {
                v = par[k][v];
            }
        }
        if (u == v) return u;
        for (int k = h - 1; k >= 0; --k) {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }
        return par[0][u];
    }
    int distance(int u, int v) { return dep[u] + dep[v] - dep[lca(u, v)] * 2; }
};

/**
 * @brief Binary Indexed Tree
 * @docs docs/datastructure/BinaryIndexedTree.md
 */
template <typename T> class BinaryIndexedTree {
    T sum(int i) {
        T res = T();
        for (; i > 0; i -= (i & -i)) res ^= dat[i];
        return res;
    }

public:
    int n;
    vector<T> dat;
    BinaryIndexedTree(int n_) : n(n_ + 1), dat(n + 1, 0) {}
    void add(int i, const T& x) {
        for (++i; i <= n; i += (i & -i)) dat[i] ^= x;
    }
    T query(int l, int r) { return sum(r) ^ sum(l); }
    T operator[](int i) { return query(i, i + 1); }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX_LOG = 20;
using u64 = uint64_t;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
    LowestCommonAncestor LCA(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        LCA.add_edge(--x, --y);
    }
    auto& G = LCA.G;
    vector<int> u(q), v(q), l(q), r(q);
    for (int i = 0; i < q; i++) cin >> u[i] >> v[i] >> l[i] >> r[i], u[i]--, v[i]--, l[i]--;

    LCA.build();
    vector<int> lb(q), ub(q), lca(q);
    for (int i = 0; i < q; i++) {
        lb[i] = l[i] - 1, ub[i] = r[i];
        lca[i] = a[LCA.lca(u[i], v[i])];
    }
    vector<u64> val(q, 0);
    vector<vector<tuple<int, int, int>>> check(n);
    auto hash = ZobristHash(n);
    BinaryIndexedTree<u64> BIT(n);

    auto dfs = [&](auto self, int v, int p) -> void {
        BIT.add(a[v], hash[a[v]]);
        for (auto& t : check[v]) {
            int L, R, idx;
            tie(L, R, idx) = t;
            val[idx] ^= BIT.query(L, R + 1);
        }
        check[v].clear();
        for (int& u : G[v]) {
            if (u == p) continue;
            self(self, u, v);
        }
        BIT.add(a[v], hash[a[v]]);
    };

    while (1) {
        bool ok = true;
        for (int i = 0; i < q; i++) {
            if (ub[i] - lb[i] == 1) continue;
            ok = false;
            int mid = (ub[i] + lb[i]) >> 1;
            check[u[i]].emplace_back(l[i], mid, i);
            check[v[i]].emplace_back(l[i], mid, i);
            if (l[i] <= lca[i] && lca[i] <= mid) val[i] ^= hash[lca[i]];
        }
        if (ok) break;
        dfs(dfs, 0, -1);

        for (int i = 0; i < q; i++) {
            if (ub[i] - lb[i] == 1) continue;
            int mid = (ub[i] + lb[i]) >> 1;
            (val[i] == 0 ? lb[i] : ub[i]) = mid;
            val[i] = 0;
        }
    }

    for (int i = 0; i < q; i++) cout << (ub[i] == r[i] ? -1 : ub[i] + 1) << '\n';
    return 0;
}