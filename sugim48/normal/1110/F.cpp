#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

ll INF = LLONG_MAX / 10;
 
template <class Unko>
struct lazy_segtree {
    using T1 = typename Unko::T1;
    using T2 = typename Unko::T2;
    int N, H;
    vector<T1> a;
    vector<T2> b;
    lazy_segtree(int _N) {
        for (N = 1, H = 0; N < _N; N *= 2, H++);
        a.assign(N * 2, Unko::id1());
        b.assign(N * 2, Unko::id2());
    }
    void up(int i) {
        while (i>>=1) {
            T1 xl = Unko::op21(b[i<<1], a[i<<1]);
            T1 xr = Unko::op21(b[i<<1 | 1], a[i<<1 | 1]);
            a[i] = Unko::op11(xl, xr);
        }
    }
    void down(int i0) {
        for (int h = H; h > 0; h--) {
            int i = i0>>h;
            a[i] = Unko::op21(b[i], a[i]);
            b[i<<1] = Unko::op22(b[i], b[i<<1]);
            b[i<<1 | 1] = Unko::op22(b[i], b[i<<1 | 1]);
            b[i] = Unko::id2();
        }
    }
    T1 get(int l, int r) {
        if (l == r) return Unko::id1();
        l += N; r += N;
        down(l); down(r - 1);
        T1 xl = Unko::id1(), xr = Unko::id1();
        for (; l < r; l>>=1, r>>=1) {
            if (l & 1) xl = Unko::op11(xl, Unko::op21(b[l], a[l])), l++;
            if (r & 1) r--, xr = Unko::op11(Unko::op21(b[r], a[r]), xr);
        }
        return Unko::op11(xl, xr);
    }
    void set(int i, T1 x) {
        i += N;
        down(i);
        a[i] = x;
        up(i);
    }
    void apply(int l0, int r0, T2 y) {
        if (l0 == r0) return;
        l0 += N; r0 += N;
        down(l0); down(r0 - 1);
        for (int l = l0, r = r0; l < r; l>>=1, r>>=1) {
            if (l & 1) b[l] = Unko::op22(y, b[l]), l++;
            if (r & 1) r--, b[r] = Unko::op22(y, b[r]);
        }
        up(l0); up(r0 - 1);
    }
};
 
struct unko {
    using T1 = ll;
    using T2 = ll;
    static T1 id1() { return INF; }
    static T2 id2() { return 0; }
    static T1 op11(const T1 &xl, const T1 &xr) {
        return min(xl, xr);
    }
    static T1 op21(const T2 &y, const T1 &x) {
        return y + x;
    }
    static T2 op22(const T2 &yl, const T2 &yr) {
        return yl + yr;
    }
};

struct Edge { int v, w; };

int N, Q;
vector<Edge> G[500000];
ll dep[500000];
int el[500000], er[500000];
vector<int> qs[500000];
int ql[500000], qr[500000];
ll ans[500000];

void dfs_dep(int u, int p) {
    for (Edge e: G[u]) if (e.v != p) {
        dep[e.v] = dep[u] + e.w;
        dfs_dep(e.v, u);
    }
}

void dfs_e(int u, int p) {
    el[u] = u;
    er[u] = u + 1;
    for (Edge e: G[u]) if (e.v != p) {
        dfs_e(e.v, u);
        er[u] = max(er[u], er[e.v]);
    }
}

void dfs_q(int u, int p, lazy_segtree<unko>& st) {
    for (int q: qs[u])
        ans[q] = st.get(ql[q], qr[q]);
    for (Edge e: G[u]) if (e.v != p) {
        st.apply(0, N, e.w);
        st.apply(el[e.v], er[e.v], -e.w * 2);
        dfs_q(e.v, u, st);
        st.apply(0, N, -e.w);
        st.apply(el[e.v], er[e.v], e.w * 2);
    }
}

int main() {
    cin >> N >> Q;
    for (int u = 1; u < N; u++) {
        int p, w;
        scanf("%d%d", &p, &w);
        p--;
        G[p].pb(Edge{u, w});
        G[u].pb(Edge{p, w});
    }
    dfs_dep(0, -1);
    dfs_e(0, -1);
    rep(q, Q) {
        int u, l, r;
        scanf("%d%d%d", &u, &l, &r);
        u--; l--;
        qs[u].pb(q);
        ql[q] = l;
        qr[q] = r;
    }
    lazy_segtree<unko> st(N);
    rep(u, N) if (er[u] - el[u] == 1) st.apply(u, u + 1, dep[u] - INF);
    dfs_q(0, -1, st);
    rep(q, Q) printf("%lld\n", ans[q]);
}