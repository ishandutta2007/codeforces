#include <bits/stdc++.h>
using namespace std;

// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush

namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::const_iterator find(const vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(const vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
}
using namespace __algorithm;

struct __monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))__monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))__monostate& ms) { return os; }
} ms;

namespace __io {
    FILE* setIn(string s) { return freopen(s.c_str(),"r",stdin); }
    FILE* setOut(string s) { return freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

// tree {{{
#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>

struct edge {
    int u_xor_v;

    edge() : u_xor_v(0) {}

    edge(int _u_xor_v) : u_xor_v(_u_xor_v) {}

    int get_nbr(int u) const {
        assert(u_xor_v);
        return u ^ u_xor_v;
    }
};

template<typename Data>
struct edge_with_data : edge {
    Data data;

    edge_with_data() : edge() {}

    edge_with_data(int _u_xor_v, Data _data) : edge(_u_xor_v), data(_data) {}
};

enum TreeInputFormat { EDGE_LIST, PARENT_LIST };
template<typename Edge>
struct tree {
    int V, root;
    std::vector<std::vector<Edge>> neighbors;

    std::vector<int> parent, depth, subtree_size, preorder, reverse_preorder;

    tree() : V(0), root(-1) {}

    tree(int _V, int _root) : V(_V), root(_root), neighbors(V) {}

    void add_edge(int u, int v, Edge e = {}) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        e.u_xor_v = u ^ v;
        neighbors[u].push_back(e);
        neighbors[v].push_back(e);
    }

    const Edge& parent_edge(int u) const {
        assert(u != root);
        return neighbors[u].front();
    }

    template<typename Function>
    void for_each_child(int u, Function fn) const {
        for (int i = u != root; i < int(neighbors[u].size()); i++)
            fn(neighbors[u][i]);
    }

    static void DefaultEdgeDataReader(__attribute((unused)) Edge &e) {}

    template<typename EdgeDataReader = void(*)(Edge&)>
    friend void re(tree &t, TreeInputFormat Format, int FirstIndex,
            EdgeDataReader read = DefaultEdgeDataReader) {
        assert(t.V > 0);
        for (int i = 0; i < t.V - 1; i++) {
            int u, v;
            std::cin >> u, u -= FirstIndex;
            if (Format == PARENT_LIST) v = i + 1;
            else std::cin >> v, v -= FirstIndex;
            Edge e;
            read(e);
            t.add_edge(u, v, e);
        }
        t.init();
    }

    void reroot(int _root) {
        root = _root;
        init();
    }

    void init() {
        parent.resize(V), depth.resize(V), subtree_size.resize(V);

        parent[root] = -1;
        depth[root] = 0;

        traverse(root);

        for (int u = 0; u < V; u++) {
            sort(neighbors[u].begin(), neighbors[u].end(), [&](const Edge &a, const Edge &b) {
                return subtree_size[a.get_nbr(u)] > subtree_size[b.get_nbr(u)];
            });
        }

        preorder.clear();
        build_preorder(root);

        reverse_preorder = preorder;
        std::reverse(reverse_preorder.begin(), reverse_preorder.end());
    }

    void traverse(int u) {
        subtree_size[u] = 1;
        for (Edge e : neighbors[u]) {
            int v = e.get_nbr(u);
            if (v == parent[u]) continue;

            parent[v] = u;
            depth[v] = depth[u] + 1;
            traverse(v);
            subtree_size[u] += subtree_size[v];
        }
    }

    void build_preorder(int u) {
        preorder.push_back(u);
        for_each_child(u, [&](Edge e) { build_preorder(e.get_nbr(u)); });
    }

    static void DefaultEdgeDataWriter(__attribute((unused)) Edge &e) {}

    template<typename EdgeDataWriter = void(*)(Edge&)>
    friend void pr(const tree& t, EdgeDataWriter write = DefaultEdgeDataWriter) {
        std::cout << "{V=" << t.V << " root=" << t.root << " |";
        for (int u = 0; u < t.V; u++) {
            std::cout << " " << u << "--{";
            t.for_each_child(u, [&](Edge e) {
                std::cout << "(ch=" << e.get_nbr(u);
                write(e);
                std::cout << ")";
            });
            std::cout << "}";
        }
        std::cout << "}";
    }
};
// }}}

// binary_indexed_tree {{{
#include <iterator>
#include <vector>
#include <cassert>
#include <functional>

template<typename T, typename AssociativeOperation>
struct binary_indexed_tree {
    int SZ;
    T identity;
    AssociativeOperation TT;
    std::vector<T> data;

