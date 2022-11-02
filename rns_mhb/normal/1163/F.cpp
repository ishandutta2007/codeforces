#include<bits/stdc++.h>
using namespace std;

#define N 200010

typedef long long ll;
typedef pair <ll, int> pli;

const ll INF = 1e18;

vector <int> adj[N];
int n, m, u[N], v[N], w[N];

vector <int> nxt[N];
int p[N], L[N];
ll d[N], fd[N];
bool chk[N];

void dijkstra(int x) {
    priority_queue <pli> q;
    for(int i = 1; i <= n; i ++) d[i] = INF, p[i] = 0;
    d[x] = 0;
    q.push(pli(0, x));
    while(!q.empty()) {
        pli tp = q.top(); q.pop();
        x = tp.second;
        if(tp.first != -d[x]) continue;
        for(int i = 0; i < adj[x].size(); i ++) {
            int j = adj[x][i];
            int y = u[j] ^ v[j] ^ x;
            ll z = d[x] + w[j];
            if(d[y] <= z) continue;
            p[y] = j, d[y] = z;
            q.push(pli(-z, y));
        }
    }
}

void dfs(int x) {
    if(!L[x]) L[x] = L[u[p[x]]^v[p[x]]^x];
    for(int i = 0; i < nxt[x].size(); i ++) dfs(nxt[x][i]);
}

struct QMR {
    ll val[N<<2], _m;
    void build(int _n) {
        _m = 1 << 33 - __builtin_clz(_n);
        for(int i = 0; i < _m; i ++) val[i] = INF;
    }
    void update(int l, int r, ll x) {
        l += _m >> 1, r += _m >> 1;
        while(l <= r) {
            val[l] = min(val[l], x);
            val[r] = min(val[r], x);
            l = l + 1 >> 1, r = r - 1 >> 1;
        }
    }
    ll query(int x) {
        ll ret = INF;
        x += _m >> 1;
        while(x) {
            ret = min(ret, val[x]);
            x >>= 1;
        }
        return ret;
    }
} T;


int main() {
    int q;
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= m; i ++) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        adj[u[i]].push_back(i);
        adj[v[i]].push_back(i);
    }
    int src = 1, dst = n;
    dijkstra(dst);
    for(int i = 1; i <= n; i ++) fd[i] = d[i];
    dijkstra(src);
    for(int i = 1; i <= n; i ++) if(p[i]) nxt[u[p[i]]^v[p[i]]^i].push_back(i);
    vector <int> path;
    for(int x = dst; x != src; x=u[p[x]]^v[p[x]]^x) path.push_back(x);
    path.push_back(src);
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i ++) {
        L[path[i]] = i + 1;
        if(i) chk[p[path[i]]] = 1;
    }
    dfs(src);
    T.build(path.size() + 4);
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < adj[i].size(); j ++) {
            int k = adj[i][j];
            int x = i, y = u[k] ^ v[k] ^ i;
            if(L[x] >= L[y]) continue;
            if(chk[k]) continue;
            T.update(L[x], L[y] - 1, d[x]+fd[y]+w[k]);
        }
    }
    while(q --) {
        int k, z;
        scanf("%d%d", &k, &z);
        int x = u[k], y = v[k];
        ll ans;
        if(!chk[k]) {
            ans = d[dst];
            ans = min(ans, min(d[x]+fd[y],d[y]+fd[x])+z);
        }
        else {
            ans = d[dst] + z - w[k];
            ans = min(ans, T.query(min(L[x], L[y])));
        }
        printf("%I64d\n", ans);
    }
}