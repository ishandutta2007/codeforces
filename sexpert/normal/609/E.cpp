#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> qry;

const int MAXN = 2e5 + 10;
const int LG = 20;
int rep[MAXN], dead[MAXN], mx[MAXN], res[MAXN], sz[MAXN], tree[MAXN], n, m;
vector<ii> adj[MAXN];

/***************************************
*******ESTA PARTE ENCUENTRA EL MST******
***************************************/
int find(int u) {
    return rep[u] ? rep[u] = find(rep[u]) : u;
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v)
        return false;
    rep[v] = u;
    return true;
}

struct edge {
    int u, v, w;
    bool operator< (const edge &o) const {
        return w < o.w;
    }
};

vector<edge> edges;

ll kruskal() {
    vector<edge> tmp = edges;
    sort(tmp.begin(), tmp.end());
    ll res = 0;
    for(auto &e : tmp) {
        if(join(e.u, e.v)) {
            res += e.w;
            adj[e.u].push_back({e.v, e.w});
            adj[e.v].push_back({e.u, e.w});
        }
    }
    return res;
}
/***************************************
**FIN DE LA PARTE QUE ENCUENTRA EL MST**
***************************************/

void dfs_sz(int s, int p = 0) {
    sz[s] = 1;
    for(auto e : adj[s]) {
        int v = e.first;
        if(v == p || dead[v])
            continue;
        dfs_sz(v, s);
        sz[s] += sz[v];
    }
}

int get_cen(int s, int root, int p = 0) {
    for(auto e : adj[s]) {
        int v = e.first;
        if(v == p || dead[v])
            continue;
        if(2 * sz[v] > sz[root])
            return get_cen(v, root, s);
    }
    return s;
}

void calc(int s, int wei = 0, int tr = -1, int p = 0) {
    mx[s] = wei;
    tree[s] = tr;
    int ctr = 0;
    for(auto e : adj[s]) {
        int v = e.first;
        if(v == p || dead[v]) {
            ctr++;
            continue;
        }
        calc(v, max(wei, e.second), (tr == -1 ? ctr : tr), s);
        ctr++;
    }
}

void solve(int s, vector<qry> &qs) {
    dfs_sz(s);
    s = get_cen(s, s);
    calc(s);
    vector<vector<qry>> rec(adj[s].size());
    for(auto q : qs) {
        if(tree[q[0]] != tree[q[1]])
            res[q[2]] = max(mx[q[0]], mx[q[1]]);
        else
            rec[tree[q[0]]].push_back({q[0], q[1], q[2]});
    }
    dead[s] = 1;
    for(int i = 0; i < adj[s].size(); i++) {
        if(dead[adj[s][i].first])
            continue;
        solve(adj[s][i].first, rec[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    ll ans = kruskal();
    vector<qry> qs;
    for(int i = 0; i < edges.size(); i++)
        qs.push_back({edges[i].u, edges[i].v, i});
    solve(1, qs);
    for(int i = 0; i < edges.size(); i++)
        cout << ans - res[i] + edges[i].w << '\n';
}