    binary_indexed_tree() {}

    binary_indexed_tree(int _SZ, T _identity, AssociativeOperation _TT)
            : SZ(_SZ), identity(_identity), TT(_TT) {
        data.assign(2 * SZ, identity);
    }

    // Replaces the current value at index i with TT(current value, v)
    void add(int i, T v) {
        for (i++; i <= SZ; i += i & -i)
            data[i] = TT(data[i], v);
    }

    // Returns the result of accumulating the elements at indices in [0, len)
    T accumulate_prefix(int len) const {
        assert(0 <= len && len <= SZ);
        T res = identity;
        for (; len; len -= len & -len)
            res = TT(res, data[len]);
        return res;
    }

    /* Returns the smallest len in [0, S] such that p(accumulate_prefix(len)) returns true.
     * Returns S + 1 if no such len exists.
     * Requires that p(accumulate_prefix(len)) is non-decreasing in len.
     */
    template<typename Predicate>
    int binary_search(Predicate p) const {
        if (p(identity)) return 0;

        int len = 0;
        T accumulator = identity;

        for (int bit = 31 - __builtin_clz(SZ); bit >= 0; bit--) {
            int next = len + (1 << bit);
            if (next > SZ) continue;

            T combined = TT(accumulator, data[next]);
            if (!p(combined)) {
                len = next;
                accumulator = combined;
            }
        }

        return len + 1;
    }
};
// }}}

int main() {
    setIO();

    int N; re(N);

    vi a(N); re(a);

    vi univ = a;
    dedup(univ);

    const int U = sz(univ);
    vvi occur(U);

    F0R (i, N) {
        a[i] = index(univ, a[i]);
        occur[a[i]].pb(i);
    }

    tree<edge> tr(N, 0);
    re(tr, EDGE_LIST, 1);

    vi index(N);
    F0R (i, sz(tr.preorder))
        index[tr.preorder[i]] = i;

    binary_indexed_tree<int, plus<int>> bit(N, 0, plus<int>());

    auto get_count = [&](int u, edge e) {
        int v = e.get_nbr(u);
        if (tr.depth[v] < tr.depth[u]) {
            return bit.accumulate_prefix(N) -
                (bit.accumulate_prefix(index[u] + tr.subtree_size[u]) - bit.accumulate_prefix(index[u]));
        } else {
            return
                bit.accumulate_prefix(index[v] + tr.subtree_size[v]) - bit.accumulate_prefix(index[v]);
        }
    };

    binary_indexed_tree<int, plus<int>> ban(N, 0, plus<int>());

    auto ban_away = [&](int u, edge e) {
        int v = e.get_nbr(u);
        if (tr.depth[v] < tr.depth[u]) {
            ban.add(index[u], 1);
            ban.add(index[u] + tr.subtree_size[u], -1);
        } else {
            ban.add(0, 1);
            ban.add(index[v], -1);
            ban.add(index[v] + tr.subtree_size[v], 1);
            ban.add(N, -1);
        }
    };

    F0R (v, U) {
        trav (u, occur[v])
            bit.add(index[u], 1);

        trav (u, occur[v]) {
            bool found = 0;
            trav (e, tr.neighbors[u]) {
                int ct = get_count(u, e);
                if (ct > 0) {
                    if (found) {
                        cerr << "3 collinear" << endl;
                        ps(0);
                        return 0;
                    } else {
                        found = 1;
                        ban_away(u, e);
                    }
                }
            }
        }

        trav (u, occur[v])
            bit.add(index[u], -1);
    }

    int ok = 0;

    FOR (len, 1, N + 1) {
        if (!ban.accumulate_prefix(len))
            ok++;
    }

    ps(ok);

    return 0;
}