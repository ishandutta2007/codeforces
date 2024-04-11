#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

struct union_find {
    vector<int> P, R, S;

    union_find(int N) {
        P.resize(N), R.resize(N, 0), S.resize(N, 1);
        for (int i = 0; i < N; i++)
            P[i] = i;
    }

    int rep(int i) {
        if(P[i] != i) P[i] = rep(P[i]);
        return P[i];
    }

    bool unio(int a, int b) {
        a = rep(a), b = rep(b);
        if(a == b) return false;
        if(R[a] < R[b]) swap(a, b);
        P[b] = a;
        S[a] += S[b];
        if(R[a] == R[b]) R[a]++;
        return true;
    }
};

template<typename T> struct seg_tree {
    int S;

    T zero;
    vector<T> value;

    seg_tree<T>(int _S = 0, T _zero = T()) {
        S = _S, zero = _zero;
        value.resize(2*S+1, zero);
    }

    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);

        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }

    T query(int i) {
        i += S;
        T res = value[i];
        while(i>1){
            i/=2;
            res = res + value[i];
        }
        return res;
    }

    void upd(int i, int j, T v) {
        for(i += S, j += S; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) value[i] = value[i] + v, i++;
            if((j&1) == 0) value[j] = value[j] + v, j--;
        }
    }
};

struct lca {
    int L, N;
    vector<int> depth, size, link;

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

template<typename T> struct heavy_light {
    lca links;
    seg_tree<T> st;
    vector<int> preorder, index, jump;

    heavy_light(const vvi &graph, int root) {
        links = lca(graph, 0);

        st = seg_tree<T>(graph.size());
        index.resize(graph.size()), jump.resize(graph.size()),
        preorder.resize(graph.size());
        dfs(root, root, root, graph, 0);
    }

    int dfs(int loc, int par, int lhv, const vvi &graph, int inx) {
        jump[loc] = lhv;
        index[loc] = inx;
        preorder[inx++] = loc;

        vector<int> ch = graph[loc];
        sort(ch.begin(), ch.end(), [&](int i, int j) {
            return links.size[i] > links.size[j]; });
        if (loc != par) ch.erase(ch.begin());

        for (int c = 0; c < ch.size(); c++)
            inx = dfs(ch[c], loc, c ? ch[c] : lhv, graph, inx);
        return inx;
    }

    void __assign(int u, int r, T update) {
        while (u != r) {
            int go = max(index[r] + 1, index[jump[u]]);
            st.upd(go, index[u], update);
            u = links.link[preorder[go]];
        }
    }

    void assign(int u, int v, T update) {
        int r = links.find(u, v);
        __assign(u, r, update);
        __assign(v, r, update);
    }
};

struct T {
    int v;
    T(int _v = INT_MAX) { v = _v; }
    T operator+(const T &o) const {
        return T(min(v, o.v));
    }
    T operator()(const T &o) const {
        return T(min(v, o.v));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K, M;
    cin >> N >> K >> M;

    union_find ufa(N);
    vvi tree(N);

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
        ufa.unio(a, b);
    }

    ll ans = 0;
    vi a(M), b(M), w(M);

    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> w[i];
        a[i]--, b[i]--;
        if (ufa.unio(a[i], b[i])) {
            ans -= w[i];
            tree[a[i]].push_back(b[i]);
            tree[b[i]].push_back(a[i]);
        }
    }

    heavy_light<T> hld(tree, 0);
    for (int i = 0; i < M; i++) {
        hld.assign(a[i], b[i], T(w[i]));
    }

    for (int i = 1; i < N; i++) {
        int ew = hld.st.query(i).v;
        if (ew == INT_MAX) {
            cout << -1 << endl;
            return 0;
        }
        ans += ew;
    }

    cout << ans << endl;
    return 0;
}