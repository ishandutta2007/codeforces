#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5;
const int INF = 1e9;

int N, M;
vector<int> adj[MAXN];

bool targ[MAXN];
int subt[MAXN];
int depth[MAXN];

void dfs(int loc, int par, int dep) {
    depth[loc] = dep;
    if (targ[loc])
        subt[loc] = 1;

    for (int v : adj[loc]) {
        if (v != par) {
            dfs(v, loc, dep+1);
            subt[loc] += subt[v];
        }
    }
}

vector<int> verts;
void rebuild(vector<pair<int, int>> pruned) {
    for (auto p : pruned) {
        verts.push_back(p.first);
        verts.push_back(p.second);
    }

    sort(verts.begin(), verts.end());
    verts.resize(unique(verts.begin(), verts.end()) - verts.begin());

    for (int i = 0; i < N; i++)
        adj[i].clear();

    N = verts.size();

    for (auto p : pruned) {
        int u = lower_bound(verts.begin(), verts.end(), p.first) - verts.begin();
        int v = lower_bound(verts.begin(), verts.end(), p.second) - verts.begin();

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(int src, vector<int> &dist) {
    dist.resize(N, INF);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int loc = q.front();
        q.pop();

        for (int v : adj[loc]) {
            if (dist[v] != INF) continue;
            dist[v] = 1 + dist[loc];
            q.push(v);
        }
    }
}

pair<int, int> diam() {
    vector<int> d1, d2;

    bfs(0, d1);

    int f = 0;
    for (int i = 0; i < N; i++)
        if (d1[i] > d1[f]) 
            f = i;

    bfs(f, d2);

    int g = 0;
    for (int i = 0; i < N; i++) 
        if (d2[i] > d2[g])
            g = i;

    return make_pair(d2[g], min(f, g));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    vector<pair<int, int>> edges;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        edges.emplace_back(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < M; i++) {
        int V;
        cin >> V;
        targ[V-1] = true;
    }

    dfs(0, 0, 0);

    vector<pair<int, int>> pruned;

    for (auto p : edges) {
        int u = p.first;
        int v = p.second;

        if (depth[u] < depth[v]) swap(u, v);
        if (subt[u] != 0 && subt[u] != M) {
            pruned.emplace_back(u, v);
        }
    }

    int ans = pruned.size() * 2;
    rebuild(pruned);
    if (N > 1) {
        pair<int, int> res = diam();
        ans -= res.first;
        cout << verts[res.second] + 1 << "\n";
    }
    else {
        // start from anyone with a human
        for (int i = 0; ; i++)
            if (targ[i]) {
                cout << i + 1 << "\n";
                break;
            }
    }
    cout << ans << "\n";
}