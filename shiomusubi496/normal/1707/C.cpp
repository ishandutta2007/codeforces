#line 2 "library/other/template.hpp"

#include<bits/stdc++.h>

#ifndef __COUNTER__
#define __COUNTER__ __LINE__
#endif

#define REP_SELECTER(a, b, c, d, e, ...) e
#define REP1_0(b, c) REP1_1(b, c)
#define REP1_1(b, c) for (ll REP_COUNTER_ ## c = 0; REP_COUNTER_ ## c < (ll)(b); ++ REP_COUNTER_ ## c)
#define REP1(b) REP1_0(b, __COUNTER__)
#define REP2(i, b) for (ll i = 0; i < (ll)(b); ++i)
#define REP3(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define REP4(i, a, b, c) for (ll i = (ll)(a); i < (ll)(b); i += (ll)(c))
#define rep(...) REP_SELECTER(__VA_ARGS__, REP4, REP3, REP2, REP1) (__VA_ARGS__)
#define RREP2(i, a) for (ll i = (ll)(a) - 1; i >= 0; --i)
#define RREP3(i, a, b) for (ll i = (ll)(a) - 1; i >= (ll)(b); --i)
#define RREP4(i, a, b, c) for (ll i = (ll)(a) - 1; i >= (ll)(b); i -= (ll)(c))
#define rrep(...) REP_SELECTER(__VA_ARGS__, RREP4, RREP3, RREP2) (__VA_ARGS__)
#define REPS2(i, b) for (ll i = 1; i <= (ll)(b); ++i)
#define REPS3(i, a, b) for (ll i = (ll)(a) + 1; i <= (ll)(b); ++i)
#define REPS4(i, a, b, c) for (ll i = (ll)(a) + 1; i <= (ll)(b); i += (ll)(c))
#define reps(...) REP_SELECTER(__VA_ARGS__, REPS4, REPS3, REPS2) (__VA_ARGS__)
#define RREPS2(i, a) for (ll i = (ll)(a); i > 0; --i)
#define RREPS3(i, a, b) for (ll i = (ll)(a); i > (ll)(b); --i)
#define RREPS4(i, a, b, c) for (ll i = (ll)(a); i > (ll)(b); i -= (ll)(c))
#define rreps(...) REP_SELECTER(__VA_ARGS__, RREPS4, RREPS3, RREPS2) (__VA_ARGS__)

#define each_for(...) for (auto&& __VA_ARGS__)
#define each_const(...) for (const auto& __VA_ARGS__)

#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)

#if __cplusplus >= 201402L
#define CONSTEXPR constexpr
#else
#define CONSTEXPR
#endif

#ifdef __cpp_if_constexpr
#define IF_CONSTEXPR constexpr
#else
#define IF_CONSTEXPR
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PLL = std::pair<ll, ll>;
template<class T> using prique = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<class T> class infinity {
  public:
    static constexpr T value = std::numeric_limits<T>::max() / 2;
    static constexpr T mvalue = std::numeric_limits<T>::min() / 2;
    static constexpr T max = std::numeric_limits<T>::max();
    static constexpr T min = std::numeric_limits<T>::min();
};

#if __cplusplus <= 201402L
template<class T> constexpr T infinity<T>::value;
template<class T> constexpr T infinity<T>::mvalue;
template<class T> constexpr T infinity<T>::max;
template<class T> constexpr T infinity<T>::min;
#endif

#if __cplusplus >= 201402L
template<class T> constexpr T INF = infinity<T>::value;
#endif

constexpr ll inf = infinity<ll>::value;
constexpr ld EPS = 1e-8;
constexpr ld PI = 3.1415926535897932384626;

template<class T, class U> std::ostream& operator<<(std::ostream& ost, const std::pair<T, U>& p) {
    return ost << p.first << ' ' << p.second;
}
template<class T, class U> std::istream& operator>>(std::istream& ist, std::pair<T, U>& p) {
    return ist >> p.first >> p.second;
}

template<class Container,
        typename std::enable_if<!std::is_same<Container, std::string>::value>::type* = nullptr>
