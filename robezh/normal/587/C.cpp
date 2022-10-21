#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int N = 100050, INF = (int)1e9;
const int K = 10;
const int LOG_N = 17;
int root = 0;
int n,m,q;

struct pset {
    const static int tr = 10;
    int S[K];
    int sz = 0;

    void insert(int v) {
        auto it = lower_bound(S, S + sz, v);
        if(it != S + sz && *it == v) return ;
        if(sz == tr && v < S[sz-1]) sz--;
        if(sz < tr) S[sz++] = v;
        for(int i = sz - 1; i >= 1; i--) if(S[i] < S[i-1]) swap(S[i], S[i-1]);
    }


    void merge(pset &ps) {
        int a[N], asz = 0;
        int cur = 0;
        for(int i = 0; i < sz && asz < K; i++) {
            while(cur < ps.sz && ps.S[cur] <= S[i] && asz < K) a[asz++] = ps.S[cur++];
            if(asz < K) a[asz++] = S[i];
        }
        while(cur < ps.sz && asz < K) a[asz++] = ps.S[cur++];
        for(int i = 0; i < asz; i++) S[i] = a[i];
        sz = asz;
    }
};

void print_out(pset &ps) {
    for(int i = 0; i < ps.sz; i++) cout << ps.S[i] << " ";
    cout << endl;
}

vector<int> G[N];
vector<int> live[N];
pset S[LOG_N][N];
int parent[LOG_N][N];
int depth[N], par[N];

void dfs(int v, int p, int d){
    parent[0][v] = p;
    S[0][v] = {{}, 0};
    for(int lv : live[v]) {
        S[0][v].insert(lv);
    }
    depth[v] = d;
    for(int nxt : G[v]){
        if(nxt != p) dfs(nxt, v, d+1);
    }
}

void init(int V){
    dfs(root, -1, 0);

    for(int k = 0; k+1 < LOG_N; k++){
        for(int v = 0; v < V; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else {
                parent[k+1][v] = parent[k][parent[k][v]];
                S[k+1][v] = S[k][v];
                pset &ps = S[k][parent[k][v]];
                S[k+1][v].merge(ps);
            }
        }
    }
}

pset lca(int u, int v){
    pset res = {{}, 0};
    if(depth[u] > depth[v]){int tmp = u; u = v; v = tmp;}
    for(int k = 0; k < LOG_N; k++){
        if((depth[v] - depth[u]) >> k & 1){
            res.merge(S[k][v]);
            v = parent[k][v];
        }
    }
    if(u == v) {
        res.merge(S[0][v]);
        return res;
    }
    for(int k = LOG_N - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            res.merge(S[k][u]);
            u = parent[k][u];
            res.merge(S[k][v]);
            v = parent[k][v];
        }
    }
    res.merge(S[0][u]);
    res.merge(S[0][v]);
    res.merge(S[0][parent[0][u]]);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    for(int i = 0; i < m; i++) {
        int a; cin >> a; a--;
        live[a].push_back(i);
    }
    init(n);
    while(q--) {
        int u, v, a;
        cin >> u >> v >> a; u--, v--;
        pset ps = lca(u, v);
        int k = min(a, ps.sz);
        cout << k << " ";
        for(int i = 0; i < k; i++) cout << ps.S[i] + 1 << " ";
        cout << "\n";
    }
}