#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

const int MAX_V = 1000050;
const int MAX_LOG_V = 20;
int root;
int n,k,a,b;

vector<int> G[MAX_V];

int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];
bool filled[MAX_V];

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

int find_last(int u){
    for(int k = MAX_LOG_V - 1; k >= 0; k--){
        if(parent[k][u] != -1 && !filled[parent[k][u]]){
            u = parent[k][u];
        }
    }
    return u;
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    root = n-1;
    init(n);
    int rem = n - k;
    for(int i = n-1; i >= 0; i--){
        int now = i, nxt = find_last(i);
        if(!filled[now]){
            if(depth[now] - depth[nxt] + 1 > rem) continue;
            rem -= (depth[now] - depth[nxt] + 1);
            filled[now] = true;
            while(now != nxt){now = parent[0][now]; filled[now] = true;}
        }
    }
    for(int i = 0; i < n-1; i++){
        if(!filled[i]) printf("%d ", i+1);
    }

}