auto operator<<(std::ostream& ost, const Container& cont)
        -> decltype(cont.begin(), cont.end(), ost)
{
    for (auto itr = cont.begin(); itr != cont.end(); ++itr) {
        if (itr != cont.begin()) ost << ' ';
        ost << *itr;
    }
    return ost;
}
template<class Container,
        typename std::enable_if<!std::is_same<Container, std::string>::value>::type* = nullptr>
auto operator>>(std::istream& ist, Container& cont)
        -> decltype(cont.begin(), cont.end(), ist)
{
    for (auto itr = cont.begin(); itr != cont.end(); ++itr) ist >> *itr;
    return ist;
}

template<class T, class U> inline constexpr bool chmin(T &a, const U &b) noexcept {
    return a > b ? a = b, true : false;
}
template<class T, class U> inline constexpr bool chmax(T &a, const U &b) noexcept {
    return a < b ? a = b, true : false;
}

inline CONSTEXPR ll gcd(ll a, ll b) noexcept {
    while (b) {
        const ll c = a;
        a = b;
        b = c % b;
    }
    return a;
}
inline CONSTEXPR ll lcm(ll a, ll b) noexcept {
    return a / gcd(a, b) * b;
}

inline CONSTEXPR bool is_prime(ll N) noexcept {
    if (N <= 1) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}
inline std::vector<ll> prime_factor(ll N) noexcept {
    std::vector<ll> res;
    for (ll i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            res.push_back(i);
            N /= i;
        }
    }
    if (N != 1) res.push_back(N);
    return res;
}

inline CONSTEXPR ll my_pow(ll a, ll b) noexcept {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        b >>= 1;
        a *= a;
    }
    return res;
}
inline CONSTEXPR ll mod_pow(ll a, ll b, ll mod) noexcept {
    a %= mod;
    ll res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        b >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

inline PLL extGCD(ll a, ll b) noexcept {
    const ll n = a, m = b;
    ll x = 1, y = 0, u = 0, v = 1;
    ll t;
    while (b) {
        t = a / b;
        std::swap(a -= t * b, b);
        std::swap(x -= t * u, u);
        std::swap(y -= t * v, v);
    }
    if (x < 0) {
        x += m;
        y -= n;
    }
    return {x, y};
}
inline ll mod_inv(ll a, ll mod) noexcept {
    ll b = mod;
    ll x = 1, u = 0;
    ll t;
    while (b) {
        t = a / b;
        std::swap(a -= t * b, b);
        std::swap(x -= t * u, u);
    }
    if (x < 0) x += mod;
    assert(a == 1);
    return x;
}
inline PLL ChineseRemainder(ll b1, ll m1, ll b2, ll m2) noexcept {
    const PLL p = extGCD(m1, m2);
    const ll g = p.first * m1 + p.second * m2;
    const ll l = m1 / g * m2;
    if ((b2 - b1) % g != 0) return PLL{-1, -1};
    const ll x = (b2 - b1) / g * p.first % (m2 / g);
    return {(x * m1 + b1 + l) % l, l};
}
PLL ChineseRemainders(const std::vector<ll>& b, const std::vector<ll>& m) noexcept {
    PLL res{0, 1};
    rep (i, b.size()) {
        res = ChineseRemainder(res.first, res.second, b[i], m[i]);
        if (res.first == -1) return res;
    }
    return res;
}

template<class F> class RecLambda {
  private:
    F f;
  public:
    explicit constexpr RecLambda(F&& f_) : f(std::forward<F>(f_)) {}
    template<class... Args> constexpr auto operator()(Args&&... args) const
            -> decltype(f(*this, std::forward<Args>(args)...)) {
        return f(*this, std::forward<Args>(args)...);
    }
};

template<class F> inline constexpr RecLambda<F> rec_lambda(F&& f) {
    return RecLambda<F>(std::forward<F>(f));
}

template<class Head, class... Tail> struct multi_dim_vector {
    using type = std::vector<typename multi_dim_vector<Tail...>::type>;
};
template<class T> struct multi_dim_vector<T> {
    using type = T;
};

template<class T, class Arg> constexpr std::vector<T> make_vec(int n, Arg&& arg) {
    return std::vector<T>(n, std::forward<Arg>(arg));
}
template<class T, class... Args>
constexpr typename multi_dim_vector<Args..., T>::type make_vec(int n, Args&&... args) {
    return typename multi_dim_vector<Args..., T>::type (n, make_vec<T>(std::forward<Args>(args)...));
}

inline CONSTEXPR int popcnt(ull x) {
#if __cplusplus >= 202002L
    return std::popcount(x);
#endif
    x = (x & 0x5555555555555555) + ((x >> 1 ) & 0x5555555555555555);
    x = (x & 0x3333333333333333) + ((x >> 2 ) & 0x3333333333333333);
    x = (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4 ) & 0x0f0f0f0f0f0f0f0f);
    x = (x & 0x00ff00ff00ff00ff) + ((x >> 8 ) & 0x00ff00ff00ff00ff);
    x = (x & 0x0000ffff0000ffff) + ((x >> 16) & 0x0000ffff0000ffff);
    return (x & 0x00000000ffffffff) + ((x >> 32) & 0x00000000ffffffff);
}

