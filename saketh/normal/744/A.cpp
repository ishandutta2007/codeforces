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

void go(int loc, vvi &adj, vb &vis, int &nodes, int &edges) {
    if (vis[loc]) return;

    vis[loc] = true;
    nodes++;
    edges += adj[loc].size();

    for (int nbr : adj[loc])
        go(nbr, adj, vis, nodes, edges);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M, K;
    cin >> N >> M >> K;

    vi govt(K);
    for (int k = 0; k < K; k++) {
        cin >> govt[k];
        govt[k]--;
    }

    vvi adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    int ans = 0;
    int used_nodes = 0, used_edges = 0;
    int maxcomp = 0;

    vb vis(N);

    for (int g : govt) {
        int nodes = 0, edges = 0;
        go(g, adj, vis, nodes, edges);
        edges /= 2;

        ans += nodes * (nodes - 1) / 2 - edges;

        used_nodes += nodes;
        used_edges += edges;
        maxcomp = max(maxcomp, nodes);
    }

    int unused = N - used_nodes;
    int add = unused * maxcomp 
            + unused * (unused - 1) / 2
            - (M - used_edges);

    cout << ans + add << endl;
    return 0;
}