#include <bits/stdc++.h>
using namespace std;

#define N 100200

int n, m, s;
vector <int> vec, adj[N];

int cnt, vis[N][2];
bool win, draw;

void dfs(int u, int k = 0) {
    cnt ++; vis[u][k] = 1;
    if (cnt > 1e6) {
        draw = 1;
        return;
    }
    if (adj[u].empty() && k == 1) {
        win = 1;
        vec.clear();
        vec.push_back(u);
        return;
    }
    for (auto v : adj[u]) {
        assert(!win);
        if (vis[v][k^1] == 1) draw = 1;
        if (!vis[v][k^1]) dfs(v, k ^ 1);
        if (win) {
            assert(vec.back() == v);
            vec.push_back(u);
            return;
        }
    }
    vis[u][k] = 2, cnt --;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        adj[i].resize(x);
        for (int j = 0; j < x; j ++) scanf("%d", &adj[i][j]);
    }
    scanf("%d", &s);
    dfs(s);
    if (win) {
        puts("Win"); assert(vec.size() % 2 == 0);
        for (int i = vec.size() - 1; i >= 0; i --) printf("%d ", vec[i]);
        puts("");
    }
    else puts(draw ? "Draw" : "Lose");
}