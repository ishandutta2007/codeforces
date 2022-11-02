#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define N 100010

vector <int> adj[N];
set <int> q[N], r[N];
int n, m, ans[N];

void dfs(int x, int p = 0) {
    for(auto y : adj[x]) {
        if(y == p) continue;
        for(auto z : q[y]) if(q[x].count(z)) ans[z] = INF;
        dfs(y, x);
    }
    set <int> s;
    for(auto y : adj[x]) {
        if(y == p) continue;
        if(r[x].size() < r[y].size()) swap(r[x], r[y]);
        for(auto z : r[y]) {
            if(q[x].count(z)) ans[z] ++;
            else if(r[x].count(z)) s.insert(z);
            else r[x].insert(z);
        }
        r[y].clear();
    }
    for(auto z : s) {
        r[x].erase(z);
        ans[z] ++;
    }
    for(auto z : q[x]) {
        if(r[x].count(z)) ans[z] ++;
        r[x].insert(z);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1, x, y; i < n; i ++) {
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    scanf("%d", &m);
    for(int i = 1, k, x; i <= m; i ++) {
        scanf("%d", &k);
        while(k --) {
            scanf("%d", &x);
            q[x].insert(i);
        }
    }
    dfs(1);
    for(int i = 1; i <= m; i ++) printf("%d\n", ans[i] < INF ? ans[i] : -1);
}