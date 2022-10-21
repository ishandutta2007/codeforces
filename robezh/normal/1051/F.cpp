#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, int> Pi;
typedef pair<ll, int> Pl;

const int N = 100050, LOG_N = 17;
const ll INF = (ll)1e18;
int root = 0;
int n,m,a,b,d,q;
int u[N];

vector<Pi> segs;
ll dist[45][N];
int dk = 0;

vector<P> G[N], Gv[N];
int parent[LOG_N][N];
ll depth[N];

int find(int i){return u[i] == i ? i : u[i] = find(u[i]);}
void unite(int i, int j){i = find(i), j = find(j), u[i] = j; }

void dfs_dis(int v, int i){
    fill(dist[i], dist[i]+N, INF);
    dist[i][v] = 0;
    priority_queue<Pl, vector<Pl>, greater<Pl> > pque;
    pque.push({0, v});

    while(!pque.empty()){
        auto p = pque.top(); pque.pop();
        int u = p.second;
        ll cur_dist = p.first;
        if(cur_dist > dist[i][u]) continue;

        for(P e : Gv[u]){
            if(e.second + dist[i][u] < dist[i][e.first]){
                dist[i][e.first] = e.second + dist[i][u];
                pque.push({dist[i][e.first], e.first});
            }
        }
    }
}

void dfs(int v, int p, int d, ll d_s){
    parent[0][v] = p;
    depth[v] = d;
    dist[dk][v] = d_s;
    for(auto e : G[v]){
        if(e.first != p) dfs(e.first, v, d + 1, d_s + e.second);
    }
}

void init(int V){
    dfs(root, -1, 0, 0);

    for(int k = 0; k+1 < LOG_N; k++){
        for(int v = 0; v < V; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]){int tmp = u; u = v; v = tmp;}
    for(int k = 0; k < LOG_N; k++){
        if((depth[v] - depth[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    if(u == v) return u;
    for(int k = LOG_N - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

ll min_dis(int u, int v){
    //assert(u >= 0 && v >= 0);
    int ca = lca(u, v);
    return dist[dk][u] + dist[dk][v] - 2 * dist[dk][ca];
}


int main(){
    for(int i = 0; i < N; i++) u[i] = i;

    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &d);
        a--, b--;
        if(find(a) == find(b)) segs.push_back({{a, b}, d});
        else{
            G[a].push_back({b, d});
            G[b].push_back({a, d});
            unite(a, b);
        }
        Gv[a].push_back({b, d});
        Gv[b].push_back({a, d});
    }
    dk = 2 * segs.size();
    init(n);

    for(int i = 0; i < segs.size(); i++){
        dfs_dis(segs[i].first.first, i * 2);
        dfs_dis(segs[i].first.second, i * 2 + 1);
    }


    scanf("%d", &q);
    while(q--){
        scanf("%d%d", &a, &b);
        a--, b--;
        ll ans = min_dis(a, b);
        for(int i = 0; i < segs.size(); i++){
            ans = min(ans, segs[i].second + dist[i*2][a] + dist[i*2+1][b]);
            ans = min(ans, segs[i].second + dist[i*2+1][a] + dist[i*2][b]);
        }
        printf("%I64d\n", ans);
    }

}