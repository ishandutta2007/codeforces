//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

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

template <class T>
void mkuni(vector<T>& v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
}

template <class T>
vector<int> sort_by(const vector<T>& v) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) { return v[i] < v[j]; });
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
void scan(vector<T>& v, T offset = T(0)) {
    for (auto& x : v) {
        cin >> x;
        x += offset;
    }
}

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

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;

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

template <class T>
V<T> bfs(const Graph<T>& g, int s = 0) {
    const T inf = numeric_limits<T>::max() / 2;
    int n = g.size();

    V<T> ds(n, inf);
    using P = pair<T, int>;
    queue<int> que;
    que.push(s);
    ds[s] = 0;

    while (!que.empty()) {
        auto v = que.front();
        que.pop();
        for (auto e : g[v]) {
            T nx = ds[v] + 1;
            if (ds[e.to] > nx) {
                ds[e.to] = nx;
                que.push(e.to);
            }
        }
    }
    for (auto& x : ds)
        if (x == inf) x = -1;
    return ds;
}

// must be optimized
template <class T>
V<T> bfs01(const Graph<T>& g, int s = 0) {
    const T inf = numeric_limits<T>::max() / 2;
    int n = g.size();

    V<T> ds(n, inf);
    using P = pair<T, int>;
    deque<int> que;
    que.push_back(s);
    ds[s] = 0;

    while (!que.empty()) {
        auto v = que.front();
        que.pop_front();
        for (auto e : g[v]) {
            T nx = ds[v] + e.cost;
            if (ds[e.to] > nx) {
                ds[e.to] = nx;
                if (e.cost == 0) {
                    que.push_front(e.to);
                } else {
                    que.push_back(e.to);
                }
            }
        }
    }
    for (auto& x : ds)
        if (x == inf) x = -1;
    return ds;
}

template <class T>
V<T> dijkstra(const Graph<T>& g, int s = 0) {
    const T inf = numeric_limits<T>::max() / 2;
    int n = g.size();

    V<T> ds(n, inf);
    using P = pair<T, int>;
    priority_queue<P, V<P>, greater<P>> que;
    que.emplace(0, s);
    ds[s] = 0;
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        int v = p.se;
        if (ds[v] < p.fi) continue;
        for (auto e : g[v]) {
            T nx = ds[v] + e.cost;
            if (ds[e.to] > nx) {
                ds[e.to] = nx;
                que.emplace(nx, e.to);
            }
        }
    }
    for (auto& x : ds)
        if (x == inf) x = -1;
    return ds;
}

const ll INF = TEN(18);

void slv() {
    int n, q;
    cin >> n >> q;
    auto a = make_vec<ll>(3, n);
    cin >> a;

    V<pair<pii, int>> es;

    VV<pii> vr(n + 1), vl(n + 1);

    rep(i, q) {
        int l, r, k;
        cin >> l >> r >> k;
        --l;
        es.eb(mp(l, r), k);
        vl[l].eb(r, k);
        vr[r].eb(l, k);
    }

    auto ps = make_vec<ll>(3, n + 1);
    rep(i, 3) {
        rep(j, n) { ps[i][j + 1] = ps[i][j] + a[i][j]; }
    }

    V<ll> sum1(n + 1), sum3(n + 1);
    rep(i, n) {
        sum1[i] = ps[0][i + 1] - ps[1][i];
        sum3[i + 1] = ps[2][n] - ps[2][i] + ps[1][i + 1];
    }

    //[l, r)->cost(l, r) + sum1[l] + sum3[r]

    ll mx = max(*max_element(ALL(sum1)), *max_element(ALL(sum3)));

    ll ans = TEN(18);
    auto rec = [&](auto&& f, int l, int r, ll cov) -> void {
        if (r <= l + 1) return;
        int m = (l + r) / 2;
        int cnt_node = r - l + 2;
        int S = cnt_node - 2, T = cnt_node - 1;
        Graph<ll> g(cnt_node);

        for (int i = l; i < r - 1; ++i) {
            g.add_directed_edge(i - l + 1, i - l, 0);
        }

        for (int k = l; k < m; ++k) {
            g.add_directed_edge(S, k - l, -sum1[k] + mx);
        }
        for (int k = m; k < r; ++k) {
            g.add_directed_edge(k - l, T, -sum3[k] + mx);
        }

        for (int k = l; k < r; ++k) {
            {
                ll mn = INF;
                for (auto [to, w] : vl[k]) {
                    if (to < r) {
                        g.add_directed_edge(k - l, to - l, w);
                    } else {
                        chmin(mn, w);
                    }
                }
                if (mn != INF) {
                    g.add_directed_edge(k - l, r - 1 - l, mn);
                }
            }
            {
                ll mn = INF;
                for (auto [to, w] : vr[k]) {
                    if (to < l) {
                        chmin(mn, w);
                    }
                }
                if (mn != INF) {
                    g.add_directed_edge(l - l, k - l, mn);
                }
            }
        }
        g.add_directed_edge(l - l, r - 1 - l, cov);
        auto ds = dijkstra(g, S);
        chmin(ans, ds[T]);

        {
            ll covl = cov;
            for (int k = m; k < r; ++k) {
                for (auto [to, w] : vr[k]) {
                    if (to < l) {
                        chmin(covl, w);
                    }
                }
            }
            f(f, l, m, covl);
        }
        {
            ll covr = cov;
            for (int k = l; k < m; ++k) {
                for (auto [to, w] : vl[k]) {
                    if (to >= r) {
                        chmin(covr, w);
                    }
                }
            }
            f(f, m, r, covr);
        }
    };

    rec(rec, 0, n + 1, 1e18);
    ans = -(ans - mx * 2);
    print(ans);
}

int main() {
    int cases = 1;
    // cin >> cases;
    rep(i, cases) slv();

    return 0;
}