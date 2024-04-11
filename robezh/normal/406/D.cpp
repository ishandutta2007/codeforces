#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const int MAX_V = 100050, N = (int)1e5 + 500;
const int MAX_LOG_V = 17;
int root = 0;
int n,m,a,b;
ll x[N], y[N];

struct pt{
    ll x, y;
    int id;
    pt(ll _x, ll _y, int _id){
        x = _x, y = _y, id = _id;
    }
};

vector<int> G[MAX_V];

int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    for(int i = 0; i < G[v].size(); i++){
        if(G[v][i] != p) dfs(G[v][i], v, d+1);
    }
}

void init(int V){
    dfs(root, -1, 0);

    for(int k = 0; k+1 < MAX_LOG_V; k++){
        for(int v = 0; v < V; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]){int tmp = u; u = v; v = tmp;}
    for(int k = 0; k < MAX_LOG_V; k++){
        if((depth[v] - depth[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    if(u == v) return u;
    for(int k = MAX_LOG_V - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

int min_dis(int u, int v){
    int ca = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[ca];
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%I64d%I64d", &x[i], &y[i]);

    stack<pt> S;
    S.push({x[n-1], y[n-1], n-1});
    for(int i = n-2; i >= 0; i--){
        while(true){
            if(S.size() == 1){
                int par = S.top().id;
                S.push({x[i], y[i], i});
                G[i].push_back(par);
                G[par].push_back(i);
                break;
            }
            else{
                pt p1 = S.top();
                S.pop();
                pt p2 = S.top();
                if((p1.y - y[i]) * (p2.x - p1.x) >= (p2.y - p1.y) * (p1.x - x[i])){
                    S.push(p1);
                    int par = S.top().id;
                    S.push({x[i], y[i], i});
                    G[i].push_back(par);
                    G[par].push_back(i);
                    break;
                }
            }
        }
    }

    root = n-1;
    init(n);

    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        printf("%d ", lca(a, b) + 1);
    }
}