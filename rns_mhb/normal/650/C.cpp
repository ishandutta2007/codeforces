#include<bits/stdc++.h>
using namespace std;

#define N 1000010

int a[N], n, m, nm;

void print() {
    int i, j;
    for(i = 0; i < n; i ++) {
        for(j = 0; j < m; j ++) printf("%d ", a[i * m + j]);
        puts("");
    }
}

deque <int> q;
vector <int> adj[N];
bool vis[N];

void dfs(int u) {
    vis[u] = 1;
    int i, v;
    for(i = 0; i < adj[u].size(); i ++) {
        v = adj[u][i];
        if(!vis[v]) dfs(v);
    }
    q.push_front(u);
}

vector <int> jda[N];

void trans() {
    int i, j;
    for(i = 0; i < nm; i ++) {
        for(j = 0; j < adj[i].size(); j ++) jda[adj[i][j]].push_back(i);
        adj[i].clear();
    }
}

vector <int> sccv[N];
int sccn, b[N];

void DFS(int u) {
    sccv[sccn].push_back(u);
    b[u] = sccn;
    vis[u] = 1;
    int i, v;
    for(i = 0; i < jda[u].size(); i ++) {
        v = jda[u][i];
        if(!vis[v]) DFS(v);
    }
}

void SCC() {
    int i;
    for(i = 0; i < nm; i ++) if(!vis[i]) dfs(i);
    trans();
    memset(vis, 0, sizeof vis);
    for(i = 0; i < nm; i ++) if(!vis[q[i]]) DFS(q[i]), sccn ++;
}

bool cmp(int i, int j) {return a[i] < a[j];}

void make_graph() {
    int i, j;
    for(i = 0; i < n; i ++) {
        for(j = 0; j < m; j ++) b[j] = i * m + j;
        sort(b, b + m, cmp);
        for(j = 1; j < m; j ++) {
            adj[b[j]].push_back(b[j - 1]);
            if(a[b[j]] == a[b[j - 1]]) adj[b[j - 1]].push_back(b[j]);
        }
    }
    for(i = 0; i < m; i ++) {
        for(j = 0; j < n; j ++) b[j] = j * m + i;
        sort(b, b + n, cmp);
        for(j = 1; j < n; j ++) {
            adj[b[j]].push_back(b[j - 1]);
            if(a[b[j]] == a[b[j - 1]]) adj[b[j - 1]].push_back(b[j]);
        }
    }
}

void solve_dfs(int u) {
    vis[u] = 1;
    b[u] = 1;
    int i, v;
    for(i = 0; i < adj[u].size(); i ++) {
        v = adj[u][i];
        if(v == u) continue;
        if(!vis[v]) solve_dfs(v);
        b[u] = max(b[u], b[v] + 1);
    }
}

void solve() {
    int i, j, v;
    make_graph();
    SCC();
    for(i = 0; i < nm; i ++) for(j = 0; j < jda[i].size(); j ++) {
        v = jda[i][j];
        adj[b[v]].push_back(b[i]);
    }
    for(i = 0; i < sccn; i ++) vis[i] = 0;
    for(i = 0; i < sccn; i ++) if(!vis[i]) solve_dfs(i);
    for(i = 0; i < sccn; i ++) for(j = 0; j < sccv[i].size(); j ++) a[sccv[i][j]] = b[i];
    print();
}

int main() {
    int i;
    scanf("%d%d", &n, &m);
    nm = n * m;
    for(i = 0; i < nm; i ++) scanf("%d", a + i);
    solve();
}