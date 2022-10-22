#pragma region satashun
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

template <class T>
V<T> make_vec(size_t a) {
    return V<T>(a);
}

template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

template <typename T, typename V>
void fill_vec(vector<T>& vec, const V& val, int len) {
    vec.assign(len, val);
}
template <typename T, typename V, typename... Ts>
void fill_vec(vector<T>& vec, const V& val, int len, Ts... ts) {
    vec.resize(len),
        for_each(begin(vec), end(vec), [&](T& v) { fill_vec(v, val, ts...); });
}

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <typename T>
int arglb(const V<T>& v, const T& x) {
    return distance(v.begin(), lower_bound(ALL(v), x));
}

template <typename T>
int argub(const V<T>& v, const T& x) {
    return distance(v.begin(), upper_bound(ALL(v), x));
}

template <class T>
void mkuni(vector<T>& v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
}

template <class T>
vector<int> sort_by(const vector<T>& v, bool increasing = true) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);

    if (increasing) {
        stable_sort(res.begin(), res.end(),
                    [&](int i, int j) { return v[i] < v[j]; });
    } else {
        stable_sort(res.begin(), res.end(),
                    [&](int i, int j) { return v[i] > v[j]; });
    }
    return res;
}

template <class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
    is >> p.first >> p.second;
    return is;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) {
        is >> x;
    }
    return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const set<T>& ST) {
    os << "{";
    for (auto it = ST.begin(); it != ST.end(); ++it) {
        if (it != ST.begin()) os << ",";
        os << *it;
    }
    os << "}";
    return os;
}

template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& MP) {
    for (auto it = MP.begin(); it != MP.end(); ++it) {
        os << "(" << it->first << ": " << it->second << ")";
    }
    return os;
}

string to_string(__int128_t x) {
    if (x == 0) return "0";
    string result;
    if (x < 0) {
        result += "-";
        x *= -1;
    }
    string t;
    while (x) {
        t.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(t.begin(), t.end());
    return result + t;
}

ostream& operator<<(ostream& o, __int128_t x) { return o << to_string(x); }

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

template <class T>
V<T>& operator+=(V<T>& vec, const T& v) {
    for (auto& x : vec) x += v;
    return vec;
}

template <class T>
V<T>& operator-=(V<T>& vec, const T& v) {
    for (auto& x : vec) x -= v;
    return vec;
}

// suc : 1 = newline, 2 = space
template <class T>
void print(T x, int suc = 1) {
    cout << x;
    if (suc == 1)
        cout << "\n";
    else if (suc == 2)
        cout << " ";
}

template <class T>
void print(const vector<T>& v, int suc = 1) {
    for (int i = 0; i < v.size(); ++i)
        print(v[i], i == int(v.size()) - 1 ? suc : 2);
}

template <class T>
void show(T x) {
    print(x, 1);
}

template <typename Head, typename... Tail>
void show(Head H, Tail... T) {
    print(H, 2);
    show(T...);
}

int topbit(int t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(int a) { return a == 0 ? 32 : __builtin_ctz(a); }
int botbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int popcount(int t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
int bit_parity(int t) { return __builtin_parity(t); }
int bit_parity(ll t) { return __builtin_parityll(t); }

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;
#pragma endregion satashun

template <class T>
class Edge {
   public:
    int from, to, idx;
    T cost;

    Edge() = default;
    Edge(int from, int to, T cost = T(1), int idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {}
    operator int() const { return to; }

    bool operator<(const Edge& e) const { return cost < e.cost; }
};

template <class T>
class Graph {
   public:
    using E = Edge<T>;
    vector<vector<E>> g;
    vector<E> edges;
    int es;

    Graph() {}
    Graph(int n) : g(n), edges(0), es(0){};

    int size() const { return g.size(); }

    virtual void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }

    virtual void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    inline vector<E>& operator[](const int& k) { return g[k]; }

    inline const vector<E>& operator[](const int& k) const { return g[k]; }

    void read(int M, int offset = -1, bool directed = false,
              bool weighted = false) {
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a += offset;
            b += offset;
            T c = T(1);
            if (weighted) cin >> c;
            edges.emplace_back(a, b, c);
            if (directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }
};

class unionfind {
    vector<int> par, rank;

   public:
    void init(int n) {
        par.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    unionfind() {}
    unionfind(int n) { init(n); }

    int find(int x) {
        if (par[x] == x)
            return x;
        else
            return par[x] = find(par[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;

        if (rank[x] < rank[y])
            par[x] = y;
        else {
            par[y] = x;
            if (rank[x] == rank[y]) ++rank[x];
        }
        return true;
    }

    bool same(int x, int y) { return (find(x) == find(y)); }
};

void slv() {
    int n, m;
    cin >> n >> m;

    Graph<int> g(n), g2(n);
    g.read(m);

    string ans(m, '0');
    unionfind uf(n);
    V<int> one;
    set<int> us;
    V<int> tree;

    rep(i, m) {
        auto e = g.edges[i];
        if (!uf.unite(e.from, e.to)) {
            ans[i] = '1';
            one.pb(i);
            us.insert(e.from);
            us.insert(e.to);
        } else {
            g2.add_edge(e.from, e.to);
            tree.pb(i);
        }
    }

    V<int> par_edge(n);
    V<int> dep(n);

    auto rec = [&](auto&& f, int v, int p, int pe, int d) -> void {
        dep[v] = d;
        par_edge[v] = pe;
        for (auto e : g2[v]) {
            if (e.to == p) continue;
            f(f, e.to, v, tree[e.idx], d + 1);
        }
    };

    rec(rec, 0, -1, -1, 0);

    debug(one);
    if (SZ(one) == 3 && SZ(us) == 3) {
        debug("baka");
        int v = one.back();
        ans[v] = '0';

        int p = g.edges[v].from;
        int q = g.edges[v].to;
        if (dep[p] < dep[q]) swap(p, q);
        int pe = par_edge[p];
        ans[pe] = '1';
    }
    show(ans);
}

int main() {
    int cases = 1;
    cin >> cases;
    rep(i, cases) slv();

    return 0;
}