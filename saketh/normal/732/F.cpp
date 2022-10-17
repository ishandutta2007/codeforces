#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

void find_bridges(int loc, int par, vvi &adj, vi &u, vi &v, vi &depth, vi &lp) {
    if (loc != par) depth[loc] = depth[par] + 1;
    else depth[loc] = 0;
    lp[loc] = depth[loc];

    for (int e : adj[loc]) {
        int nbr = u[e] + v[e] - loc;
        if (depth[nbr] == -1) {
            find_bridges(nbr, loc, adj, u, v, depth, lp);
            lp[loc] = min(lp[loc], lp[nbr]);
        } else if (nbr != par) {
            lp[loc] = min(lp[loc], depth[nbr]);
        }
    }
}

void bicomp(int loc, vvi &adj, vi &u, vi &v, int cn, vi &comp, vi &size, vb &bridge) {
    if (comp[loc] != -1) return;
    comp[loc] = cn;
    size[cn]++;

    for (int e : adj[loc]) {
        if (bridge[e]) continue;
        int nbr = u[e] + v[e] - loc;
        bicomp(nbr, adj, u, v, cn, comp, size, bridge);
    }
}

void dfs(int loc, int dep, vvi &adj, vi &u, vi &v, vi &depth, vb &used) {
    depth[loc] = dep;
    for (int e : adj[loc]) {
        int nbr = u[e] + v[e] - loc;
        if (depth[nbr] == -1) {
            used[e] = true;
            dfs(nbr, dep + 1, adj, u, v, depth, used);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vvi adj(N);
    vi u(M), v(M);

    for (int e = 0; e < M; e++) {
        cin >> u[e] >> v[e];
        u[e]--, v[e]--;
        adj[u[e]].push_back(e);
        adj[v[e]].push_back(e);
    }

    vi depth(N, -1), lp(N);
    find_bridges(0, 0, adj, u, v, depth, lp);

    vb bridge(M);
    for (int e = 0; e < M; e++) {
        if (depth[u[e]] > depth[v[e]]) swap(u[e], v[e]);
        bridge[e] = lp[v[e]] >= depth[v[e]];
    }

    WATCHC(bridge);

    int root = 0;
    vi comp(N, -1), size(N);
    for (int i = 0; i < N; i++) {
        bicomp(i, adj, u, v, i, comp, size, bridge);
        if (size[comp[i]] > size[comp[root]]) root = i;
    }

    vi depth2(N, -1);
    vb used(M);
    dfs(root, 0, adj, u, v, depth2, used);

    WATCHC(depth2);

    cout << size[comp[root]] << "\n";
    for (int e = 0; e < M; e++) {
        if ((depth2[u[e]] > depth2[v[e]]) != used[e])
            swap(u[e], v[e]);
        cout << u[e] + 1 << " " << v[e] + 1 << "\n";
    }

    return 0;
}