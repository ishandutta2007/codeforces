#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template <size_t I> struct index_t {};
#define _i(i, v) const index_t<i> v{}
_i(0, _0); _i(1, _1); _i(2, _2); _i(3, _3); _i(4, _4);
template<typename... T> struct tp {
    std::tuple<T...> elts;
    tp() {}
    tp(std::tuple<T...> _t) : elts(_t) {}
    template<typename T1, typename... Ts> tp(T1 t1, Ts... ts) : elts(t1, ts...) {}
    template <size_t I> decltype(auto) operator[](index_t<I>) {
        return get<I>(this->elts);
    }
    template <size_t I> decltype(auto) operator[](index_t<I>) const {
        return get<I>(this->elts);
    }
    friend bool operator <(const tp& a, const tp& b) { return a.elts < b.elts; }
};

namespace output {
    template<typename T, size_t... I> void print_tuple(ostream& o,
            const T& t, index_sequence<I...>) {
        o << "("; ((o << (I ? ", " : "") << get<I>(t)), ...); o << ")";
    }
    template<typename... T> ostream& operator<<(ostream& o,
            const tp<T...>& t) {
        print_tuple(o, t.elts, index_sequence_for<T...>{}); return o;
    }
    template<typename T1, typename T2> ostream& operator<<(ostream& o,
            const pair<T1, T2>& t) {
        return o << "(" << t.first << ", " << t.second << ")";
    }
    template<typename T, size_t N> ostream& operator<<(ostream& o,
            const array<T, N>& a) {
        o << "[";
        for (int i = 0; i < N; i++) { if (i) o << ", "; o << a[i]; }
        return o << "]";
    }
    template<typename T> ostream& operator<<(ostream& o,
            const vector<T>& v) {
        o << "[";
        for (int i = 0; i < sz(v); i++) { if (i) o << ", "; o << v[i]; }
        return o << "]";
    }
}
using namespace output;

/*
 * Supports O(1) range queries on an immutable array of items.
 * Requires that type T's combine operator is associate, commutative,
 * and idempotent.
 */
template<typename T> struct sparse_table {
    int S, L;
    vector<T> table;
    T& entry(int l, int i) { return table[l * S + i]; }

    // Constructs the table in O(S log S) time and memory
    sparse_table(const vector<T>& elts = {}) : S(sz(elts)) {
        L = S ? 32 - __builtin_clz(S) : 0;
        table.resize(L * S);
        copy(all(elts), table.begin());

        for (int l = 0; l + 1 < L; l++) {
            for (int i = 0; i < S; i++) {
                entry(l + 1, i) = entry(l, i);
                if (i + (1 << l) < S)
                    entry(l + 1, i) = entry(l + 1, i) + entry(l, i + (1 << l));
            }
        }
    }

    // Returns elts[i] + ... + elts[j] in O(1)
    T query(int i, int j) {
        int l = 31 - __builtin_clz(j - i + 1);
        return entry(l, i) + entry(l, j - (1 << l) + 1);
    }
};

/*
 * Supports O(1) lowest common ancestor queries on an immutable forest.
 */
struct lowest_common_ancestor {
    struct visit {
        int node, depth;
        visit operator + (const visit& o) const {
            return depth <= o.depth ? *this : o;
        }
    };

    vi depth, pos, comp;
    sparse_table<visit> euler;

    lowest_common_ancestor(const vvi& tree = {}, int root = -1) {
        depth.resize(sz(tree));
        comp.resize(sz(tree), -1);
        pos.resize(sz(tree), -1);

        vector<visit> tour; int cc = 0;
        auto dfs = [&](auto& self, int loc, int par) -> void {
            comp[loc] = cc, pos[loc] = sz(tour);
            tour.push_back({ loc, depth[loc] });
            for (int nbr : tree[loc]) if (nbr != par) {
                depth[nbr] = depth[loc] + 1;
                self(self, nbr, loc);
                tour.push_back({ loc, depth[loc] });
            }
        };
        if (root != -1) dfs(dfs, root, root), cc++;
        for (int i = 0; i < sz(tree); i++)
            if (comp[i] == -1) dfs(dfs, i, i), cc++;
        euler = sparse_table<visit>(tour);
    }

    // Returns the lowest common ancestor of u and v
    // Returns -1 if they are in different components
    int lca(int u, int v) {
        if (comp[u] != comp[v]) return -1;
        u = pos[u], v = pos[v];
        if (u > v) swap(u, v);
        return euler.query(u, v).node;
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    // Checks if btw is on the path from u to v. Careful!
    bool on_path(int u, int v, int btw) {
        return dist(u, v) == (dist(u, btw) + dist(btw, v));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;

    vvi adj(N);
    vector<array<int, 2>> edge(M);
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        edge[i] = { --u, --v };
        adj[u].pb(i);
        adj[v].pb(i);
    }

    vvi from(N), to(N);
    vector<array<int, 2>> msg(Q);
    for (int i = 0, s, t; i < Q; i++) {
        cin >> s >> t;
        assert(1 <= s && s <= N);
        assert(1 <= t && t <= N);
        msg[i] = { --s, --t };
        from[s].pb(i);
        to[t].pb(i);
    }

    int CC = 0, SCC = 0;
    vi cc(N, -1), scc(N, -1);
    vvi scc_elts;

    auto dfs = [&](auto& self, int loc, int ine) -> int {
        static int V = 0, st = 0;
        static vi index(N), stack(N + 1, -1);

        int low = index[loc] = V++;
        stack[st++] = loc;
        cc[loc] = CC;

        for (int e : adj[loc]) if (e != ine) {
            int nbr = edge[e][0] + edge[e][1] - loc;
            if (cc[nbr] == -1) ckmin(low, self(self, nbr, e));
            else ckmin(low, index[nbr]);
        }

        if (low == index[loc]) {
            scc_elts.pb({});
            while (stack[st] != loc) {
                scc[stack[--st]] = SCC;
                scc_elts[SCC].pb(stack[st]);
            }
            SCC++;
        }

        return low;
    };
    for (int i = 0; i < N; i++)
        if (cc[i] == -1) {
            dfs(dfs, i, -1);
            assert(cc[i] != -1);
            assert(scc[i] != -1);
            CC++;
        }

    vvi forest(SCC);
    for (auto [u, v] : edge) {
        if (scc[u] != scc[v]) {
            forest[scc[u]].pb(scc[v]);
            forest[scc[v]].pb(scc[u]);
        }
    }
    vi up(SCC), down(SCC);

    lowest_common_ancestor lca(forest);

    for (auto [_s, _t] : msg) {
        int s = scc[_s], t = scc[_t], m = lca.lca(s, t);
        if (m == -1) { cout << "No\n"; return 0; }
        ckmax(up[s], lca.dist(s, m));
        ckmax(down[t], lca.dist(m, t));
    }

    vb vis(SCC);
    auto dfs2 = [&](auto& self, int loc, int par) -> int {
        vis[loc] = true;
        int sm = 0, lg = 0;
        for (int nbr : forest[loc]) if (nbr != par) {
            int sv = self(self, nbr, loc);
            if (sv < 0) ckmin(sm, ++sv);
            if (sv > 0) ckmax(lg, --sv);
        }
        ckmin(sm, -down[loc]);
        ckmax(lg, up[loc]);
        if (sm && lg) { cout << "No\n"; exit(0); }
        return sm ^ lg;
    };
    for (int i = 0; i < SCC; i++) if (!vis[i]) dfs2(dfs2, i, i);

    cout << "Yes\n";

    return 0;
}