#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int N = 100050, INF = (int)1e9;
const int LOG_N = 17;
int root = 0;
int n,m,a,b;

vector<int> G[N];
int parent[LOG_N][N], maxval[LOG_N][N];
int depth[N];
int in_dg[N];

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    for(int nxt : G[v]){
        if(nxt != p) dfs(nxt, v, d+1);
    }
}

void init(int V){
    for(int i = 0; i < V; i++){
        if(in_dg[i] == 0) dfs(i, -1, 0);
    }
    for(int k = 0; k+1 < LOG_N; k++){
        for(int v = 0; v < V; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else{
                int mid_par = parent[k][v];
                parent[k+1][v] = parent[k][mid_par];
                maxval[k+1][v] = max(maxval[k][v], maxval[k][mid_par]);
            }
        }
    }
}

int max_query(int u, int p){
    if(depth[u] < depth[p]) return INF;
    int res = -1;
    for(int k = 0; k < LOG_N; k++){
        if((depth[u] - depth[p]) >> k & 1){
            res = max(res, maxval[k][u]);
            u = parent[k][u];
        }
    }
    return u == p ? res : INF;
}

int pac[N], pac_time[N];
int p_cnt = 0;

struct query{
    int x, i;
};

vector<query> qry;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int t, a, b;
        scanf("%d", &t);
        if(t == 1){
            scanf("%d%d", &a, &b);
            a--, b--;
            G[b].push_back(a);
            in_dg[a] ++;
            maxval[0][a] = i;
        }
        else if(t == 2){
            scanf("%d", &a);
            pac_time[p_cnt] = i;
            pac[p_cnt++] = a-1;
        }
        else{
            scanf("%d%d", &a, &b);
            a--, b--;
            qry.push_back({a, b});
        }
    }
    init(n);
    for(auto q : qry){
        int em = pac[q.i], par = q.x, tim = pac_time[q.i];
        int link_time = max_query(em, par);
//        cout << "em = " << em + 1 << ", par = " << par + 1 << endl;
//        cout << link_time << ", " << tim << endl;
        printf(tim > link_time ? "YES\n" : "NO\n");
    }
}