#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> ii;
 
const int MAXN = 2e5 + 5;
const ll INF = 1e16;
 
int le[MAXN], ri[MAXN], pos[MAXN], n, m, q;
bool in_path[MAXN];
 
struct edge {
    int to, idx;
    ll wt;
};
 
array<int, 3> edges[MAXN];
vector<edge> adj[MAXN];
vector<int> path_idx;
 
void dijkstra(int src, vector<ll> &dis, bool keep = false) {
    fill(dis.begin(), dis.end(), INF);
    vector<ii> pre(dis.size());
    dis[src] = 0;
    priority_queue<ii> q;
    q.push({0, src});
    int sgn = 0;
    if(!keep)
        sgn = (src == 1 ? 1 : -1);
    while(!q.empty()) {
        auto p = q.top(); q.pop();
        int u = p.second;
        if(dis[u] < p.first) continue;
        for(auto e : adj[u]) {
            int v = e.to;
            if(dis[v] > dis[u] + e.wt) {
                dis[v] = dis[u] + e.wt;
                q.push({-dis[v], v});
                pre[v] = {u, e.idx};
                if(!keep && !in_path[v]) {
                    if(sgn == 1)
                        le[v] = le[u];
                    else
                        ri[v] = ri[u];
                }
            }
        }
    }
    if(keep) {
        int s = n;
        while(s != 1) {
            path_idx.push_back(pre[s].second);
            s = pre[s].first;
        }
        int L = path_idx.size();
        s = n;
        while(s != 1) {
            le[s] = ri[s] = L--;
            in_path[s] = true;
            s = pre[s].first;
        }
        in_path[1] = true;
        reverse(path_idx.begin(), path_idx.end());
    }
}
 
struct node {
    int l, r;
    ll mn, lazy;
    node *left, *right;
 
    inline ll get() { return (lazy == -1 ? mn : lazy); }
    inline void merge() { mn = min(left->get(), right->get()); }
    inline void compose(ll val) {
        if(val == -1) return;
        if(lazy == -1) lazy = val;
        else lazy = min(val, lazy);
    }
    inline void push() { left->compose(lazy); right->compose(lazy); lazy = -1; }
 
    node(int l, int r) : l(l), r(r), mn(INF), lazy(-1) {
        if(l != r) {
            int mi = (l + r)/2;
            left = new node(l, mi);
            right = new node(mi + 1, r);
            merge();
        }
    }
 
    void upd(int rl, int rr, ll val) {
        if(rr < l || r < rl) return;
        if(rl <= l && r <= rr) { compose(val); return; }
        push();
        left->upd(rl, rr, val);
        right->upd(rl, rr, val);
        merge();
    }
 
    ll qry(int p) {
        if(l == r) return get();
        push();
        merge();
        if(p <= left->r) return left->qry(p);
        else return right->qry(p);
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, i + 1, w});
        adj[v].push_back({u, i + 1, w});
        edges[i + 1] = {u, v, (int)w};
    }
    vector<ll> idis(n + 1), odis(n + 1);
    dijkstra(1, idis, true);

    memset(pos, -1, sizeof pos);
    for(int i = 0; i < path_idx.size(); i++)
        pos[path_idx[i]] = i;

    dijkstra(1, idis);
    dijkstra(n, odis);
 
    node tree(0, path_idx.size() - 1);
 
    for(int i = 1; i <= m; i++) {
        if(pos[i] >= 0) continue;
        int u = edges[i][0], v = edges[i][1];
        ll dis = idis[u] + odis[v] + edges[i][2];
        int L = le[u], R = ri[v] - 1;
        if(L <= R) 
            tree.upd(L, R, dis);
        dis = idis[v] + odis[u] + edges[i][2];
        L = le[v], R = ri[u] - 1;
        if(L <= R)
            tree.upd(L, R, dis);
    }
 
    while(q--) {
        int idx, w;
        cin >> idx >> w;
        if(pos[idx] == -1) {
            int u = edges[idx][0], v = edges[idx][1];
            cout << min({idis[u] + w + odis[v], idis[v] + w + odis[u], idis[n]}) << '\n';
        }
        else {
            if(w <= edges[idx][2]) {
                ll del = w - edges[idx][2];
                cout << idis[n] + del << '\n';
            }
            else {
                ll del = w - edges[idx][2];
                int p = pos[idx];
                cout << min(idis[n] + del, tree.qry(p)) << '\n';
            }
        }
    }
}