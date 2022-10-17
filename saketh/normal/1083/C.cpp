#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
    sparse_table(const vector<T>& elts = {}) : S(elts.size()) {
        L = 32 - __builtin_clz(S);
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
 * Supports O(1) lowest common ancestor queries on an immutable tree.
 */
struct lowest_common_ancestor {
    struct visit {
        int node, depth;
        visit operator + (const visit& o) const {
            return depth <= o.depth ? *this : o;
        }
    };

    vi depth, pos;
    vector<visit> tour;
    sparse_table<visit> euler;

    // Constructs the lookup table in O(V log V) time and memory
    lowest_common_ancestor(const vvi& tree = {}, int root = 0) {
        if (!tree.size()) return;
        depth.resize(tree.size());
        pos.resize(tree.size());
        dfs(tree, tour, root, root);
        euler = sparse_table<visit>(tour);
    }

    void dfs(const vvi& tree, auto& tour, int loc, int par) {
        pos[loc] = tour.size();
        tour.push_back({ loc, depth[loc] });
        for (int nbr : tree[loc]) if (nbr != par) {
            depth[nbr] = depth[loc] + 1;
            dfs(tree, tour, nbr, loc);
            tour.push_back({ loc, depth[loc] });
        }
    }

    int lca(int u, int v) {
        u = pos[u], v = pos[v];
        if (u > v) swap(u, v);
        return euler.query(u, v).node;
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    bool on_path(int u, int v, int w) {
        return dist(u, v) == (dist(u, w) + dist(w, v));
    }
};

struct node {
    static lowest_common_ancestor lca;

    int u, v;
    node(int u = INT_MAX) : u(u), v(u) {}
    node(int u, int v) : u(u), v(v) {}

    node operator + (const node& o) const {
        if (u == INT_MAX) return o;
        if (o.u == INT_MAX) return *this;
        if (u == -1 || o.u == -1) return node(-1);

        if (lca.on_path(u, v, o.u) && lca.on_path(u, v, o.v)) return node(u, v);
        if (lca.on_path(u, o.u, v) && lca.on_path(u, o.u, o.v)) return node(u, o.u);
        if (lca.on_path(u, o.v, v) && lca.on_path(u, o.v, o.u)) return node(u, o.v);
        if (lca.on_path(v, o.u, u) && lca.on_path(v, o.u, o.v)) return node(v, o.u);
        if (lca.on_path(v, o.v, u) && lca.on_path(v, o.v, o.u)) return node(v, o.v);
        if (lca.on_path(o.v, o.u, u) && lca.on_path(o.v, o.u, v)) return node(o.u, o.v);

        return node(-1);
    }
};
lowest_common_ancestor node::lca;

/*
 * Supports O(logS) range queries and updates on an array of items.
 * Requires that type T's combine operator is associative and
 * that T() + t = t + T() = t for all T t.
 */
template<typename T> struct seg_tree {
    int S;
    vector<T> value;

    seg_tree<T>(int S) : S(S) {
        value.resize(2 * S);
    }

    // Rebuilds all non-leaf layers of the tree in O(S)
    void rebuild() {
        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }

    // Replaces the value at index i with v in O(logS)
    void upd(int i, T v) {
        i += S;
        value[i] = v;
        while (i > 1) {
            i /= 2;
            value[i] = value[2 * i] + value[2 * i + 1];
        }
    }

    // Returns the sum of the values at indices [i, j] in O(logS)
    T query(int i, int j) {
        T res_left, res_right;
        for (i += S, j += S; i <= j; i /= 2, j /= 2) {
            if ((i&1) == 1) res_left = res_left + value[i++];
            if ((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

template<typename T> struct full_seg_tree : seg_tree<T> {
    int _S;
    full_seg_tree<T>(int _S) : _S(_S), seg_tree<T>(1 << (32 - __builtin_clz(_S - 1))) { }

    /*
     * Returns in O(logS) the first index i such that pred(query(0, i)) evaluates to true.
     * Returns S if no such i exists.
     * pred(query(0, i)) should be monotonic in i.
     */
    int lower_bound(function<bool(T)> pred) {
        if (!pred(this->value[1])) return this->_S;
        T pref;
        int v = 1;
        for (int i = 0, j = this->S - 1; v < this->S; ) {
            int m = (j + i) / 2;
            if (pred(pref + this->value[2 * v])) {
                j = m;
                v = 2 * v;
            } else {
                pref = pref + this->value[2 * v];
                i = m + 1;
                v = 2 * v + 1;
            }
        }
        return v - this->S;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi perm(N);
    for (int i = 0; i < N; i++)
        cin >> perm[i];

    vi par(N);
    vvi tree(N);
    for (int i = 1; i < N; i++) {
        cin >> par[i];
        tree[--par[i]].push_back(i);
    }

    node::lca = lowest_common_ancestor(tree);
    full_seg_tree<node> st(N);
    for (int i = 0; i < N; i++) {
        st.value[st.S + perm[i]] = node(i);
    }
    st.rebuild();

    int Q, t, u, v;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        cin >> t;
        if (t == 1) {
            cin >> u >> v;
            --u, --v;
            swap(perm[u], perm[v]);
            st.upd(perm[u], u);
            st.upd(perm[v], v);
        } else {
            cout << st.lower_bound([](const node& n) { return n.u == -1; }) << "\n";
        }
    }

    return 0;
}