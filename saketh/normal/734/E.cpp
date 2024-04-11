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

void flood(int loc, int label, vvi &adj, vi &col, vi &comp) {
    if (comp[loc] != -1) return;
    if (col[loc] != col[label]) return;
    comp[loc] = label;

    for (int v : adj[loc])
        flood(v, label, adj, col, comp);
}

pair<int, int> farthest(vvi &adj, int root) {
    queue<int> bfs({root});
    int last = root;

    vi dist(adj.size(), INT_MAX);
    dist[root] = 0;

    while (!bfs.empty()) {
        int loc = bfs.front();
        bfs.pop();

        last = loc;
        for (int v : adj[loc]) {
            if (dist[v] != INT_MAX) continue;
            dist[v] = dist[loc] + 1;
            bfs.push(v);
        }
    }

    return { last, dist[last] };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi col(N);
    for (int i = 0; i < N; i++)
        cin >> col[i];

    vvi adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vi comp(N, -1);
    for (int i = 0; i < N; i++) {
        flood(i, i, adj, col, comp);
    }

    vvi cadj(N);

    for (int i = 0; i < N; i++) {
        for (int v : adj[i]) {
            if (comp[i] != comp[v])
                cadj[comp[i]].push_back(comp[v]);
        }
    }

    auto r1 = farthest(cadj, 0);
    auto r2 = farthest(cadj, r1.first);
    cout << (r2.second + 1) / 2 << endl;

    return 0;
}