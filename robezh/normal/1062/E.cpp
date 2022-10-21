#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = (int)1e9;

struct P{
    int first, second;
    P(){};
    P(int a, int b){first = a, second = b;}

};

P min(P a, P b, int type){
    return ((a.first < b.first) ^ type) ? a : b;
}

int get(int a, int b, int type){
    return ((a < b) ^ type) ? a : b;
}

const int N = 100050;
const int LOG_N = 17;
int root = 0;
int n,q,a,b;
int mm[N];
int st[2][LOG_N][N];
int loc[2][N], id[2][N];
int tim[2] = {0, 0};

vector<int> G[N];
int parent[LOG_N][N];
int depth[N], par[N];

void dfs(int v, int p, int d){
    id[0][tim[0]] = v;
    loc[0][v] = tim[0]++;
    parent[0][v] = p;
    depth[v] = d;
    for(int nxt : G[v]){
        if(nxt != p) dfs(nxt, v, d+1);
    }
    id[1][tim[1]] = v;
    loc[1][v] = tim[1]++;
}

void init(int V){
    dfs(root, -1, 0);

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

void init_rmq(){
    for(int k = 0; k < 2; k++){
        for(int i = 0; i < n; i++){
            st[k][0][i]= loc[k][i];
        }
        for(int lg = 1; lg < LOG_N; lg++){
            for(int j = 0; j + (1 << lg) - 1 < n; j++){
                st[k][lg][j] = get(st[k][lg-1][j], st[k][lg-1][j+(1<<(lg-1))], k);
            }
        }
    }

}

int rmq(int l, int r, int type){
    if(l > r) return type == 0 ? INF : -INF;
    int k = mm[r - l + 1];
    return get(st[type][k][l], st[type][k][r-(1<<k)+1], type) ;
}

P get_del(int l, int r, int del){
    int left = min(rmq(l, del-1, 0), rmq(del+1, r, 0));
    int right = max(rmq(l, del-1, 1), rmq(del+1, r, 1));

    int ca = lca(id[0][left], id[1][right]);
    return P(depth[ca], del);
}

P get_res(int l, int r){
    int mn = rmq(l, r, 0);
    mn = id[0][mn];
    P mn_res = get_del(l, r, mn);

    int mx = rmq(l, r, 1);
    mx = id[1][mx];
    P mx_res = get_del(l, r, mx);

    return min(mn_res, mx_res, 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    mm[0]=-1;
    for(int i = 1; i < N; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];


    cin >> n >> q;
    for(int i = 1; i < n; i++){
        cin >> a;
        a--;
        G[a].push_back(i);
    }
    init(n);
    init_rmq();

    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        auto res = get_res(l, r);
        cout << res.second + 1 << " " << res.first << endl;
    }

}