template<class T, class Comp = std::less<T>> class presser {
  protected:
    std::vector<T> dat;
    Comp cmp;
    bool sorted = false;
  public:
    presser() : presser(Comp()) {}
    presser(const Comp& cmp) : cmp(cmp) {}
    presser(const std::vector<T>& vec, const Comp& cmp = Comp()) : dat(vec), cmp(cmp) {}
    presser(std::vector<T>&& vec, const Comp& cmp = Comp()) : dat(std::move(vec)), cmp(cmp) {}
    presser(std::initializer_list<T> il, const Comp& cmp = Comp()) : dat(il.begin(), il.end()), cmp(cmp) {}
    void reserve(int n) {
        assert(!sorted);
        dat.reserve(n);
    }
    void push_back(const T& v) {
        assert(!sorted);
        dat.push_back(v);
    }
    void push_back(T&& v) {
        assert(!sorted);
        dat.push_back(std::move(v));
    }
    void push(const std::vector<T>& vec) {
        assert(!sorted);
        const int n = dat.size();
        dat.resize(n + vec.size());
        rep (i, vec.size()) dat[n + i] = vec[i];
    }
    int build() {
        assert(!sorted); sorted = true;
        std::sort(all(dat), cmp);
        dat.erase(std::unique(all(dat), [&](const T& a, const T& b) -> bool {
            return !cmp(a, b) && !cmp(b, a);
        }), dat.end());
        return dat.size();
    }
    const T& operator[](int k) const& {
        assert(sorted);
        assert(0 <= k && k < (int)dat.size());
        return dat[k];
    }
    T operator[](int k) && {
        assert(sorted);
        assert(0 <= k && k < (int)dat.size());
        return std::move(dat[k]);
    }
    int get_index(const T& val) const {
        assert(sorted);
        return static_cast<int>(std::lower_bound(all(dat), val, cmp) - dat.begin());
    }
    std::vector<int> pressed(const std::vector<T>& vec) const {
        assert(sorted);
        std::vector<int> res(vec.size());
        rep (i, vec.size()) res[i] = get_index(vec[i]);
        return res;
    }
    void press(std::vector<T>& vec) const {
        static_assert(std::is_integral<T>::value, "template argument must be convertible from int type");
        assert(sorted);
        each_for (i : vec) i = get_index(i);
    }
    int size() const {
        assert(sorted);
        return dat.size();
    }
    const std::vector<T>& data() const& { return dat; }
    std::vector<T> data() && { return std::move(dat); }
};
#line 2 "library/graph/tree/DoublingLowestCommonAncestor.hpp"

#line 2 "library/other/bitop.hpp"

#line 4 "library/other/bitop.hpp"

namespace bitop {

#define KTH_BIT(b, k) (((b) >> (k)) & 1)
#define POW2(k) (1ull << (k))

