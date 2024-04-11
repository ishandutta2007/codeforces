#include<bits/stdc++.h>
using namespace std;

#define N 100010

vector <int> adj[N], v;
bool vis[N][2];
int vi[N];

bool dfs(int x, int flag) {
    vis[x][flag] = 1;
    if(flag == 0 && adj[x].size() == 0) {
        v.push_back(x);
        return 1;
    }
    for(int i = 0; i < adj[x].size(); i ++) {
        int y = adj[x][i];
        if(!vis[y][flag^1]) {
            if(dfs(y, flag ^ 1)) {
                v.push_back(x);
                return 1;
            }
        }
    }
    return 0;
}

bool efs(int x) {
    vi[x] = 1;
    for(int i = 0; i < adj[x].size(); i ++) {
        int y = adj[x][i];
        if(vi[y] == 1) return 1;
        if(vi[y] == 0) if(efs(y)) return 1;
    }
    vi[x] = 2;
    return 0;
}

int main() {
    int n, m, s;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) {
        int x, y;
        scanf("%d", &x);
        while(x --) {
            scanf("%d", &y);
            adj[i].push_back(y);
        }
    }
    scanf("%d", &s);
    if(dfs(s, 1)) {
        puts("Win");
        for(int i = v.size() - 1; i >= 0; i --) printf("%d ", v[i]);
        puts("");
        return 0;
    }
    if(efs(s)) {
        puts("Draw");
        return 0;
    }
    puts("Lose");
}