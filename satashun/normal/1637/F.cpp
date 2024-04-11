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

const ll INF = TEN(18);

void slv() {
    int n;
    cin >> n;
    V<int> h(n);
    cin >> h;
    Graph<int> g(n);
    g.read(n - 1);
    int r = max_element(ALL(h)) - h.begin();

    V<int> mx(n);
    V<ll> dp(n, INF);

    auto rec = [&](auto&& f, int v, int p) -> void {
        mx[v] = h[v];
        ll tmp = 0;

        V<pair<int, ll>> vec;

        int c = 0;

        for (auto e : g[v]) {
            if (e.to == p) continue;
            f(f, e.to, v);
            chmax(mx[v], mx[e.to]);
            tmp += dp[e.to];
            vec.eb(mx[e.to], dp[e.to]);
            if (mx[e.to] >= h[v]) c++;
        }

        // chmin(dp[v], tmp + h[v]);
        if (p == -1) {
            // must
            if (c >= 2) {
                chmin(dp[v], tmp);
            } else if (c == 1) {
                if (SZ(vec) >= 2) {
                    ll md = INF;
                    rep(i, SZ(vec)) {
                        if (vec[i].fi < h[v]) chmin(md, h[v] - vec[i].fi);
                    }
                    chmin(dp[v], tmp + md);
                } else {
                    chmin(dp[v], tmp + h[v]);
                }
            } else {
                if (SZ(vec) >= 2) {
                    V<ll> vt;
                    for (auto p : vec) vt.pb(p.fi);
                    vt.reserve(SZ(vec));
                    sort(ALL(vt));
                    reverse(ALL(vt));
                    chmin(dp[v], tmp + h[v] * 2 - vt[0] - vt[1]);
                    /*
                                        rep(i, SZ(vec)) {
                                            rep(j, i) {
                                                chmin(dp[v],
                                                      tmp + h[v] * 2 - vec[j].fi
                       - vec[i].fi);
                                            }
                                        }*/
                } else {
                    rep(i, SZ(vec)) {
                        chmin(dp[v], tmp + h[v] * 2 - vec[i].fi);
                    }
                }
            }
        } else {
            if (c >= 1) {
                chmin(dp[v], tmp);
            } else {
                chmin(dp[v], tmp + h[v]);
                if (SZ(vec) >= 1) {
                    ll md = INF;
                    rep(i, SZ(vec)) { chmin(md, h[v] - vec[i].fi); }
                    tmp += md;
                    chmin(dp[v], tmp);
                }
            }
        }
    };

    rec(rec, r, -1);
    debug(dp);
    print(dp[r]);
}

int main() {
    int cases = 1;
    // cin >> cases;
    rep(i, cases) slv();

    return 0;
}