    inline ull next_combination(int n, ull x) {
        if (n == 0) return 1;
        ull a = x & -x;
        ull b = x + a;
        return (x & ~b) / a >> 1 | b;
    }

#define rep_comb(i, n, k) for (ull i = (1ull << (k)) - 1; i < (1ull << (n)); i = bitop::next_combination((n), i))

    inline CONSTEXPR int msb(ull x) {
        int res = x ? 0 : -1;
        if (x & 0xFFFFFFFF00000000) x &= 0xFFFFFFFF00000000, res += 32;
        if (x & 0xFFFF0000FFFF0000) x &= 0xFFFF0000FFFF0000, res += 16;
        if (x & 0xFF00FF00FF00FF00) x &= 0xFF00FF00FF00FF00, res +=  8;
        if (x & 0xF0F0F0F0F0F0F0F0) x &= 0xF0F0F0F0F0F0F0F0, res +=  4;
        if (x & 0xCCCCCCCCCCCCCCCC) x &= 0xCCCCCCCCCCCCCCCC, res +=  2;
        return res + ((x & 0xAAAAAAAAAAAAAAAA) ? 1 : 0);
    }

    inline CONSTEXPR int ceil_log2(ull x) {
        return x ? msb(x - 1) + 1 : 0;
    }
}
#line 2 "library/graph/Graph.hpp"

#line 4 "library/graph/Graph.hpp"

template<class T = int> struct edge {
    int from, to;
    T cost;
    int idx;
    edge() : from(-1), to(-1) {}
    edge(int f, int t, const T& c = 1, int i = -1) : from(f), to(t), cost(c), idx(i) {}
    edge(int f, int t, T&& c, int i = -1) : from(f), to(t), cost(std::move(c)), idx(i) {}
    operator int() const { return to; }
    friend bool operator<(const edge<T>& lhs, const edge<T>& rhs) {
        return lhs.cost < rhs.cost;
    }
    friend bool operator>(const edge<T>& lhs, const edge<T>& rhs) {
        return lhs.cost > rhs.cost;
    }
};

template<class T = int> using Edges = std::vector<edge<T>>;
template<class T = int> using GMatrix = std::vector<std::vector<T>>;

template<class T = int> class Graph : public std::vector<std::vector<edge<T>>> {
  private:
    using Base = std::vector<std::vector<edge<T>>>;
  public:
    int edge_id = 0;
    using Base::Base;
    int edge_size() const { return edge_id; }
    int add_edge(int a, int b, const T& c, bool is_directed = false) {
        assert(0 <= a && a < (int)this->size());
        assert(0 <= b && b < (int)this->size());
        (*this)[a].emplace_back(a, b, c, edge_id);
        if (!is_directed) (*this)[b].emplace_back(b, a, c, edge_id);
        return edge_id++;
    }
    int add_edge(int a, int b, bool is_directed = false) {
        assert(0 <= a && a < (int)this->size());
        assert(0 <= b && b < (int)this->size());
        (*this)[a].emplace_back(a, b, 1, edge_id);
        if (!is_directed) (*this)[b].emplace_back(b, a, 1, edge_id);
        return edge_id++;
    }
};

template<class T> GMatrix<T> ListToMatrix(const Graph<T>& G) {
    const int N = G.size();
    auto res = make_vec<T>(N, N, infinity<T>::value);
    rep (i, N) res[i][i] = 0;
    rep (i, N) {
        each_const (e : G[i]) res[i][e.to] = e.cost;
    }
    return res;
}

template<class T> Edges<T> UndirectedListToEdges(const Graph<T>& G) {
    const int V = G.size();
    const int E = G.edge_size();
    Edges<T> Ed(E);
    rep (i, V) {
        each_const (e : G[i]) Ed[e.idx] = e;
    }
    return Ed;
}

