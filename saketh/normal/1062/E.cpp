#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct lca {
    int L, N;
    vi depth, size, link;

    lca(){}
    lca(const vvi &graph, int root = 0) {
        N = graph.size();
        for (L = 0; (1 << L) <= N; L++);

        depth.resize(N);
        size.resize(N);
        link.resize(L*N);
        init(root, root, graph);
    }

    void init(int loc, int par, const vvi &graph) {
        link[loc] = par;
        for (int l = 1; l < L; l++)
            link[l*N + loc] = link[(l-1)*N + link[(l-1)*N + loc]];

        for (int nbr : graph[loc]) {
            if (nbr == par) continue;
            depth[nbr] = depth[loc] + 1;
            init(nbr, loc, graph);
            size[loc] += size[nbr];
        }

        size[loc]++;
    }

    int above(int loc, int dist) {
        for (int l = 0; l < L; l++)
            if ((dist >> l)&1)
                loc = link[l*N + loc];
        return loc;
    }

    int find(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        v = above(v, depth[v] - depth[u]);
        if (u == v) return u;

        for (int l = L - 1; l >= 0; l--) {
            if (link[l*N + u] != link[l*N + v])
                u = link[l*N + u], v = link[l*N + v];
        }

        return link[u];
    }
};

struct node {
    int s0, s1, b0, b1;
    node() {
        s0 = s1 = INT_MAX;
        b0 = b1 = INT_MIN;
    }
    node(int v) {
        s0 = v;
        s1 = INT_MAX;
        b0 = INT_MIN;
        b1 = v;
    }
    node(int _s0, int _s1, int _b0, int _b1) : s0(_s0), s1(_s1), b0(_b0), b1(_b1) {
    }
    node operator+(const node& o) {
        auto ssort = [](array<int, 4> &v) {
            for (int i = 1; i < 4; i++) {
                for (int j = i; j > 0; j--) {
                    if (v[j] < v[j-1]) {
                        swap(v[j], v[j-1]);
                    } else break;
                }
            }
        };

        array<int, 4> smalls = { s0, s1, o.s0, o.s1 };
        ssort(smalls);
        array<int, 4> bigs = { b0, b1, o.b0, o.b1 };
        ssort(bigs);
        return { smalls[0], smalls[1], bigs[2], bigs[3] };
    }
};

template<typename T> struct seg_tree {
    int S;

    T zero;
    vector<T> value;

    seg_tree<T>(int _S, T _zero = T()) {
        S = _S, zero = _zero;
        value.resize(2*S+1, zero);
    }

    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);

        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }

    void upd(int i, T v) {
        i += S;
        value[i] = v;
        while(i>1){
            i/=2;
            value[i] = value[2*i] + value[2*i+1];
        }
    }

    T query(int i, int j) {
        T res_left = zero, res_right = zero;
        for(i += S, j += S; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

void go(vvi &adj, vi &dep, vi &ord, vi &inv, int &vis, int loc) {
    ord[loc] = vis++;
    inv.push_back(loc);
    for (int ch : adj[loc]) {
        dep[ch] = dep[loc] + 1;
        go(adj, dep, ord, inv, vis, ch);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, Q;
    cin >> N >> Q;

    vvi adj(N);
    for (int i = 1; i < N; i++) {
        int par;
        cin >> par;
        adj[par-1].push_back(i);
    }

    lca anc(adj, 0);
    vi dep(N), ord(N), inv;
    int vis = 0;
    go(adj, dep, ord, inv, vis, 0);

    seg_tree<node> st(N);
    vector<node> leaves(N);
    for (int i = 0; i < N; i++) {
        leaves[i] = node(ord[i]);
    }
    st.set_leaves(leaves);

    int l, r;
    for (int q = 0; q < Q; q++) {
        cin >> l >> r;
        node n = st.query(l-1, r-1);

        int c1 = anc.find(inv[n.s1], inv[n.b1]);
        int c2 = anc.find(inv[n.s0], inv[n.b0]);

        if (dep[c1] > dep[c2]) {
            cout << inv[n.s0] + 1 << " " << dep[c1] << "\n";
        } else {
            cout << inv[n.b1] + 1 << " " << dep[c2] << "\n";
        }
    }

    return 0;
}