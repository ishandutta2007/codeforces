#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

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

void solve(int loc, int par, const vvi &adj, lca &links, vi &res) {
    int big = -1;

    for (int ch : adj[loc]) {
        if (ch == par) continue;
        solve(ch, loc, adj, links, res);

        if (links.size[ch] * 2 > links.size[loc])
            big = ch;
    }

    if (big == -1) {
        res[loc] = loc;
        return;
    }

    int cent = res[big];

    for (int l = links.L - 1; l >= 0; l--) {
        int cand = links.link[l*links.N + cent];
        if (links.depth[cand] <= links.depth[loc]) continue;

        int above = links.size[loc] - links.size[cand];
        if (2 * above > links.size[loc])
            cent = cand;
    }

    while (2 * (links.size[loc] - links.size[cent]) > links.size[loc])
        cent = links.link[cent];

    res[loc] = cent;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, Q;
    cin >> N >> Q;

    vvi adj(N);

    for (int i = 1; i < N; i++) {
        int par;
        cin >> par;
        par--;

        adj[i].push_back(par);
        adj[par].push_back(i);
    }

    lca links(adj, 0);
    vi res(N);

    solve(0, 0, adj, links, res);

    for (int i = 0; i < Q; i++) {
        int que;
        cin >> que;
        cout << res[que-1] + 1 << "\n";
    }

    return 0;
}