template<class T> Edges<T> DirectedListToEdges(const Graph<T>& G) {
    const int V = G.size();
    const int E = std::accumulate(
        all(G), 0,
        [](int a, const std::vector<edge<T>>& v) -> int { return a + v.size(); }
    );
    Edges<T> Ed(G.edge_size()); Ed.reserve(E);
    rep (i, V) {
        each_const (e : G[i]) {
            if (Ed[e.idx] == -1) Ed[e.idx] = e;
            else Ed.push_back(e);
        }
    }
    return Ed;
}

template<class T> Graph<T> ReverseGraph(const Graph<T>& G) {
    const int V = G.size();
    Graph<T> res(V);
    rep (i, V) {
        each_const (e : G[i]) {
            res[e.to].emplace_back(e.to, e.from, e.cost, e.idx);
        }
    }
    res.edge_id = G.edge_size();
    return res;
}


struct unweighted_edge {
    template<class... Args> unweighted_edge(const Args&...) {}
    operator int() { return 1; }
};

using UnweightedGraph = Graph<unweighted_edge>;

/**
 * @brief Graph-template
 * @docs docs/Graph.md
 */
#line 6 "library/graph/tree/DoublingLowestCommonAncestor.hpp"

template<class T> class DoublingLCA {
  protected:
    int root, n, h;
    Graph<T> G_;
    const Graph<T>& G;
    std::vector<edge<T>> par;
    std::vector<int> dep;
    std::vector<std::vector<int>> dbl;
    void dfs_build(int v, int p) {
        each_const (e : G[v]) {
            if (e.to != p) {
                par[e.to] = edge<T>(e.to, e.from, e.cost, e.idx);
                dep[e.to] = dep[v] + 1;
                dfs_build(e.to, v);
            }
        }
    }
    void init() {
        n = G.size();
        h = bitop::ceil_log2(n) + 1;
        par.resize(n); par[root] = edge<T>{};
        dep.resize(n); dep[root] = 0;
        dfs_build(root, -1);
        dbl.assign(n, std::vector<int>(h, -1));
        rep (i, n) dbl[i][0] = par[i].to;
        rep (i, h - 1) {
            rep (j, n) dbl[j][i + 1] = dbl[j][i] == -1 ? -1 : dbl[ dbl[j][i] ][i];
        }
    }
  public:
    DoublingLCA(const Graph<T>& G, int r = 0) : root(r), G(G)  { init(); }
    DoublingLCA(Graph<T>&& G, int r = 0) : root(r), G_(std::move(G)), G(G_) { init(); }
    int depth(int v) const { return dep[v]; }
    int parent(int v) const { return par[v].to; }
    int kth_ancestor(int v, int k) const {
        if (dep[v] < k) return -1;
        rrep (i, h) {
            if ((k >> i) & 1) v = dbl[v][i];
        }
        return v;
    }
    int next_vertex(int s, int t) const {
        if (dep[s] >= dep[t]) return parent(s);
        int u = kth_ancestor(t, dep[t] - dep[s] - 1);
        return parent(u) == s ? u : parent(s);
    }
    Edges<T> path(int s, int t) const {
        Edges<T> pre, suf;
        while (dep[s] > dep[t]) pre.push_back(par[s]), s = par[s].to;
        while (dep[t] > dep[s]) suf.push_back(par[t]), t = par[t].to;
        while (s != t) {
            pre.push_back(par[s]), s = par[s].to;
            suf.push_back(par[t]), t = par[t].to;
        }
        rrep (i, suf.size()) pre.emplace_back(suf[i].to, suf[i].from, suf[i].cost, suf[i].idx);
        return pre;
    }
    int lca(int u, int v) const {
        if (dep[u] > dep[v]) u = kth_ancestor(u, dep[u] - dep[v]);
        if (dep[u] < dep[v]) v = kth_ancestor(v, dep[v] - dep[u]);
        if (u == v) return u;
        rrep (i, h) {
            if (dbl[u][i] != dbl[v][i]) {
                u = dbl[u][i];
                v = dbl[v][i];
            }
        }
        return parent(u);
    }
    int dist(int u, int v) const {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
};

/**
 * @brief DoublingLowestCommonAncestor(LCA)
 * @docs docs/DoublingLowestCommonAncestor.md
 */
#line 2 "library/graph/mst/Kruskal.hpp"

#line 2 "library/data-struct/unionfind/UnionFind.hpp"

#line 4 "library/data-struct/unionfind/UnionFind.hpp"

class UnionFind {
  protected:
    int n;
    std::vector<int> par_vec;
  public:
    UnionFind() : UnionFind(0) {}
    UnionFind(int n) : n(n), par_vec(n, -1) {}
    int find(int x) {
        assert(0 <= x && x < n);
        return par_vec[x] < 0 ? x : par_vec[x] = find(par_vec[x]);
    }
    std::pair<int, int> merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return {x, -1};
        if (par_vec[x] > par_vec[y]) std::swap(x, y);
        par_vec[x] += par_vec[y];
        par_vec[y] = x;
        return {x, y};
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return -par_vec[find(x)];
    }
    std::vector<std::vector<int>> groups() {
        std::vector<std::vector<int>> res(n);
        rep (i, n) res[find(i)].push_back(i);
        res.erase(
            remove_if(all(res), [](const std::vector<int>& v) { return v.empty(); }),
            res.end()
        );
        return res;
    }
    bool is_root(int x) const {
        assert(0 <= x && x < n);
        return par_vec[x] < 0;
    }
};

/**
 * @brief UnionFind
 * @docs docs/UnionFind.md
 */
#line 6 "library/graph/mst/Kruskal.hpp"

template<class T> T Kruskal(int N, Edges<T> Ed) {
    std::sort(all(Ed));
    UnionFind UF(N);
    T res = 0;
    each_const (e : Ed) {
        if (UF.merge(e.from, e.to).second >= 0) res += e.cost;
    }
    return res;
}

template<class T> Edges<T> Kruskal_vec(int N, Edges<T> Ed) {
    std::sort(all(Ed));
    UnionFind UF(N);
    Edges<T> res;
    each_const (e : Ed) {
        if (UF.merge(e.from, e.to).second >= 0) res.push_back(e);
    }
    return res;
}

/**
 * @brief Kruskal()
 * @docs docs/Kruskal.md
 */
#line 4 "main.cpp"

using namespace std;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    Edges<ll> edges;
    rep (i, m) {
        int a, b; scanf("%d%d", &a, &b);
        edges.emplace_back(a - 1, b - 1, i);
    }
    auto mst_edges = Kruskal_vec(n, edges);
    Graph<ll> mst(n);
    each_const (e : mst_edges) mst.add_edge(e.from, e.to, e.cost);
    vector<bool> used(m, false);
    each_const (e : mst_edges) used[e.cost] = true;
    constexpr int r = 0;
        string ans(n, '1');
        DoublingLCA<ll> dlca(mst, r);
        vector<int> ca(n), cb(n), cc(n);
        auto f = [&](int a, int b) {
            // a is b's ancestor
            int l = dlca.next_vertex(a, b);
            if (l != b) {
                ca[l]++; cc[l]--;
                ca[b]--; cc[b]++;
            }
        };
        each_const (e : edges) {
            if (used[e.cost]) continue;
            int u = e.from, v = e.to;
            int l = dlca.lca(u, v);
            if (l == v) swap(u, v);
            if (l == u) {
                f(l, v);
            }
            else {
                ca[r]++;
                {
                    int l2 = dlca.next_vertex(l, u);
                    ca[l2]--; cc[l2]++;
                }
                {
                    int l2 = dlca.next_vertex(l, v);
                    ca[l2]--; cc[l2]++;
                }
                f(l, u);
                f(l, v);
            }
        }
        ll t = 0;
        rec_lambda([&](auto&& self, int v, int p) -> void {
            t += ca[v];
            each_const (e : mst[v]) {
                if (e.to == p) continue;
                self(e.to, v);
            }
            t += cb[v];
            if (t) ans[v] = '0';
            t += cc[v];
        })(r, -1);
        rep (i, n) putchar(ans[i]);
        puts("");
}